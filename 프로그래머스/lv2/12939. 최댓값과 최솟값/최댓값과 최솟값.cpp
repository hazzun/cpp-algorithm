#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int t;
vector<int> arr;

string solution(string s)
{
  string answer = "";
  bool flag = false;
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == ' ')
      continue;
    if (s[i] == '-')
    {
      flag = true;
      continue;
    }
    if (flag)
    {
      string tmp = "";
      while (s[i] != ' ')
        tmp += s[i++];
      arr.push_back((-1) * (stoi(tmp)));
      flag = false;
    }
    else
    {
      string tmp = "";
      while (s[i] != ' ')
        tmp += s[i++];
      arr.push_back(stoi(tmp));
    }
  }

  sort(arr.begin(), arr.end());

  answer += to_string(arr.front());
  answer += ' ';
  answer += to_string(arr.back());
  return answer;
}