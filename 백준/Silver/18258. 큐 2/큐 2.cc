#include <iostream>
#include <queue>
using namespace std;

/*
push X: 정수 X를 큐에 넣는 연산이다.
pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 큐에 들어있는 정수의 개수를 출력한다.
empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
*/

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