#include <iostream>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  if((a == true && b == true) || (a == false && b == false))
    cout << 0;
  else
    cout << 1;
}