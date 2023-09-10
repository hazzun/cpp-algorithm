#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long factorial(int n)
{
  if (n <= 1)
    return 1;
  else
    return factorial(n - 1) * n;
}

vector<int> solution(int n, long long k)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int facSize = factorial(n);
  vector<int> arr;
  vector<int> answer;

  for (int i = 0; i < n; i++)
    arr.push_back(i + 1);

  for (int i = n; i > 1; i--)
  {
    int index;
    if (k == 0)
      index = arr.size() - 1;
    else
      index = (k - 1) / factorial(i - 1);

    answer.push_back(arr[index]);
    arr.erase(arr.begin() + index);
    k %= (factorial(i - 1));
  }

  answer.push_back(arr[0]);

  return answer;
}
