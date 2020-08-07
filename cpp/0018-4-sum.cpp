#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  //为了减少算法复杂度 先求的 两数和， 再求的所有两数和的 四数和
  // { "x",{"a","b"}}
  // 先定义四个指针 ，
  vector<vector<int>> fourSum(vector<int> &nums, int target)
  {
    sort(nums.begin(), nums.end());
    vector<vector<int>> x = {};
    int n = nums.size();
    int i, j, k, l;
    for (i = 0; i < n; i++)
    {
      if (4 * nums[i] > target)
        break;
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      for (j = i + 1; j < n; j++)
      {
        if ((nums[i] + 3 * nums[j]) > target)
          break;
        if (j > i + 1 && nums[j] == nums[j - 1])
          continue;
        k = j + 1;
        l = n - 1;
        while (k < l)
        {
          int sum = nums[i] + nums[j] + nums[k] + nums[l];
          if (sum == target)
          {
            x.push_back({nums[i], nums[j], nums[k], nums[l]});
            k++;
            // break;
          }
          else if (sum > target)
          {
            l--;
          }
          else
          {
            k++;
          }
          while (l < n - 1 && l > k && nums[l] == nums[l + 1])
          {
            l--;
          }
          while (k > j + 1 && k < l && nums[k] == nums[k - 1])
          {
            k++;
          }
        }
      }
    }
    return x;
  }
};

int main()
{
  Solution solu;
  // vector<int> x = {-4, 0, -4, 2, 2, 2, -2, -2};
  // int target = 7;
  vector<int> x = {0, 0, 0, 0};
  int target = 0;
  auto res = solu.fourSum(x, target);
  // cout << "end";
  for (auto i = res.begin(); i != res.end(); i++)
  {
    for (auto j = (*i).begin(); j != (*i).end(); j++)
    {
      cout << *j;
    }
    cout << endl;
  }
}