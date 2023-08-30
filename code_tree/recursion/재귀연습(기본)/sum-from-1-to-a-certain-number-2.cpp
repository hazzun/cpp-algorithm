#include <iostream>

using namespace std;

int recursion(int n)
{
  if (n == 1)
    return 1;

  return recursion(n - 1) + n;
}

int main()
{
  int n;
  cin >> n;

  cout << recursion(n);
}