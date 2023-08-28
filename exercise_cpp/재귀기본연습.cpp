#include <iostream>

using namespace std;

int recursionSum(int n)
{
  if (n == 0)
    return 0;
  return (n + recursionSum(n - 1));
}

int recursionPrint(int n)
{
  if (n == 0)
    return 0;
  cout << n << " ";
  recursionPrint(n - 1);
}

int main(void)
{
  int n;
  cin >> n;
  int sum = 0;
  sum = recursionSum(n);

  cout << sum << "\n";
}