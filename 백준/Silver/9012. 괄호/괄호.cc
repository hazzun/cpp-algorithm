#include <iostream>
#include <stack>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  while (n--)
  {
    string vps;
    cin >> vps;

    stack<char> S;

    bool check = true;

    for (auto i : vps)
    {
      if (i == '(')
        S.push(i);
      else if (i == ')')
      {
        if (!S.empty() && S.top() == '(')
          S.pop();
        else
        {
          check = false;
          break;
        }
      }
    }
    if (S.empty() && check)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}