#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int arr[10];
int check[10];

int main()
{
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
  {
    arr[i - 1] = i;
    if (i > m)
      check[i - 1] = 1;
  }

  do
  {
    for (int i = 0; i < n; i++)
    {
      if (check[i] == 0)
        cout << i + 1 << " ";
    }
    cout << "\n";
  } while (next_permutation(check, check + n));
}