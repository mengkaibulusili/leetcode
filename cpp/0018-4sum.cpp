#include <algorithm>
#include <vector>

using namespace std;
class Solution
{
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target)
  {
    sort(nums.begin(), nums.end());
    vector<vector<int>> x = {};
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      for (int j = i + 1; j < n; j++)
      {
        if (j > i + 1 && nums[j] == nums[j - 1])
          continue;
      }
    }
    return x;
  }
}

