#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int n;
  cin >> n;

  string first, second;
  string arr[1000][2] = {};
  for (int i = 0; i < n; i++)
  {
    cin >> first >> second;
    arr[i][0] = first;
    arr[i][1] = second;
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      sort(arr[i][j].begin(), arr[i][j].end());
    }
  }
  for (int i = 0; i < n; i++)
  {
    if (arr[i][0] == arr[i][1])
      cout << "Possible\n";
    else
      cout << "Impossible\n";
  }
}