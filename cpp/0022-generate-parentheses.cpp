#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;
class Solution
{
public:
  vector<string> generateParenthesis(int n)
  {
    vector<string> last = {""};
    vector<string> now = {};
    unordered_set<string> sets = {};
    while (n > 0)
    {
      for (auto i = last.begin(); i != last.end(); i++)
      {
        int slen = (*i).size();
        for (int j = 0; j < slen + 1; j++)
        {
          string temp = "";
          temp = (*i).substr(0, j) + "()";
          if (j < slen)
          {
            temp = (*i).substr(0, j) + "()" + (*i).substr(j, slen - j);
          }
          else
          {
            temp = (*i) + "()";
          }

          if (!sets.count(temp))
          {
            sets.insert(temp);
            now.push_back(temp);
          }
        }
      }
      last = now;
      n--;
      if (n == 0)
        return now;
      now = {};
    }
    return now;
  }
};

int main()
{
  Solution solu;
  auto r1 = solu.generateParenthesis(3);
  for (auto i = r1.begin(); i != r1.end(); i++)
  {
    cout << *i << endl;
  }
}