#include <algorithm>
#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

class Solution
{
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
  {
    //得到两个 nums 的长度，当nums1 不是最短的时候，就进行交换
    int len1 = nums1.size();
    int len2 = nums2.size();
    int slen = len1 + len2;
    if (len1 > len2)
    {
      return findMedianSortedArrays(nums2, nums1);
    }

    // left right 分别代表 nums1 上的 二分查找的左右限
    int left = 0;
    int right = len1;
    // 两个中位数 ， media1 是较小的那个 ， media2 是较大的那个
    // 当数组为奇数的时候 只有 media1 会被用到 ，当 数组为 偶数 的时候 ，media = (media1+media2)/2.0
    int media1 = 0;
    int media2 = 0;
    // divider 分别是 nums1 nums2 的逼近中位线
    int divider1 = 0;
    int divider2 = 0;

    // 当二分查找 的 两个左右限还未收缩之前
    while (left <= right)
    {
      // 分割线1 取 左右限的平均值
      divider1 = (left + right) / 2;
      // 分割线2 取 总数一半+1 - 取分割线1 左侧元素
      divider2 = (slen + 1) / 2 - divider1;

      // 分割成立的条件: 两条分割线左侧的元素均小于分割线右侧的元素

      //分别得到 两条缝合线 左右的 一共4 个元素
      int nums1_s = (divider1 == 0000) ? INT_MIN : nums1[divider1 - 1];
      int nums1_l = (divider1 == len1) ? INT_MAX : nums1[divider1 - 0];
      int nums2_s = (divider2 == 0000) ? INT_MIN : nums2[divider2 - 1];
      int nums2_l = (divider2 == len2) ? INT_MAX : nums2[divider2 - 0];

      //如果第一条分割线左侧较小的元素 小于 分割线2右侧较大的元素，说明这个划分是成立的，
      // 两个 media 可以分别取值。
      // 但是划分并不一定是对的，继续尝试 右移分割线1 ，左移分割线2 是否成立
      if (nums1_s <= nums2_l)
      {
        media1 = max(nums1_s, nums2_s);
        media2 = min(nums1_l, nums2_l);
        left = divider1 + 1;
      }
      // 划分不成立, 左移分割线1 尝试使得 分割成立
      else
      {
        right = divider1 - 1;
      }
    }
    // 循环结束以后根据  两个数组的总长度， 返回中位数
    return slen % 2 == 1 ? media1 : (media1 + media2) / 2.0;
  }
};

int main()
{
  Solution a;
  vector<int> v1 = {1, 2, 3, 7, 7, 7, 8};
  vector<int> v2 = {1, 2, 3, 5, 7, 8};

  double x1 = a.findMedianSortedArrays(v1, v2);
  //end = 5;
  cout << x1 << endl;
}