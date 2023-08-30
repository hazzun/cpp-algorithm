#include <iostream>

using namespace std;

int arr[10];

int gcd(int a, int b)
{
  int tmp;
  while (b != 0)
  {
    tmp = a % b;
    a = b;
    b = tmp;
  }
  return a;
}
int answer(int a, int b)
{
  return a * b / gcd(a, b);
}

int rec(int n)
{
  if (n == 0)
    return arr[0];
  return answer(rec(n - 1), arr[n]);
}

int main()
{
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  cout << rec(n - 1);
}