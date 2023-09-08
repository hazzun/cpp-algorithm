#include <iostream>
#include <algorithm>

using namespace std;
string a, b;

bool isSame()
{
  for (int i = 0; i < a.size(); i++)
  {
    if (a[i] != b[i])
      return false;
  }
  return true;
}

int main()
{
  cin >> a >> b;

  if (a.size() != b.size())
  {
    cout << "No";
    return 0;
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  if (isSame())
    cout << "Yes";
  else
    cout << "No";
}