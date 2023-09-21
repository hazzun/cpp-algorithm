#include <iostream>
#include <vector>

using namespace std;

int n, m;
int arr[10];
bool isused[10];

void rec(int num)
{
  if (num == m)
  {
    for (int i = 0; i < m; i++)
      cout << arr[i] << " ";
    cout << "\n";
    return;
  }
  for (int i = 1; i <= n; i++)
  {
    if (!isused[i])
    {
      arr[num] = i;
      isused[i] = 1;
      rec(num + 1);
      isused[i] = 0;
    }
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  rec(0);

  return 0;
}