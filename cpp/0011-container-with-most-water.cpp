#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
  int maxArea(vector<int> &height)
  {
    int l = 0, r = height.size() - 1;
    int maxA = 0;
    while (l < r)
    {
      maxA = max(maxA, min(height[l], height[r]) * (r - l));
      height[l] >= height[r] ? r-- : l++;
    }
    return maxA;
  }
}; // namespace stdclass Solution

int main()
{
  Solution solu;
  vector<int> vi = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  cout << endl
       << solu.maxArea(vi) << endl;
}