#include <iostream>

using namespace std;

int n;
int board[130][130];
int colorCount[2];

bool sameCheck(int x, int y, int count)
{
  for (int i = x; i < x + count; i++)
  {
    for (int j = y; j < y + count; j++)
    {
      if (board[x][y] != board[i][j])
        return false;
    }
  }
  return true;
}

void rec(int x, int y, int count)
{
  if (sameCheck(x, y, count))
  {
    colorCount[board[x][y]]++;
    return;
  }
  else
  {
    int slash = count / 2;
    for (int i = 0; i < 2; i++)
    {
      for (int j = 0; j < 2; j++)
      {
        rec(x + i * slash, y + j * slash, slash);
      }
    }
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> board[i][j];

  rec(0, 0, n);

  for (auto i : colorCount)
    cout << i << "\n";
}