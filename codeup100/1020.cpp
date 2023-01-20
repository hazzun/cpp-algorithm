#include <iostream>
using namespace std;

int main() {
  int a, b;
  char mid;
  cin >> a >> mid >> b;

  cout.width(6);
  cout.fill('0');
  cout << a;
  cout << b << endl;
}