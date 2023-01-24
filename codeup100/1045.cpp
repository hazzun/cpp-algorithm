#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
  long long a, b;
  scanf("%ld %ld", &a, &b);
  cout << a+b << '\n' << a-b << '\n' << a * b << '\n' << a/b << '\n' << a%b << endl;
  cout << fixed << setprecision(2);
  cout << round(((a * 1000) / b)) / 1000;
}