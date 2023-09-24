#include <iostream>

using namespace std;

int n, cnt;
int arr[20][20];
bool leftVisit[30];
bool underVisit[20];
bool rightVisit[30];

void rec(int num)
{
  if (num == n)
  {
    cnt++;
    return;
  }
  for (int i = 0; i < n; i++)
  {
    if (leftVisit[num + i] || underVisit[i] || rightVisit[num - i + n - 1])
      continue;
    leftVisit[num + i] = 1;
    underVisit[i] = 1;
    rightVisit[num - i + n - 1] = 1;
    rec(num + 1);
    leftVisit[num + i] = 0;
    underVisit[i] = 0;
    rightVisit[num - i + n - 1] = 0;
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  rec(0);
  cout << cnt;
  return 0;
}