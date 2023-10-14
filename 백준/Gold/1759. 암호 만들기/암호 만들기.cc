#include <iostream>
#include <algorithm>

using namespace std;

int l, c;
char userArr[20];
char arr[20];

bool aeiou()
{
  int cnt = 0; // 모음의 개수
  for (int i = 0; i < l; i++)
  {
    if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
      cnt++;
  }
  if (cnt >= 1 && (l - cnt) >= 2)
    return true;
  else
    return false;
}

void backtracking(int k)
{
  if (k == l && aeiou())
  {
    for (int i = 0; i < k; i++)
      cout << arr[i];
    cout << "\n";
  }
  for (int i = 0; i < c; i++)
  {
    arr[k] = userArr[i];
    if (k > 0 && arr[k - 1] >= arr[k])
      continue;
    backtracking(k + 1);
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> l >> c;
  for (int i = 0; i < c; i++)
    cin >> userArr[i];
  sort(userArr, userArr + c);

  backtracking(0);
  return 0;
}