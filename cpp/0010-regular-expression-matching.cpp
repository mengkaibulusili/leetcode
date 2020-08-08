#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
  bool isMatch(string s, string p)
  {
    int m = s.size();
    int n = p.size();

    auto matches = [&](int i, int j) {
      if (i == 0)
      {
        return false;
      }
      if (p[j - 1] == '.')
      {
        return true;
      }
      return s[i - 1] == p[j - 1];
    };

    vector<vector<int>> f(m + 1, vector<int>(n + 1));
    f[0][0] = true;
    for (int i = 0; i <= m; ++i)
    {
      for (int j = 1; j <= n; ++j)
      {
        if (p[j - 1] == '*')
        {
          f[i][j] |= f[i][j - 2];
          if (matches(i, j - 1))
          {
            f[i][j] |= f[i - 1][j];
          }
        }
        else
        {
          if (matches(i, j))
          {
            f[i][j] |= f[i - 1][j - 1];
          }
        }
      }
    }
    return f[m][n];
  }


};

void rep()
{
  string str1("123456");
  string str;
  str.assign(str1); //直接赋值
  cout << str << endl;
  str.assign(str1, 1, 1); //赋值给子串
  cout << str << endl;
  str.assign(str1, 2, str1.npos); //赋值给从位置 2 至末尾的子串
  cout << str << endl;
  return;
}

int main()
{
  Solution solu;
  cout << solu.isMatch("aaa", "a*a") << endl;

  string a = "123";
  rep();
}