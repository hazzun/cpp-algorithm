#include <iostream>
using namespace std;

int main()
{
  int n, cnt = 0, ans;
  cin >> n;
  int inputArr[1000001] = {};
  bool occurArr[2000001];

  for (int i = 0; i < n; i++)
  {
    cin >> inputArr[i];
  }

  cin >> ans;

  for (int i = 0; i < n; i++)
  {
      if((ans - inputArr[i]) > 0 && (occurArr[ans-inputArr[i]])) cnt++;
      occurArr[inputArr[i]] = true;
  }

  cout << cnt;
}