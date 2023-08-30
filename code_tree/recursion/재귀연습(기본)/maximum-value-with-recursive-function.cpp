#include <iostream>
#include <algorithm>

using namespace std;

int temp[100];

int maxRec(int n)
{
  if (n == 0)
    return temp[0];
  return max(maxRec(n - 1), temp[n]);
}

int main()
{
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> temp[i];
  cout << maxRec(n);
}