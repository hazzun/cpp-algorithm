#include <iostream>
#include <vector>

using namespace std;

int k, n;
vector<int> v;

void choose(int num)
{
  if (num == n + 1)
  {
    for (auto i : v)
      cout << i << " ";
    cout << "\n";
    return;
  }
  for (int i = 1; i <= k; i++)
  {
    v.push_back(i);
    choose(num + 1);
    v.pop_back();
  }
}

int main()
{
  cin >> k >> n;
  choose(1);
}