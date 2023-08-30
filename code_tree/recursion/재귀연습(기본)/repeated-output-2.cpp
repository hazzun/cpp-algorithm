#include <iostream>

using namespace std;

int n;

void printHello(int n)
{
  if (n == 0)
    return;
  printHello(n - 1);
  cout << "HelloWorld\n";
}

int main()
{
  cin >> n;
  printHello(n);
}