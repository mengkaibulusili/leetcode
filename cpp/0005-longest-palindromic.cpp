#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
  string longestPalindrome(string s)
  {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n));
    string ans;
    // sl 代表 子串长度减 1
    for (int sl = 0; sl < n; ++sl)
    {
      // i 代表 子串开始位置
      for (int i = 0; i + sl < n; ++i)
      {
        // j 代表子串结束位置
        int j = i + sl;
        if (sl == 0)
        {
          dp[i][j] = 1;
        }
        else if (sl == 1)
        {
          dp[i][j] = (s[i] == s[j]);
        }
        else
        {
          dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
        }
        if (dp[i][j] && sl + 1 > ans.size())
        {
          ans = s.substr(i, sl + 1);
        }
      }
    }
    return ans;
  }
};