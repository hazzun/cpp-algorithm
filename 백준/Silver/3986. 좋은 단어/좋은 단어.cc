#include <iostream>
#include <stack>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, cnt = 0;
  cin >> n;
  while (n--) {
    stack<char> S;
    string code;
    cin >> code;

    for (auto i : code) {
      if (S.empty())
        S.push(i);
      else if (i == 'A') {
        if (S.top() == 'A')
          S.pop();
        else
          S.push(i);
      } else if (i == 'B') {
        if (S.top() == 'B')
          S.pop();
        else
          S.push(i);
      }
    }

    if (S.empty())
      cnt++;
  }
  cout << cnt;
}