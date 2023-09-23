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
  for (int i = 0; i < n; i++)
  {
    if (!isused[i])
    {
      arr[k] = i;
      rec(k + 1);
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