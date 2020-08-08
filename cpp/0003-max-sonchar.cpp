#include <algorithm>
#include <iostream>
#include <unordered_set>
using namespace std;
int lengthOfLongestSubstring(string s)
{
  unordered_set<char> existChar;
  int maxSublen = 0;
  int rp = 0;
  int slen = s.length();
  for (int lp = 0; lp < slen; lp++)
  {
    while (rp < slen && existChar.count(s[rp]) == 0)
    {
      existChar.insert(s[rp]);
      rp++;
    }
    maxSublen = max(rp - lp, maxSublen);

    existChar.erase(s[lp]);
  }
  return maxSublen;
}

int main()
{
  string a = "1234123zxzcxcvxcxc2132";
  cout << lengthOfLongestSubstring(a) << endl;
}