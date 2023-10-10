#include <iostream>

using namespace std;

int n = 1, end;
int userArr[50];
int arr[50];
bool isvisit[50];

void rec(int k)
{
  if (k == 6)
  {
    for (int i = 0; i < k; i++)
      cout << arr[i] << " ";
    cout << "\n";
    return;
  }

  for (int i = 0; i < n; i++)
  {
    arr[k] = userArr[i];
    if (k > 0 && arr[k - 1] >= arr[k])
      continue;
    rec(k + 1);
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  while (n)
  {
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> userArr[i];

    rec(0);
    cout << "\n";
  }
  return 0;
}