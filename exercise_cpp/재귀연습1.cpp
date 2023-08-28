// a^b mod m 의 값 구하기
// 반복문으로 작성하면 int overflow 발생

#include <iostream>

using namespace std;

int recursionMod(int a, int b, int m, int tmp = 1)
{
  if (b == 0)
  {
    cout << "정답은 : " << tmp;
    return tmp;
  }
  tmp = tmp * a % m;
  return (tmp * recursionMod(a, b - 1, m, tmp) % m);
}

int main(void)
{
  int a, b, m;
  cin >> a >> b >> m;

  recursionMod(a, b, m);
  return 0;
}