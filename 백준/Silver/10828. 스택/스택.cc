#include <iostream>
#include <stack>

using namespace std;

// push X: 정수 X를 스택에 넣는 연산이다.
// pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
// size: 스택에 들어있는 정수의 개수를 출력한다.
// empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
// top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.

int main()
{
  stack<int> S;
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  while (n--)
  {
    string cmd;
    int num;
    cin >> cmd;
    if (cmd == "push")
    {
      cin >> num;
      S.push(num);
    }
    else if (cmd == "pop")
    {
      if (S.empty())
        cout << "-1" << '\n';
      else
      {
        cout << S.top() << '\n';
        S.pop();
      }
    }
    else if (cmd == "size")
    {
      cout << S.size() << '\n';
    }
    else if (cmd == "empty")
    {
      if (S.empty())
        cout << "1" << '\n';
      else
        cout << "0" << '\n';
    }
    else if (cmd == "top")
    {
      if (S.empty())
        cout << "-1" << '\n';
      else
        cout << S.top() << '\n';
    }
  }
}
