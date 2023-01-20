#include <iostream>
using namespace std;

int main() {
  int y, m, d;
  char semi;

  cin >> y >> semi >> m >> semi >> d;

  cout.width(4);
  cout.fill('0');
  cout << y << ".";

  cout.width(2); cout.fill('0');
  cout << m << ".";

  cout.width(2);
  cout.fill('0');
  cout << d << endl;
}