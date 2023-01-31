#include <iostream>
using namespace std;

int main() {
  string a;
  cin >> a;

  if(a == "A")
    cout << "best!!!" << endl;
  else if(a == "B")
    cout << "good!!" << endl;
  else if(a == "C")
    cout << "run!" << endl;
  else if(a == "D")
    cout << "slowly~" << endl;
  else
    cout << "what?" << endl;
}