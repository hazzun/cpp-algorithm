#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
  string str;
  cin >> str;

  sort(str.begin(), str.end());

  for (auto i : str)
    cout << i;
}