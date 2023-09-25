#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[10];
int userArr[10];
bool isused[10];

void rec(int k)
{
  if (k == m)
  {
    for (int i = 0; i < k; i++)
      cout << userArr[arr[i]] << " ";
    cout << "\n";
    return;
  }

  for (int i = 0; i < n; i++)
  {
    arr[k] = i;
    if (k > 0 && arr[k - 1] > arr[k])
      continue;
    rec(k + 1);
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