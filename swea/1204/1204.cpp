#include <iostream>
#include <algorithm>

using namespace std;

int arr[101];

int go()
{
  for (int i = 0; i < 1000; i++)
  {
    int tmp;
    cin >> tmp;
    arr[tmp]++;
  }

  int maxNum = -1;
  int answer = 0;
  for (int i = 0; i < 101; i++)
  {
    // cout << arr[i] << ", ";
    if (arr[i] >= maxNum)
    {
      if (arr[i] == maxNum)
      {
        if (i < answer)
          continue;
      }
      maxNum = arr[i];
      answer = i;
    }
  }
  // cout << answer << " " << maxNum;
  // cout << "\n";
  return answer;
}

void clear()
{
  for (int i = 0; i < 101; i++)
  {
    arr[i] = 0;
  }
}

int main(int argc, char **argv)
{
  int test_case;
  int T;
  int abc;

  freopen("input.txt", "r", stdin);
  cin >> T;

  for (test_case = 1; test_case <= T; ++test_case)
  {
    cin >> abc;
    cout << "#" << abc << " " << go() << "\n";
    clear();
  }
  return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}