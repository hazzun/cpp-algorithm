#include <iostream>
#include <vector>

using namespace std;

string solution(string s)
{
  string answer = "";
  bool flag = true;
  for (int i = 0; i < s.size(); i++)
  {
    // 첫번째 문자
    if (i == 0)
    {
      if ('a' <= s[i] && s[i] <= 'z')
        s[i] += ('A' - 'a');
    }
    // 두번째 이후 문자
    else
    {
      if (s[i] == ' ')
      {
        flag = false;
        answer.push_back(s[i]);
        continue;
      }
      // 공백 다음에 나온 문자
      if (!flag)
      {
        if ('a' <= s[i] && s[i] <= 'z')
          s[i] += ('A' - 'a');
        flag = true;
      }
      // 기존 문자 비교
      else
      {
        if ('A' <= s[i] && s[i] <= 'Z')
          s[i] -= ('A' - 'a');
      }
    }
    answer.push_back(s[i]);
  }
  return answer;
}