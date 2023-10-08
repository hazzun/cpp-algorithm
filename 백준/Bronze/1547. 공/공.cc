#include <iostream>

using namespace std;

bool isBallInclude[3] = {true, false, false};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  int a, b;

  for (int i = 0; i < n; i++)
  {
    cin >> a >> b;
    if (!isBallInclude[a - 1] && !isBallInclude[b - 1])
      continue;
    else
    {
      bool tmp = true;
      tmp = isBallInclude[a - 1];
      isBallInclude[a - 1] = isBallInclude[b - 1];
      isBallInclude[b - 1] = tmp;
    }
  }

  for (int i = 0; i < 3; i++)
  {
    if (isBallInclude[i])
      cout << i + 1;
  }
}