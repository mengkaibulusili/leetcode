#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;
class Solution
{
public:
  string intToRoman(int num)
  {
    vector<int> allVal = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    unordered_map<int, string> iToS = {
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"}};
    string res = "";
    while (num > 0)
    {
      for (int i = 0; i < allVal.size(); i++)
      {
        if (num >= allVal[i])
        {
          res += iToS[allVal[i]];
          num -= allVal[i];
          break;
        }
      }
    }
    return res;
  }

  int romanToInt(string s)
  {
    vector<string> allVal = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    unordered_map<string, int> sToi = {
        {"M", 1000},
        {"CM", 900},
        {"D", 500},
        {"CD", 400},
        {"C", 100},
        {"XC", 90},
        {"L", 50},
        {"XL", 40},
        {"X", 10},
        {"IX", 9},
        {"V", 5},
        {"IV", 4},
        {"I", 1}};
    int i = 0, sLen = s.size();
    int sum = 0;
    string temp = "";
    while (i < sLen)
    {
      if (i < (sLen - 1))
      {
        temp = s.substr(i, 2);
        if (sToi.count(temp) > 0)
        {
          sum += sToi[temp];
          i += 2;
          continue;
        }
      }
      temp = s.substr(i, 1);
      sum += sToi[temp];
      i++;
    }
    return sum;
  }

  string longestCommonPrefix(vector<string> &strs)
  {
    string res = "";
    // int vi=0,vLen=strs.size();
    int idx = 0;
    char tempC = ' ';
    if (strs.size() == 0)
    {
      return res;
    }
    while (1)

    {

      if (idx < strs[0].size())
      {
        tempC = strs[0][idx];
      }
      else
      {
        return res;
      }

      for (int vi = 1; vi < strs.size(); vi++)
      {
        if (idx < strs[vi].size())
        {
          if (strs[vi][idx] != tempC)
          {
            return res;
          }
        }
        else
        {
          return res;
        }
      }

      res += tempC;
      idx++;
    }

    return res;
  }
};

int main()
{
  Solution solu;
  // cout << endl
  //      << solu.intToRoman(20) << endl;

  // cout << endl
  //      << solu.romanToInt("XX") << endl;

  vector<string> sList = {"dog", "racecar", "car"};
  cout << endl
       << solu.longestCommonPrefix(sList) << endl;
}