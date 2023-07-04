#include <iostream>
#include <queue>
using namespace std;


int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  queue<int> Q;

  int n;
  cin >> n;
  while (n--)
  {
    string cmd;
    cin >> cmd;

    if (cmd == "push")
    {
      int k;
      cin >> k;
      Q.push(k);
    }
    if (cmd == "pop")
    {
      if (Q.empty())
        cout << "-1\n";
      else
      {
        cout << Q.front() << "\n";
        Q.pop();
      }
    }
    if (cmd == "size")
      cout << Q.size() << "\n";
    if (cmd == "empty")
      cout << Q.empty() << "\n";
    if (cmd == "front")
    {
      if (Q.empty())
        cout << "-1\n";
      else
        cout << Q.front() << "\n";
    }
    if (cmd == "back")
    {
      if (Q.empty())
        cout << "-1\n";
      else
        cout << Q.back() << "\n";
    }
  }
}