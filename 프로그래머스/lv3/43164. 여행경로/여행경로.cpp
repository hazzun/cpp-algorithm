#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

vector<vector<string>> ticket;
vector<string> answer;

bool check = false;
bool vis[10002];

void dfs(string s, int n)
{
    // cout << "dfs [s : " << s << ", n : " << n << "]\n";
  if (n == ticket.size())
  {
    // cout << "티켓사이즈는 : " << ticket.size();
    answer.push_back(s);  
    check = true;
    return;
  }
  for (int i = 0; i < ticket.size(); i++)
  {
      // cout << "for문 시작, i = " << i << "\n";
    if (vis[i] || ticket[i][0] != s)
      continue;

    // cout << "조건 통과, i = " << i << "\n";
    vis[i] = true;
    answer.push_back(s);

    dfs(ticket[i][1], ++n);
    if (!check)
    {
        // cout << "빠꾸 !\n";
        n--;
        vis[i] = false;
        answer.pop_back();
    }
  }
}

vector<string> solution(vector<vector<string>> tickets)
{
  int row = tickets.size();
  int col = tickets[0].size();

  sort(tickets.begin(), tickets.end());
  ticket = tickets;
    
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            // cout << ticket[i][j] << " ";
        }
        // cout << "\n";
    }

  dfs("ICN", 0);

  return answer;
}