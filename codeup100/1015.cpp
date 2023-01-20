#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
  float a;
  cin >> a;
  cout << fixed << setprecision(2) << round(a * 100) / 100 <<endl;
}