#include <iostream>

using namespace std;

int rec(int n)
{
  if (n == 1)
    return 0;
  if (n % 2 == 0)
    return rec(n / 2) + 1;
  else
    return rec(n * 3 + 1) + 1;
}

int main()
{
  int n;
  cin >> n;

  cout << rec(n);
}