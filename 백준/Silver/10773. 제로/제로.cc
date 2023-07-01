#include <iostream>
#include <stack>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  stack<int> S;
  int n;
  cin >> n;

  while (n--)
  {
    int k;
    cin >> k;
    if (k == 0)
      S.pop();
    else
      S.push(k);
  }
  int sum = 0;
  while (S.size() != 0)
  {
    sum += S.top();
    S.pop();
  }

  cout << sum;
}