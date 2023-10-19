#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool vis[50];
string tmp, flag;
int cnt;
vector<int> answer;

bool compareCheck(string a, string b)
{
  int compareNum = 0;
  for (int i = 0; i < a.size(); i++)
  {
    if (a[i] != b[i])
      compareNum++;
  }
  if (compareNum == 1)
    return true;
  else
    return false;
}

void rec(string tmp, string target, vector<string> words)
{
  if (tmp == target)
  {
    answer.push_back(cnt);
    return;
  }
  if (compareCheck(tmp, target))
  {
    cnt++;
    answer.push_back(cnt);
    return;
  }
  for (int i = 0; i < words.size(); i++)
  {
    if (!vis[i] && compareCheck(tmp, words[i]))
    {
      vis[i] = 1;
      cnt++;
      rec(words[i], target, words);
      vis[i] = 0;
      cnt--;
    }
  }
}

int solution(string begin, string target, vector<string> words)
{
  bool notInArr = false;
  for (auto i : words)
  {
    if (i == target)
      notInArr = true;
  }

  if (!notInArr)
    return 0;

  for (int i = 0; i < words.size(); i++)
  {
    if (compareCheck(begin, words[i]))
    {
      cnt++;
      vis[i] = 1;
      rec(words[i], target, words);
    }
    cnt = 0;
    for (int j = 0; j < words.size(); j++)
      vis[j] = 0;
  }

  int minNum = 100;
  if (answer.empty())
    return 0;
  for (int j = 0; j < answer.size(); j++)
    minNum = min(minNum, answer[j]);
  return minNum;
}