#include <iostream>
#include <iomanip>
using namespace std;

int main(){
  int y, m, d;
  scanf("%d.%d.%d", &y, &m, &d);
  cout.width(2);
  cout.fill('0');
  cout << d << "-";
  
  cout.width(2);
  cout.fill('0');
  cout << m << "-";

  cout.width(4);
  cout.fill('0');
  cout << y<< endl;
}