#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
  int n, x, k;
  cin >> n >> x;
  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++)
  {
    cin >> k;
    if (x > k)
      arr[i] = k;
  }
  for (int j = 0; j < n; j++)
  {
    if (arr[j] > 0)
    {
      cout << arr[j] << " ";
    }
  }
}