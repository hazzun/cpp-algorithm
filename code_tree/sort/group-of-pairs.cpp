#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[2000];

int main()
{
  cin >> n;
  for (int i = 0; i < n * 2; i++)
  {
    cin >> arr[i];
  }

  sort(arr, arr + n * 2);

  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum = max(sum, arr[i] + arr[2 * n - i - 1]);
  }
  cout << sum;
}