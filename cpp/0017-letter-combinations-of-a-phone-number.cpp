
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <limits.h>

using namespace std;

class Solution
{
public:
  vector<string> letterCombinations(string digits)
  {
    vector<string> x = {};
    unordered_map<char, vector<char>> m = {
        {
            '2',
            {'a', 'b', 'c'},
        },
        {
            '3',
            {'d', 'e', 'f'},
        },
        {
            '4',
            {'g', 'h', 'l'},
        },
        {
            '5',
            {'j', 'k', 'l'},
        },
        {
            '6',
            {'m', 'n', 'o'},
        },
        {
            '7',
            {'p', 'q', 'r', 's'},
        },
        {
            '8',
            {'t', 'u', 'v'},
        },
        {
            '9',
            {'w', 'x', 'y', 'z'},
        }};
    string d = digits;
    int n = d.size();
    unordered_set<string> last = {""};
    unordered_set<string> now = {};

    for (int i = 0; i < n; i++)
    {

      now.clear();
      int n2 = m[d[i]].size();
      for (int j = 0; j < n2; j++)
      {
        int n3 = last.size();
        for (auto k = last.begin(); k != last.end(); k++)
        {
          string temp = *k + m[d[i]][j];
          if (i == n - 1)
          {
            x.push_back(temp);
          }
          else
          {
            now.insert(temp);
          }
        }
      }
      last = now;
    }
    return x;
  }
};

int main()
{
  Solution solu;
  auto l = solu.letterCombinations("23");
  for (auto x = l.begin(); x != l.end(); x++)
  {
    cout << endl
         << *x << endl;
  }
}