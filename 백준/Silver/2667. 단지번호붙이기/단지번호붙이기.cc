#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

string board[50];
bool vis[50][50];

int nx[4] = {1, 0, -1, 0};
int ny[4] = {0, 1, 0, -1};

int n;
vector<int> answer;

int BFS(int i, int j)
{
  queue<pair<int, int>> Q;
  Q.push({i, j});
  vis[i][j] = 1;

  int area = 0;

  while (!Q.empty())
  {
    area++;
    auto cur = Q.front();
    Q.pop();

    for (int dir = 0; dir < 4; dir++)
    {
      int dx = cur.first + nx[dir];
      int dy = cur.second + ny[dir];

      if (dx < 0 || dy < 0 || dx >= n || dy >= n)
        continue;
      if (board[dx][dy] == '0' || vis[dx][dy])
        continue;

      vis[dx][dy] = 1;
      Q.push({dx, dy});
    }
  }
  return area;
}

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int count = 0;

  cin >> n;

  for (int i = 0; i < n; i++)
    cin >> board[i];

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (board[i][j] == '1' && !vis[i][j])
      {
        count++;
        answer.push_back(BFS(i, j));
      }
    }
  }
  sort(answer.begin(), answer.end());

  cout << count << "\n";
  for (int i : answer)
    cout << i << "\n";
}