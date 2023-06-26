#include <iostream>
#include <list>
using namespace std;

list<int> circle_list;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k, arr[5000] = {};
  cin >> n >> k;

  // 1 ~ n 인 리스트 만들기
  for (int i = 1; i <= n; i++)
    circle_list.push_back(i);
  auto pointer = circle_list.begin();
  // (원형리스트 만들기) -> end point 이면 pointer의 위치를 begin으로
  // 시작점(1) 부터 3번째인 노드 찾고
  for (int j = 0; j < n; j++) {
    for (int i = 1; i < k; i++) {
      pointer++;
      if (pointer == circle_list.end())
        pointer = circle_list.begin();
    }
    // 3번째 노드를 삭제하기
    // cout << *pointer << ", ";
    arr[j] = *pointer;
    pointer = circle_list.erase(pointer);
    if (pointer == circle_list.end())
      pointer = circle_list.begin();
  }
  cout << "<";
  for (int i = 0; i < n; i++) {
    cout << arr[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << ">";
}