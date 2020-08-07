#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
  int removeElement(vector<int> &nums, int val)
  {
    // 慢指针
    int ps = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
      if (nums[i] != val)
      {
        nums[ps] = nums[i];
        ps++;
      }
    }
    return ps;
  }
};

int main()
{
  vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
  Solution solu;
  int n = solu.removeElement(nums, 2);
  cout << n << endl;
  for (int i = 0; i < n; i++)
  {
    cout << nums[i] << " --> ";
  }
  cout << endl;
}