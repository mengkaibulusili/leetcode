#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
  int removeDuplicates(vector<int> &nums)
  {
    int n = nums.size();
    // 快慢指针
    int p2 = 0;
    if (n == 1)
    {
      return 1;
    }
    if (n > 0)
    {
      nums[p2] == nums[0];
      p2++;
    }
    for (int i = 0; i != n; i++)
    {
      if (i < (n - 1) && nums[i] != nums[i + 1])
      {
        nums[p2] = nums[i + 1];
        p2++;
      }
    }
    return p2;
  }
};

int main()
{
  vector<int> nums = {1, 1};
  Solution solu;

  int n = solu.removeDuplicates(nums);

  for (auto i = nums.begin(); i != nums.end(); i++)
  {
    cout << *i << " - ";
  }
  cout << endl;
  cout << n << endl;
}