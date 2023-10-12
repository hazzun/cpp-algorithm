#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int userArr[10];
int check[10];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    cin >> userArr[i];
    if (i > m - 1)
      check[i] = 1;
  }

  sort(userArr, userArr + n);

  do
  {
    for (int i = 0; i < n; i++)
      if (!check[i])
        cout << userArr[i] << " ";
    cout << "\n";
  } while (next_permutation(check, check + n));
}