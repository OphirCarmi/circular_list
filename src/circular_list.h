#ifndef CIRCULAR_LIST_H_
#define CIRCULAR_LIST_H_

#include <iostream>
#include <memory>
#include <mutex>

template <typename T>
class CircularList {
 public:
  void Insert(const T &item) {
    std::lock_guard<std::mutex> lock(m_);
    if (nullptr == root_) {
      root_ = std::make_shared<Node>();
      root_->item = item;
      root_->next = root_;
      curr_ = root_;
      return;
    }
    for (std::shared_ptr<Node> ptr = root_; ptr->item != item; ptr = ptr->next) {
      if (ptr->next == root_) {
        ptr->next = std::make_shared<Node>();
        ptr = ptr->next;
        ptr->item = item;
        ptr->next = root_;
        break;
      }
    }
  }

  bool Remove(const T &item) {
    std::lock_guard<std::mutex> lock(m_);
    if (nullptr == root_) return false;
    std::shared_ptr<Node> before = root_;
    for (;;) {
      if (before->next == root_) break;
      before = before->next;
    }
    for (std::shared_ptr<Node> ptr = root_;; ptr = ptr->next, before = before->next) {
      if (ptr->item == item) {
        if (curr_ == ptr) curr_ = curr_->next;
        if (root_ == ptr) root_ = root_->next;
        before->next = ptr->next;
        return true;
      }
      if (root_ == ptr->next) return false;
    }
  }

  void Clear() {
    std::lock_guard<std::mutex> lock(m_);
    root_ = nullptr;
    curr_ = nullptr;
  }

  bool Empty() const { return nullptr == root_; }

  size_t Size() const {
    if (nullptr == root_) return 0;
    std::shared_ptr<Node> ptr = root_->next;
    size_t sz = 1;
    for (; ptr != root_; ptr = ptr->next, ++sz) {
    }
    return sz;
  }

  void Next(T *out) {
    std::lock_guard<std::mutex> lock(m_);

    if (nullptr == root_) return;
    curr_ = curr_->next;
    *out = curr_->item;
  }

  int Index() const {
    if (nullptr == root_) return -1;
    std::shared_ptr<Node> ptr = root_;
    if (ptr == curr_) return 0;
    for (int ind = 1;; ++ind) {
      ptr = ptr->next;
      if (ptr == curr_) return ind;
    }
  }

  void Print() const {
    if (nullptr == root_) return;
    std::cout << "List elements:" << std::endl;
    for (std::shared_ptr<Node> ptr = root_;; ptr = ptr->next) {
      std::cout << ptr->item << std::endl;
      if (ptr->next == root_) break;
    }
  }

  bool Find(const T &item) const {
    if (nullptr == root_) return false;
    for (std::shared_ptr<Node> ptr = root_;;) {
      if (ptr->item == item) {
        return true;
      }
      ptr = ptr->next;
      if (root_ == ptr) return false;
    }
  }

 private:
  struct Node {
    Node() {}
    T item;
    std::shared_ptr<Node> next;
  };

  std::shared_ptr<Node> root_;
  std::shared_ptr<Node> curr_;
  std::mutex m_;
};

#endif  // CIRCULAR_LIST_H_
