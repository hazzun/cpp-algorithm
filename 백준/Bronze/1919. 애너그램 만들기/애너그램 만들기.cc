#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s1, s2;
  cin >> s1 >> s2;

  int arr[26] = {}, cnt = 0;

  for (auto c : s1)
    arr[c - 'a']++;
  for (auto c : s2)
    arr[c - 'a']--;

  for (int k : arr)
  {
    if (k != 0)
      cnt += abs(k);
  }
  cout << cnt;
}