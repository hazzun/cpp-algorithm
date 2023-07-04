#include <iostream>
using namespace std;

int queue[10000];
int head = 0, tail = 0;

void push(int x)
{
  queue[tail++] = x;
}

void pop()
{
  head++;
}

int main()
{

  ios::sync_with_stdio(0);
  cin.tie(0);
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
      push(k);
    }
    if (cmd == "pop")
    {
      if (head == tail)
        cout << "-1\n";
      else
      {
        cout << queue[head] << "\n";
        pop();
      }
    }
    if (cmd == "size")
      cout << tail - head << "\n";
    if (cmd == "empty")
    {
      if (head == tail)
        cout << "1\n";
      else
        cout << "0\n";
    }
    if (cmd == "front")
    {
      if (head == tail)
        cout << "-1\n";
      else
        cout << queue[head] << "\n";
    }
    if (cmd == "back")
    {
      if (head == tail)
        cout << "-1\n";
      else
        cout << queue[tail - 1] << "\n";
    }
  }
}