#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int arr[10];
bool isused[10];
int userArr[10];

void rec(int k)
{
  if (k == m) // m개의 수를 모두 채웠을 경우
  {
    for (int i = 0; i < m; i++)
      cout << userArr[arr[i]] << " "; // 채워진 수를 모두 출력
    cout << "\n";
    return;
  }
  for (int i = 0; i < n; i++) // n개의 수를 조회
  {
    if (!isused[i]) // i번째 수를 사용하지 않았다면
    {
      arr[k] = i;                       // k번째 칸을 i로 채워주고
      if (k > 0 && arr[k - 1] > arr[k]) // 현재 채울 수가 이전에 채워진 수보다 작으면 재귀실행 x
        continue;
      isused[i] = 1; // i번째 배열을 사용했으니 사용했다는 표시
      rec(k + 1);    // k+1번째 칸을 채우기 위해 조회
      isused[i] = 0; // k가 i일때의 값을 모두 조회했으므로 다시 off
    }
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  for (int i = 0; i < n; i++)
    cin >> userArr[i];
  sort(userArr, userArr + n);

  rec(0);
  return 0;
}