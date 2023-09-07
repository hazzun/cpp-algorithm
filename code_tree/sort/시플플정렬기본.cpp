#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
  int arr[8] = {12, 41, 37, 81, 19, 25, 60, 20};
  // 오름차순 정렬
  sort(arr, arr + 8);
  for (auto i : arr)
    cout << i << " ";

  cout << "\n";
  // 내림차순 정렬
  sort(arr, arr + 8, greater<int>());
  for (auto i : arr)
    cout << i << " ";
  return 0;
}