#include <iostream>

using namespace std;

void printStar(int n)
{
  if (n == 0)
    return;
  printStar(n - 1);
  for (int i = 0; i < n; i++)
  {
    cout << "*";
  }
  cout << "\n";
}

int main()
{
  int n;
  cin >> n;

  printStar(n);
}