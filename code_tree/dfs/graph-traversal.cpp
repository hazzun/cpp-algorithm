// #include <iostream>
// #include <vector>

// using namespace std;

// int board[1002][1002];
// bool vis[1002];
// int n, m;
// int cnt;

// void dfs(int start)
// {
//   for (int i = 0; i < n; i++)
//   {
//     if (board[start][i] == 1 && !vis[i])
//     {
//       vis[i] = true;
//       cnt++;
//       dfs(i);
//     }
//   }
// }

// int main()
// {
//   ios::sync_with_stdio(0);
//   cin.tie(0);

//   cin >> n >> m;
//   while (m--)
//   {
//     int x, y;
//     cin >> x >> y;
//     board[x - 1][y - 1] = 1;
//     board[y - 1][x - 1] = 1;
//   }
//   dfs(0);
//   if (cnt)
//     cout << cnt - 1;
//   else
//     cout << 0;
// }

#include <iostream>
#include <vector>

using namespace std;

int n, m, cnt;
vector<int> v[1002];
bool vis[1002];

void dfs(int node)
{
  for (int i = 0; i < v[node].size(); i++)
  {
    if (!vis[v[node][i]])
    {
      vis[v[node][i]] = true;
      cnt++;
      cout << "node : " << node << ", v[node][i] : " << v[node][i] << "\n";
      dfs(v[node][i]);
    }
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  int x, y;
  while (m--)
  {
    cin >> x >> y;

    v[x].push_back(y);
    v[y].push_back(x);
  }
  for (int i = 1; i <= n; i++)
  {
    cout << i << " : ";
    for (int j = 0; j < v[i].size(); j++)
    {
      cout << v[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "\n";
  vis[1] = true;
  dfs(1);

  cout << cnt;
}