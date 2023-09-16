#include <iostream>

using namespace std;

int n, r, c, cnt, maxCount;

void rec(int x, int y, int size)
{
  if (x == r && y == c)
  {
    maxCount = max(maxCount, cnt);
    cout << cnt;
    return;
  }
  if (size == 1)
  {
    cout << "( " << x << ", " << y << " ) - count : " << cnt << "\n";
    cnt++;
    return;
  }
  int nextSize = size / 2;
  if (cnt <= maxCount || maxCount == 0)
  {
    for (int i = 0; i < 2; i++)
    {
      for (int j = 0; j < 2; j++)
      {
        rec(x + i * nextSize, y + j * nextSize, nextSize);
      }
    }
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> r >> c;

  rec(0, 0, 1 << n);
  return 0;
}