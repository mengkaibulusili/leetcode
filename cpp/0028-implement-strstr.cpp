#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int strStr(string haystack, string needle)
  {
    if (needle == "")
      return 0;
    if (haystack == "")
      return -1;
    int hn = haystack.size();
    int nn = needle.size();
    for (int i = 0; i <= hn - nn; i++)
    {
      int j = 0;
      while (haystack[i + j] == needle[j] && j < nn)
      {
        j++;
      }
      if (j == nn)
      {
        return i;
      }
      return -1;
    }
  };

  int main()
  {
    Solution solu;
    cout << solu.strStr("aaaaa", "bba") << endl;
    cout << solu.strStr("hello", "ll") << endl;
  }