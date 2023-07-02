#include <iostream>
#include <stack>
#include <list>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  stack<int> S;
  list<string> list;
  bool answer = true;

  int n, tmp = 1;
  cin >> n;
  while (n--)
  {
    int input_num;
    cin >> input_num;

    if (tmp <= input_num)
    {
      for (int i = tmp; i <= input_num; i++)
      {
        S.push(i);
        list.push_back("+");
        tmp++;
      }
    }
    if (input_num == S.top())
    {
      S.pop();
      list.push_back("-");
    }
    if (!S.empty() && S.top() > input_num)
    {
      answer = false;
    }
  }
  if (!answer)
    cout << "NO" << "\n";
  else
  {
    while (!list.empty())
    {
      cout << list.front() << "\n";
      list.pop_front();
    }
  }
}