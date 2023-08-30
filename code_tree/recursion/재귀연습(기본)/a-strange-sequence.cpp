#include <iostream>
using namespace std;

int rec(int n)
{
  if (n == 1)
    return 1;
  if (n == 2)
    return 2;
  return rec(n / 3) + rec(n - 1);
}

int main()
{
  int n;
  cin >> n;
  cout << rec(n);
}