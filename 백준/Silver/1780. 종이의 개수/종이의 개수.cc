#include <iostream>

using namespace std;

int n;
int board[2500][2500];
int numCount[3];

bool sameCheck(int x, int y, int num)
{
  if (num == 1)
    return true;

  for (int i = x; i < x + num; i++)
    for (int j = y; j < y + num; j++)
      if (board[i][j] != board[x][y])
        return false;
  return true;
}

void cutPaper(int x, int y, int size)
{
  if (sameCheck(x, y, size))
  {
    numCount[board[x][y] + 1]++;
    return;
  }
  else
  {
    int tmp = size / 3;
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
        cutPaper(x + i * tmp, y + j * tmp, tmp);
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> board[i][j];
    }
  }
  cutPaper(0, 0, n);

  for (auto i : numCount)
    cout << i << "\n";
}