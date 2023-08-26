#include <iostream>

using namespace std;

int board[52][52];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};
int n, t, r, c;
char d;

// 범위를 벗어났다면 true, 범위 내에 있다면 false 리턴
bool lineCheck(int i, int j)
{
  int nx = r + i;
  int ny = c + j;

  return (nx <= 0 || ny <= 0 || nx > n || ny > n);
}

int main()
{
  cin >> n >> t >> r >> c >> d;

  while (t--)
  {
    // cout << "d = " << d << " / (r, c) = " << r << ", " << c << "\n";
    if (d == 'U')
    {
      if (lineCheck(dx[0], dy[0]))
      {
        d = 'D';
        continue;
      }
      else
      {
        r += dx[0];
        c += dy[0];
      }
    }
    if (d == 'D')
    {
      if (lineCheck(dx[3], dy[3]))
      {
        d = 'U';
        continue;
      }
      else
      {
        r += dx[3];
        c += dy[3];
      }
    }
    if (d == 'R')
    {
      if (lineCheck(dx[1], dy[1]))
      {
        d = 'L';
        continue;
      }
      else
      {
        r += dx[1];
        c += dy[1];
      }
    }
    if (d == 'L')
    {
      if (lineCheck(dx[2], dy[2]))
      {
        d = 'R';
        continue;
      }
      else
      {
        r += dx[2];
        c += dy[2];
      }
    }
  }

  cout << r << " " << c;
}