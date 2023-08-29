#include <iostream>
#include <list>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;

  string c;
  cin >> c;

  list<char> l;

  for (int i = 0; i < n; i++)
    l.push_back(c[i]);

  list<char>::iterator t = l.end();
  // cout << *t;
  while (m--)
  {
    char command;
    cin >> command;
    if (command == 'L')
    {
      if (t != l.begin())
        t--;
    }
    else if (command == 'R')
    {
      if (t != l.end())
        t++;
    }
    else if (command == 'D')
    {
      if (t != l.end())
        t = l.erase(t);
    }
    else if (command == 'P')
    {
      char addChar;
      cin >> addChar;
      l.insert(t, addChar);
    }
  }

  for (auto i : l)
  {
    cout << i;
  }
}