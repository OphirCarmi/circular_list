#include <fstream>

#include "src/circular_list.h"
#include "tests/3rdparty/googletest/googletest/include/gtest/gtest.h"

TEST(circular_list, All) {
    CircularList<int> list;

  EXPECT_TRUE(list.Empty());
  EXPECT_EQ(list.Size(), static_cast<size_t>(0));
  EXPECT_FALSE(list.Remove(2));
  EXPECT_EQ(list.Index(), -1);
  list.Insert(3);
  EXPECT_FALSE(list.Empty());
  EXPECT_EQ(list.Size(), static_cast<size_t>(1));
  EXPECT_EQ(list.Index(), 0);
  list.Insert(3);
  EXPECT_FALSE(list.Empty());
  EXPECT_EQ(list.Size(), static_cast<size_t>(1));
  EXPECT_EQ(list.Index(), 0);
  list.Clear();
  EXPECT_TRUE(list.Empty());
  EXPECT_EQ(list.Size(), static_cast<size_t>(0));
  EXPECT_EQ(list.Index(), -1);
  int item = -1;
  list.Next(&item);
  EXPECT_EQ(item, -1);
  list.Insert(3);
  EXPECT_FALSE(list.Empty());
  EXPECT_EQ(list.Size(), static_cast<size_t>(1));
  EXPECT_EQ(list.Index(), 0);
  list.Next(&item);
  EXPECT_EQ(item, 3);
  list.Next(&item);
  EXPECT_EQ(item, 3);
  list.Insert(3);
  EXPECT_FALSE(list.Empty());
  EXPECT_EQ(list.Size(), static_cast<size_t>(1));
  EXPECT_EQ(list.Index(), 0);
  list.Next(&item);
  EXPECT_EQ(item, 3);
  list.Next(&item);
  EXPECT_EQ(item, 3);
  list.Insert(2);
  EXPECT_FALSE(list.Empty());
  EXPECT_EQ(list.Size(), static_cast<size_t>(2));
  EXPECT_EQ(list.Index(), 0);
  list.Next(&item);
  EXPECT_EQ(list.Index(), 1);
  EXPECT_EQ(item, 2);
  list.Next(&item);
  EXPECT_EQ(list.Index(), 0);
  EXPECT_EQ(item, 3);
  list.Next(&item);
  EXPECT_EQ(list.Index(), 1);
  EXPECT_EQ(item, 2);
//   list.Next(&item);
//   EXPECT_EQ(list.Index(), 0);
//   EXPECT_EQ(pt.x, 2);
//   list.Insert(3, 4);
//   EXPECT_FALSE(list.Empty());
//   EXPECT_EQ(list.Size(), static_cast<size_t>(3));
//   EXPECT_EQ(list.Index(), 0);
//   list.Next(&item);
//   EXPECT_EQ(list.Index(), 1);
//   EXPECT_EQ(pt.x, 2);
//   list.Next(&item);
//   EXPECT_EQ(list.Index(), 2);
//   EXPECT_EQ(pt.x, 3);
//   list.Insert(13, 14);
//   EXPECT_FALSE(list.Empty());
//   EXPECT_EQ(list.Size(), static_cast<size_t>(4));
//   EXPECT_EQ(list.Index(), 2);
//   list.Next(&item);
//   EXPECT_EQ(list.Index(), 3);
//   EXPECT_EQ(pt.x, 13);
//   list.Next(&item);
//   EXPECT_EQ(list.Index(), 0);
//   EXPECT_EQ(pt.x, 2);
//   list.Next(&item);
//   EXPECT_EQ(list.Index(), 1);
//   EXPECT_EQ(pt.x, 2);
//   list.Insert(13, 14);
//   EXPECT_FALSE(list.Empty());
//   EXPECT_EQ(list.Size(), static_cast<size_t>(4));
//   EXPECT_EQ(list.Index(), 1);
//   list.Insert(3, 4);
//   EXPECT_FALSE(list.Empty());
//   EXPECT_EQ(list.Size(), static_cast<size_t>(4));
//   EXPECT_EQ(list.Index(), 1);
//   list.Insert(2, 4);
//   EXPECT_FALSE(list.Empty());
//   EXPECT_EQ(list.Size(), static_cast<size_t>(4));
//   EXPECT_EQ(list.Index(), 1);
//   list.Insert(2, 3);
//   EXPECT_FALSE(list.Empty());
//   EXPECT_EQ(list.Size(), static_cast<size_t>(4));
//   EXPECT_EQ(list.Index(), 1);
//   LostLandingPoint(2, 4);
//   EXPECT_FALSE(list.Empty());
//   EXPECT_EQ(list.Size(), static_cast<size_t>(3));
//   EXPECT_EQ(list.Index(), 1);
//   list.Next(&item);
//   EXPECT_EQ(list.Index(), 2);
//   EXPECT_EQ(pt.x, 13);
//   list.Next(&item);
//   EXPECT_EQ(list.Index(), 0);
//   EXPECT_EQ(pt.x, 2);
//   list.Next(&item);
//   EXPECT_EQ(list.Index(), 1);
//   EXPECT_EQ(pt.x, 3);
//   LostLandingPoint(3, 4);
//   EXPECT_FALSE(list.Empty());
//   EXPECT_EQ(list.Size(), static_cast<size_t>(2));
//   EXPECT_EQ(list.Index(), 1);
//   list.Next(&item);
//   EXPECT_EQ(list.Index(), 0);
//   EXPECT_EQ(pt.x, 2);
//   list.Next(&item);
//   EXPECT_EQ(list.Index(), 1);
//   EXPECT_EQ(pt.x, 13);
//   LostLandingPoint(13, 14);
//   EXPECT_FALSE(list.Empty());
//   EXPECT_EQ(list.Size(), static_cast<size_t>(1));
//   EXPECT_EQ(list.Index(), 0);
//   list.Next(&item);
//   EXPECT_EQ(list.Index(), 0);
//   EXPECT_EQ(pt.x, 2);
//   list.Insert(13, 17);
//   EXPECT_FALSE(list.Empty());
//   EXPECT_EQ(list.Size(), static_cast<size_t>(2));
//   EXPECT_EQ(list.Index(), 0);
//   list.Insert(18, 17);
//   EXPECT_FALSE(list.Empty());
//   EXPECT_EQ(list.Size(), static_cast<size_t>(3));
//   EXPECT_EQ(list.Index(), 0);
//   list.Clear();
//   EXPECT_TRUE(list.Empty());
//   EXPECT_EQ(list.Size(), static_cast<size_t>(0));
//   EXPECT_EQ(list.Index(), -1);
}
