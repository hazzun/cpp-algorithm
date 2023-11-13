#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

  int arr[1000001];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int test_case;
  int T;

  cin >> T;

  for (test_case = 1; test_case <= T; ++test_case)
  {
    long long extraSum = 0;
    long long count = 0;
    long long answer = 0;
    int maxNum = 0;

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
      cin >> arr[i];
      if (maxNum < arr[i])
        maxNum = arr[i];
    }
    for (int i = 0; i < N; i++)
    {
      if (arr[i] != maxNum)
      {
        extraSum += arr[i];
        count++;
      }
      else
      {
        answer += arr[i] * count - extraSum;
        maxNum = 0;
        extraSum = 0;
        count = 0;
        if (i + 1 != N)
        {
          for (int k = i + 1; k < N; k++)
          {
            if (maxNum < arr[k])
              maxNum = arr[k];
          }
        }
      }
    }
    cout << "#" << test_case << " " << answer << "\n";
  }
}