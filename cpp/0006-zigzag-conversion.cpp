#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
  string convert(string s, int numRows)
  {
    int sLen = s.size();
    string ans = "";
    int nowIdx = 0;
    // 第一行的间隔数
    int nextIdx0 = 0 == (numRows - 1) ? 1 : (2 * (numRows - 1));
    int tmpIndex = 0;
    int nextIdx1 = 0;
    int nextIdx2 = 0;
    bool isJ = true;
    for (int r = 0; r < numRows; r++)
    {

      nowIdx = r;
      tmpIndex = (nextIdx0 - r * 2);
      nextIdx1 = 0 != tmpIndex ? tmpIndex : nextIdx0;
      nextIdx2 = nextIdx0 - nextIdx1;
      isJ = true;
      while (1)
      {
        ans += s[nowIdx];
        nowIdx += (isJ || (0 == nextIdx2)) ? nextIdx1 : nextIdx2;
        isJ = !isJ;
        if (nowIdx >= sLen)
          break;
      }
    }
    return ans;
  }
};

int main()
{
  string s1 = "LEETCODEISHIRING";
  int r = 4;
  Solution solu;
  cout << endl
       << solu.convert(s1, r) << endl;
}