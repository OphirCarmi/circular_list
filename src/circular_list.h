#ifndef CIRCULAR_LIST_H_
#define CIRCULAR_LIST_H_

#include <memory>
#include <mutex>

template <typename T>
struct Node {
  Node() {}
  T item;
  std::shared_ptr<Node<T>> next;
};

template <typename T>
class CircularList {
 public:
  void Insert(const T &item) {
    std::lock_guard<std::mutex> lock(m_);
    if (nullptr == root_) {
      root_ = std::make_shared<Node<T>>();
      root_->item = item;
      root_->next = root_;
      curr_ = root_;
      return;
    }
    std::shared_ptr<Node<T>> ptr = root_;
    for (;;) {
      if (ptr->item == item) break;
      if (ptr->next == root_) {
        ptr->next = std::make_shared<Node<T>>();
        ptr = ptr->next;
        ptr->item = item;
        ptr->next = root_;
        break;
      }
      ptr = ptr->next;
    }
  }

  bool Remove(const T &item) {
    std::lock_guard<std::mutex> lock(m_);
    if (nullptr == root_) 
      return false;
    std::shared_ptr<Node<T>> before = root_;
    std::shared_ptr<Node<T>> ptr = root_;
    for (;;) {
      if (ptr->item == item) {
        before->next = ptr->next;
        if (curr_ == ptr) curr_ = curr_->next;
        break;
      }
      before = ptr;
      ptr = ptr->next;
      if (root_ == ptr)
        return false;
    }
    return true;
  }

  void Clear() {
    std::lock_guard<std::mutex> lock(m_);
    root_ = nullptr;
    curr_ = nullptr;
  }

  bool Empty() const { return nullptr == root_; }

  size_t Size() const {
    if (nullptr == root_) return 0;
    std::shared_ptr<Node<T>> ptr = root_;
    size_t sz = 1;
    for (;; ++sz) {
      ptr = ptr->next;
      if (ptr == root_) break;
    }
    return sz;
  }

  void Next(T *out) {
    std::lock_guard<std::mutex> lock(m_);

    if (nullptr == root_)
      return;
    curr_ = curr_->next;
    *out = curr_->item;
  }

  int Index() const {
    if (nullptr == root_) return -1;
    std::shared_ptr<Node<T>> ptr = root_;
    if (ptr == curr_) return 0;
    int ind = 1;
    for (;; ++ind) {
      ptr = ptr->next;
      if (ptr == curr_) break;
    }
    return ind;
  }

 private:
  bool Find(const T &item) const {
    if (nullptr == root_) return false;
    std::shared_ptr<Node<T>> ptr = root_;
    for (;;) {
      if (ptr->item == item) {
        return true;
      }
      ptr = ptr->next;
      if (root_ == ptr) break;
    }
    return false;
  }

  std::shared_ptr<Node<T>> root_;
  std::shared_ptr<Node<T>> curr_;
  std::mutex m_;
};

#endif  // CIRCULAR_LIST_H_
