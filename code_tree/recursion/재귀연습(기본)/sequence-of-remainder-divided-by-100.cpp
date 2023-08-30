#include <iostream>

using namespace std;

int rec(int n)
{
  if (n == 1)
    return 2;
  if (n == 2)
    return 4;
  return rec(n - 1) * rec(n - 2) % 100;
}

int main()
{
  int n;
  cin >> n;
  cout << rec(n);
}