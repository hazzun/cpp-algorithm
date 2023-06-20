#include <bits/stdc++.h>
using namespace std;

int arr[10];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a, b, c, exp;
  cin >> a >> b >> c;
  exp = a * b * c;
  while(exp != 0){
      arr[exp % 10]++;
      exp /= 10;
  }
  for (int i = 0; i < 10; i++)
  {
    cout << arr[i] << '\n';
  }
}