#include <iostream>

using namespace std;

int n, m;
int arr[10];
bool isused[10];

void backtracking(int num)
{
  if (num == m)
  {
    for (int i = 0; i < num; i++)
      cout << arr[i] << " ";
    cout << "\n";
    return;
  }
  for (int i = 1; i <= n; i++)
  {
    if (!isused[i])
    {
      arr[num] = i;
      if (num > 0 && arr[num - 1] >= arr[num])
        continue;
      isused[i] = 1;
      backtracking(num + 1);
      isused[i] = 0;
    }
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  backtracking(0);

  return 0;
}