#include <iostream>
#include <string>
#include <queue>
#include <utility>

using namespace std;

// 동 서 남 북 - R L U D
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool vis[11][11][4];
int nowX = 5, nowY = 5;
int answer = 0;

void checkMove(int x, int y, int nx, int ny, int dir, int tmp)
{
  vis[x][y][dir] = 1;
  cout << "dir : " << dir<<"\n";
  if (nx < 0 || ny < 0 || nx > 10 || ny > 10)
    return;
      nowX = nx;
  nowY = ny;
  if ( vis[nx][ny][tmp] )
    return;
  cout << "[x,y] = "
       << "[" << x << ", " << y << "], ";
  cout << "[nx,ny] = "
       << "[" << nx << ", " << ny << "]\n";
  vis[nx][ny][tmp] = 1;
  answer++;
  return;
}

int solution(string dirs)
{
  // int answer = 0;

  queue<char> Q;
  for (auto i : dirs)
    Q.push(i);
  // vis[5][5] = 1;
  while (!Q.empty())
  {
    auto cur = Q.front();
    Q.pop();
    if (cur == 'R')
    {
      checkMove(nowX, nowY, nowX + dx[0], nowY + dy[0], 0, 1);
    }
    else if (cur == 'L')
    {
      checkMove(nowX, nowY, nowX + dx[1], nowY + dy[1], 1, 0);
    }
    else if (cur == 'U')
    {
      checkMove(nowX, nowY, nowX + dx[2], nowY + dy[2], 2, 3);
    }
    else if (cur == 'D')
    {
      checkMove(nowX, nowY, nowX + dx[3], nowY + dy[3], 3, 2);
    }
  }
  cout << answer;
  return answer;
}