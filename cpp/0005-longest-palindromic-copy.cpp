#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
  string longestPalindrome(string s)
  {
    string ans = "";
    int slen = s.size();
    vector<vector<bool>> dp(slen, vector<bool>(slen));
    for (int i = 0; i < slen; i++)
    {
      dp[i][i] = true;
      if (s[i] == s[i + 1])
      {
        dp[i][i + 1] = true;
      }
    }

    for (int sublen = 0; sublen < slen; sublen++)
    {
      for (int startIndex = 0; startIndex + sublen < slen; startIndex++)
      {
        int endIndex = startIndex + sublen;
        if (sublen > 1)
        {
          dp[startIndex][endIndex] = (s[startIndex] == s[endIndex]) && (dp[startIndex + 1][endIndex - 1]);
        }
        if (dp[startIndex][endIndex] && sublen + 1 > ans.size())
        {
          ans = s.substr(startIndex, sublen + 1);
        }
      }
    }
    return ans;
  }
};
