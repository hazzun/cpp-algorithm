#include <iostream>

using namespace std;

int n, s, cnt;
int arr[20];
bool isvisit[20];
int tmp[20];

void rec(int m, int k)
{
  if (m == k)
  {
    int sum = 0;
    for (int i = 0; i < m; i++)
      sum += arr[tmp[i]];
    if (sum == s)
      cnt++;
    return;
  }

  for (int i = 0; i < n; i++)
  {
      tmp[k] = i;
      if (k > 0 && tmp[k - 1] >= tmp[k])
        continue;
      rec(m, k + 1);
  }

  return;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> s;

  for (int i = 0; i < n; i++)
    cin >> arr[i];

  for (int i = 1; i <= n; i++)
    rec(i, 0);
  cout << cnt;
  return 0;
}