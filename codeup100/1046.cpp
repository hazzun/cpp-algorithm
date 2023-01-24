#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
  long long a, b, c;
  scanf("%ld %ld %ld", &a, &b, &c);
  cout << a + b + c << endl;
  cout << fixed << setprecision(1);
  cout << round((a + b + c) * 100 / 3) / 100;
}