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
      cout << arr[i] << " ";
    cout << "\n";
    return;
  }
  int tmp = 0;
  for (int i = 0; i < n; i++)
  {
    arr[k] = userArr[i];
    // cout << "k = " << k << ", i = " << i << " \n";

    if (k == 0 && i > 0 && arr[k] == userArr[i - 1])
      continue;
    if (k > 0 && tmp == userArr[i])
    {
      // cout << "ㅈ자ㅂ았다\n";
      continue;
    }
    tmp = userArr[i];
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