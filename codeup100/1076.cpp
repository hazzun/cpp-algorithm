#include <iostream>
using namespace std;

int main() {
  char x, text = 'a';
  cin >> x;
  
  do
  {
    cout << text << " ";
    text++;
    if(x == text)
      break;
  } while (text <= 'z');
  
}