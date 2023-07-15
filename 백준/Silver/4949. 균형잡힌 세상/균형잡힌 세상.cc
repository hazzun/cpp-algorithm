#include <iostream>
#include <stack>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while (1) {
    string stc;
    bool isValid = true;
    getline(cin, stc);
    if (stc == ".")
      return 0;
    stack<char> S;

    for (int i = 0; i < stc.length(); i++) {
      if (stc[i] == '(' || stc[i] == '[')
        S.push(stc[i]);
      else if (stc[i] == ')') {
        if (S.empty() || S.top() != '(') {
          isValid = false;
          break;
        } else
          S.pop();
      } else if (stc[i] == ']') {
        if (S.empty() || S.top() != '[') {
          isValid = false;
          break;
        } else
          S.pop();
      }
    }
    if (!S.empty())
      isValid = false;
    if (isValid)
      cout << "yes\n";
    else
      cout << "no\n";
  }
}