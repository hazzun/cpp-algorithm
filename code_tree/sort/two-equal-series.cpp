#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[100];
int b[100];

bool isSame()
{
  bool flag = true;
  for (int i = 0; i < n; i++)
  {
    // cout << "a[" << i << "] : " << a[i] << ", b[" << i << "] : " << b[i] << "\n";
    if (a[i] != b[i])
    {
      flag = false;
      break;
    }
  }
  return flag;
}

int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  for (int i = 0; i < n; i++)
  {
    cin >> b[i];
  }

  sort(a, a + n);
  sort(b, b + n);

  if (isSame())
    cout << "Yes";
  else
    cout << "No";
}
