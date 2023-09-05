#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;
int board[52][52];
int safeSection[52][52];
int countSection[100];
bool vis[52][52];
stack<pair<int, int>> S;

void dfs(int x, int y)
{
  while (!S.empty())
  {
    auto cur = S.top();
    S.pop();

    for (int dir = 0; dir < 4; dir++)
    {
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];

      if (nx < 0 || ny < 0 || nx >= n || ny >= m)
        continue;
      if (vis[nx][ny] || !safeSection[nx][ny])
        continue;

      vis[nx][ny] = 1;
      S.push({nx, ny});
    }
  }
}

int main()
{
  cin >> n >> m;

  int maxPoint = 0;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> board[i][j];
      maxPoint = max(maxPoint, board[i][j]);
    }
  }
  while (maxPoint > 0)
  {
    maxPoint--;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (board[i][j] > maxPoint)
          safeSection[i][j] = 1;
      }
    }
    cout << "\nmaxpoint : " << maxPoint << "\n";
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        cout << safeSection[i][j] << " ";
      }
      cout << "\n";
    }
    int count = 0;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (safeSection[i][j] && !vis[i][j])
        {
          S.push({i, j});
          vis[i][j] = 1;
          count++;
          dfs(i, j);
        }
      }
    }
    // vis 배열 초기화해주기
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        vis[i][j] = 0;

    cout << count << "\n";
    countSection[maxPoint - 1] = count;
  }

  // 모든 경우에서 나오는 안전지대 개수의 최대값 구하기
  int answer = 0;
  for (auto i : countSection)
    answer = max(answer, i);
  cout << "answer = " << answer << "\n";
  // 답안 출력
  for (int i = 0; i < 100; i++)
  {
    if (answer == countSection[i])
    {
      cout << i + 1 << " " << answer;
      return 0;
    }
  }
}

/*
4 5
1 2 4 7 5
4 2 5 5 2
5 7 3 2 6
6 7 4 5 1

=> 4 4
*/