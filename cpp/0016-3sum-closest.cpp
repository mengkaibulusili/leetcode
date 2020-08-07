#include <limits.h>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution
{
public:
  int threeSumClosest(vector<int> &nums, int target)
  {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int best = 1e7;

    // 根据差值的绝对值来更新答案
    // [] 生成闭包时，捕获外层的元素
    // []什么也不捕获，  [x] 捕获x的值，  [&x] 捕获x的引用
    // [=] 以值拷贝方式 捕获所有的 值，
    // [&] 以引用方式捕获，所有变量
    // 不捕获: 无法使用外层的值
    // 值捕获： 可以使用外层的值 ,修改对外层无效
    // 引用捕获: 可以 使用 修改 外层的值
    auto update = [&](int cur) {
      if (abs(cur - target) < abs(best - target))
      {
        best = cur;
      }
    };

    // 枚举 a
    for (int i = 0; i < n; ++i)
    {
      // 保证和上一次枚举的元素不相等
      if (i > 0 && nums[i] == nums[i - 1])
      {
        continue;
      }
      // 使用双指针枚举 b 和 c
      int j = i + 1, k = n - 1;
      while (j < k)
      {
        int sum = nums[i] + nums[j] + nums[k];
        // 如果和为 target 直接返回答案
        if (sum == target)
        {
          return target;
        }
        update(sum);
        if (sum > target)
        {
          // 如果和大于 target，移动 c 对应的指针
          int k0 = k - 1;
          // 移动到下一个不相等的元素
          while (j < k0 && nums[k0] == nums[k])
          {
            --k0;
          }
          k = k0;
        }
        else
        {
          // 如果和小于 target，移动 b 对应的指针
          int j0 = j + 1;
          // 移动到下一个不相等的元素
          while (j0 < k && nums[j0] == nums[j])
          {
            ++j0;
          }
          j = j0;
        }
      }
    }
    return best;
  }

  int threeSumClosest2(vector<int> &nums, int target)
  {
    sort(nums.begin(), nums.end());
    int res = INT_MAX;
    int n = nums.size();

    auto update = [&](int x) {
      if (abs(x - target) < abs(res - target))
      {
        res = x;
      }
    };

    for (int i = 0; i < n; i++)
    {
      if (i > 0 && nums[i - 1] == nums[i])
        continue;

      int k = n - 1;
      int j = i + 1;
      while (j < k)
      {

        int sum = nums[i] + nums[j] + nums[k];

        update(sum);
        if (sum == target)
          return res;
        if (sum > target)
        {
          while (k > 1 && nums[k] == nums[k - 1])
          {
            k--;
          }
          k--;
        }
        else
        {
          while (j > n - 1 && nums[j] == nums[j + 1])
          {
            j++;
          }
          j++;
        }
      }
    }
    return res;
  }
};

int main()
{
  Solution solu;

  int target = 1;
  vector<int> nums = {-1, 2, 1, -4};
  cout << endl
       << solu.threeSumClosest2(nums, target) << endl;
}
