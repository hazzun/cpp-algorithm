#include <iostream>

using namespace std;

int oddRec(int n)
{
  if (n == 1)
    return 1;
  return oddRec(n - 2) + n;
}
int evenRec(int n)
{
  if (n == 2)
    return 2;
  return evenRec(n - 2) + n;
}

int main()
{
  int n;
  cin >> n;

  if (n % 2 == 1)
    cout << oddRec(n);
  else
    cout << evenRec(n);
}