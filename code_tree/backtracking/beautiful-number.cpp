#include <iostream>

using namespace std;

int n, cnt;
int numCheck[10];

int rec(int num)
{
  if (num == 1)
  {
    // cnt++;
    return 1;
  }
  return rec(num - 1);
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  rec(n);

  return 0;
}