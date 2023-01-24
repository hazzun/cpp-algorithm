#include <iostream>
using namespace std;

int main() {
  char word[20];
  cin >> word;
  for(auto& i : word){
    if(i == '\0')
      break;
    cout << '\'' << i <<'\'' << endl;
  }
}