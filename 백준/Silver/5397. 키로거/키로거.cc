#include <iostream>
#include <list>
using namespace std;

// 알파벳 대문자, 소문자, 숫자, 백스페이스( - ), 화살표( <, > )
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  while (n--)
  {
    list<char> pwd;
    auto cursor = pwd.end();
    string test;
    cin >> test;
    for (auto i : test)
    {
      if (i == '<')
      {
        if (cursor != pwd.begin())
          cursor--;
      }
      else if (i == '>')
      {
        if (cursor != pwd.end())
          cursor++;
      }
      else if (i == '-')
      {
        if (cursor != pwd.begin())
          cursor = pwd.erase(--cursor);
      }
      else
        pwd.insert(cursor, i);
    }
    for (auto i : pwd)
      cout << i;
    cout << '\n';
  }
}