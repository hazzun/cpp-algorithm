#include <iostream>
#include <stack>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  stack<int> S;
  int cnt = 0;

  string stick;
  cin >> stick;

  for (int i = 0; i < stick.length(); i++)
  {
    if (stick[i] == '(')
    {
      S.push(stick[i]);
    }
    else
    { 
      if (stick[i-1] == '(')
      {
        S.pop();
        cnt += S.size();
      }
      else
      {                 
        S.pop();
        cnt++;
      }
    }
  }
  
  cout << cnt;
}