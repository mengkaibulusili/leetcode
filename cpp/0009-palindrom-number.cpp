#include <iostream>
#include <limits.h>
using namespace std;
class Solution
{
public:
  bool isPalindrome(int x)
  {
    int y = x;
    int ans = 0;
    if (x < 0)
      return false;
    while (x != 0)
    {
      if (ans > INT_MAX / 10 || ((x % 10 > INT_MAX % 10) && ans == (INT_MAX / 10)))
      {
        return false;
      }
      ans = ans * 10 + x % 10;
      x = x / 10;
    }
    return ans == y;
  }
};

int main()
{
  Solution so;
  cout << endl
       << so.isPalindrome(1234321) << endl;
}