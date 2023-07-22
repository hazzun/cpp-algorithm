/**
 * () = 2점
 * [] = 3점
 * ()[(())][] = 2 + (3 * 2 * 2) + 3 : score = 17
 * ()[()[()]] = 2 + 3 * (2 + (3 * 2)) : score = 26
 * 만약, 괄호 구성이 잘못된 경우 score = 0
 */
#include <iostream>
#include <stack>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  stack<char> S;

  string inputBracket;
  cin >> inputBracket;

  int score = 0;
  bool flag = false;
  char tmp = ' ';
  int flagScore = 0;

  for (auto i : inputBracket)
  {
    // '(' 가 들어왔다면
    if (i == '(')
    {
      tmp = ' ';

      if (!S.empty() && (S.top() == '(' || S.top() == '['))
        flag = true;
      S.push(i);
    }

    // '[' 가 들어왔다면
    else if (i == '[')
    {
      tmp = ' ';
      if (!S.empty() && (S.top() == '(' || S.top() == '['))
        flag = true;
      S.push(i);
    }

    // ')'가 들어왔다면
    else if (i == ')')
    {
      if (S.top() == '(')
      {
        S.pop();
        if (tmp == ' ')
        {
          if (flag)
          {
            flagScore += 2;
            cout << "1 flag score = " << flagScore << "\n";
          }
          else
          {
            score += 2;
            cout << "2 score = " << score << "\n";
          }
        }
        else if (tmp == ')' || tmp == ']')
        {
          flag = true;
          if (flag)
          {
            flagScore *= 2;
            cout << "3 flag score = " << flagScore << "\n";
            flag = false;
          }
          else
          {
            score *= 2;
            cout << "4 score = " << score << "\n";
          }
        }
        tmp = i;
      }
    }

    // ']'가 들어왔다면
    else if (i == ']')
    {
      if (S.top() == '[')
      {
        S.pop();
        if (tmp == ' ')
        {
          if (flag)
          {
            flagScore += 3;
            cout << "5 flag score = " << flagScore << "\n";
          }
          else
          {
            score += 3;
            cout << "6 score = " << score << "\n";
          }
        }
        else if (tmp == ')' || tmp == ']')
        {
          flag = true;
          if (flag)
          {
            flagScore *= 3;
            cout << "7 flag score = " << flagScore << "\n";
            flag = false;
          }
          else
          {
            score *= 3;
            cout << "8 score = " << score << "\n";
          }
        }
        tmp = i;
      }
    }
  }

  if (!flag)
  {
    score += flagScore;
  }
  if (S.empty())
    cout << score;
  else
    cout << "0";
}