#include <limits.h>
#include <string>
using namespace std;

class Solution
{
public:
  int myAtoi(string str)
  {
    int sLen = str.size();
    int idx = 0;
    int ans = 0;
    int sign = 0;
    int flag = 0;
    while (idx < sLen)
    {
      if (0 == flag)
      {
        if (str[idx] == ' ')
        {
        }
        else if (str[idx] == '+')
        {
          sign = 1;
          flag = 1;
        }
        else if (str[idx] == '-')
        {
          sign = -1;
          flag = 1;
        }
        else if (str[idx] >= '0' && str[idx] <= '9')
        {
          sign = 1;
          ans = ans * 10 + (str[idx] - '0');
          flag = 1;
        }
        else
        {
          return 0;
        }
      }
      else if (1 == flag)
      {
        if (str[idx] >= '0' && str[idx] <= '9')
        {
          if (ans > INT_MAX / 10 || (INT_MAX / 10 == ans && (str[idx] - '0') > INT_MAX % 10))
          {
            return INT_MAX;
          }
          else if (ans < INT_MIN / 10 || (INT_MIN / 10 == ans && (str[idx] - '0') > (-1 * (INT_MIN % 10))))
          {
            return INT_MIN;
          }
          ans = ans * 10 + sign * (str[idx] - '0');
          flag = 1;
        }
        else
        {
          return ans;
        }
      }
      idx++;
    }
    return ans;
  }
};