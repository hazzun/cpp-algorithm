#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
string t;
string box[101];

bool isContain(string x)
{
  // cout << x << ", " << t << "\n";
  for (int i = 0; i < t.size(); i++)
  {
    if (t[i] != x[i])
      return false;
  }
  return true;
}

int main()
{
  cin >> n >> k >> t;

  for (int i = 0; i < n; i++)
    cin >> box[i];

  sort(box, box + n);

  int count = 0;
  for (int i = 0; i < n; i++)
  {
    if (isContain(box[i]))
      count++;
    if (count == k)
    {
      cout << box[i];
      return 0;
    }
  }
}