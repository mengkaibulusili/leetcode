#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
  bool isValid(string s)
  {
    stack<char> sc = {};
    int n = s.size();
    int i = 0;
    for (; i < n; i++)
    {
      if (s[i] == '(')
        sc.push('(');
      else if (s[i] == '[')
        sc.push('[');
      else if (s[i] == '{')
        sc.push('{');
      else if (s[i] == ')' && sc.size() && sc.top() == '(')
        sc.pop();
      else if (s[i] == ']' && sc.size() && sc.top() == '[')
        sc.pop();
      else if (s[i] == '}' && sc.size() && sc.top() == '{')
        sc.pop();
      else
        break;
    }
    // cout << "i:" << i << "  n:" << n << endl;
    return (i == n) && (0 == sc.size());
  }
};

int main()
{
  Solution solu;
  cout << solu.isValid("]");
}