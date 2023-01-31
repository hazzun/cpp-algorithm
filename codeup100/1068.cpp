#include <iostream>
using namespace std;

int main() {
  int a;
  cin >> a;

  if(a >= 90 && a <= 100) {
    cout << "A" << endl;
  } else if (a < 90 && a >= 70){
    cout << "B" << endl;
  } else if (a < 70 && a >= 40){
    cout << "C" << endl;
  } else if (a < 40 && a >= 0){
    cout << "D" << endl;
  }
}