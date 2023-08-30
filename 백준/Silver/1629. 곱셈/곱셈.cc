#include <iostream>

using namespace std;
using ll = long long;

ll recursionMod(ll a, ll b, ll m)
{
  if (b == 1)
    return a % m;
  ll tmp = recursionMod(a, b / 2, m);
  if (b % 2 == 0)
    return tmp * tmp % m;
  else
    return tmp * tmp % m * a % m;
}

int main(void)
{
  ll a, b, m;
  cin >> a >> b >> m;

  cout << recursionMod(a, b, m);
  return 0;
}