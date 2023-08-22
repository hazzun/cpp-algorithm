#include <iostream>
#include <queue>

using namespace std;

int board[1000001];

int high, loc, goal, up, down;

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> high >> loc >> goal >> up >> down;
   
  if(loc == goal){
      cout << 0;
      return 0;
  }

  int next[2] = {up, -down};

  for (int i = 0; i < high; i++)
    board[i] = -1;

  queue<int> Q;
  Q.push(loc);
  board[loc] = 0;

  while (!Q.empty())
  {
    int cur = Q.front();
    Q.pop();

    for (int i = 0; i < 2; i++)
    {
      int nx = cur + next[i];

      if (nx == goal)
      {
        cout << board[cur] + 1;
        return 0;
      }
      if (nx > high || nx <= 0)
        continue;
      if (nx < high && board[nx] == -1)
      {
        Q.push(nx);
        board[nx] = board[cur] + 1;
      }
      if (nx > 0 && board[nx] == -1)
      {
        Q.push(nx);
        board[nx] = board[cur] + 1;
      }
    }
  }
  cout << "use the stairs";
  return 0;
}