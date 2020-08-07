#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int strStr(string haystack, string needle)
  {
    int pos = -1;
    int hn = haystack.size();
    int nn = needle.size();
    // if (haystack == "")
    // {
    //   pos = 0;
    // }
    if (needle == "")
    {
      pos = 0;
    }

    for (int i = 0; i < hn; i++)
    {
      int flag = 0;
      for (int j = 0; j < nn; j++)
      {
        if ((i + j) < hn && haystack[i + j] == needle[j])
        {
        }
        else
        {
          break;
        }
        if (j == (nn - 1))
        {
          flag = 1;
        }
      }
      if (flag == 1)
      {
        return i;
        pos = i;
      }
    }
    return pos;
  }
};

int main()
{
  Solution solu;
  cout << solu.strStr("aaaaa", "bba") << endl;
  cout << solu.strStr("hello", "ll") << endl;
}