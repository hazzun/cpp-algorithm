#include <iostream>

using namespace std;

int rec(int n)
{
  if (n < 10)
    return (n % 10) * (n % 10);
  return rec(n / 10) + (n % 10) * (n % 10);
}

int main()
{
  int n;
  cin >> n;
  cout << rec(n);
}