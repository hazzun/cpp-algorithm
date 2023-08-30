#include <iostream>

using namespace std;

void startToEnd(int n)
{
  if (n == 0)
    return;
  startToEnd(n - 1);
  cout << n << " ";
}
void endToStart(int n)
{
  if (n == 0)
    return;
  cout << n << " ";
  endToStart(n - 1);
}

int main()
{
  int n;
  cin >> n;
  startToEnd(n);
  cout << "\n";
  endToStart(n);
}