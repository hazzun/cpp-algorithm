/**
 * 남-남 / 여-여 끼리 방 배정 해야함
 * 한 방에는 같은 학년의 학생들을 배정해야 함
 * 한 방에 한 명만 배정하는 것도 가능
 */

/*
이중배열로 관리하기

stud[2][6]

[2]에 해당하는 부분 : 남 / 녀
[6]에 해당하는 부분 : 1~6학년
*/

#include <iostream>
using namespace std;

int main()
{
  int n, maxRoom, gender, level;
  cin >> n >> maxRoom;
  int stud[1000][1000] = {};

  for (int i = 0; i < n; i++)
  {
    cin >> gender >> level;
    stud[gender][level - 1]++;
  }
  int cnt = 0;
  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 6; j++)
    {
      if (stud[i][j] % maxRoom == 0)
      {
        cnt += stud[i][j] / maxRoom;
      }
      else
      {
        cnt += stud[i][j] / maxRoom + 1;
      }
    }
  }
  cout << cnt;
}