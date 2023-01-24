#include <iostream>
#include <cmath>
using namespace std;

int main(){
  int num;
  int cnt = 0;
  cin >> num;
  int tmp = num;
  do{
    tmp /= 10;
    cnt++;
  } while(tmp > 0);

  for(int i=1; i <= cnt; i++){
    int first;
    first = num / pow(10, cnt - i);
    num %= int(pow(10, cnt - i));
    cout << "[" << first * pow(10, cnt - i) << "]" << endl;
  }
}