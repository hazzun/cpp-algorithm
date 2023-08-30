#include <iostream>

using namespace std;

int rec(long long n)
{
  if (n < 10)
    return n;
  return rec(n / 10) + n % 10;
}

int main()
{
  long long a, b, c;
  cin >> a >> b >> c;

  cout << rec(a * b * c);
}