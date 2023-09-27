#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int userArr[10];
int arr[10];
bool isused[10];

void rec(int k)
{
  if (k == m)
  {
    for (int i = 0; i < m; i++)
      cout << userArr[arr[i]] << " ";
    cout << "\n";
    return;
  }

  int tmp = 0;
  for (int i = 0; i < n; i++)
  {
    if (!isused[i] && tmp != userArr[i])
    {
      arr[k] = i;
      tmp = userArr[arr[k]];
      isused[i] = 1;
      rec(k + 1);
      isused[i] = 0;
    }
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  for (int i = 0; i < n; i++)
    cin >> userArr[i];

  sort(userArr, userArr + n);

  rec(0);
  return 0;
}