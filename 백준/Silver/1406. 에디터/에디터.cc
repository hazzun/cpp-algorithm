#include <iostream>
#include <list>
using namespace std;

int main() {
  list<char> listText;
  // 사용자로부터 문자열 입력받고
  string inputText;
  cin >> inputText;
  // list에 넣어주기
  for (char i : inputText) {
    listText.push_back(i);
  }

  // cursor는 리스트의 끝을 가리키고 있음
  auto cursor = listText.end();
  // cursor--;
  // cout << *cursor << "<- cursor의 위치 \n";

  // 몇개의 명령어를 입력받을건지 물어보고
  int n;
  cin >> n;

  while (n > 0) {
    // 명령어 입력받기
    char cmd, word;
    cin >> cmd;
    // 단어를 추가하는 명령어(P) 일 때
    if (cmd == 'P') {
      cin >> word;
      listText.insert(cursor, word);
    }
    // 커서를 왼쪽으로 이동하라는 명령어(L) 일 때
    if (cmd == 'L') {
      if (cursor != listText.begin())
        cursor--;
    }
    // 커서를 오른쪽으로 이동하라는 명령어(D) 일 때
    if (cmd == 'D') {
      if (cursor != listText.end())
        cursor++;
    }
    // 커서 왼쪽의 문자를 삭제하라는 명령어(B) 일 때
    if (cmd == 'B') {
      if (cursor != listText.begin())
        cursor = listText.erase(--cursor);
    }
    n--;
  }

  for (auto i : listText)
    cout << i;
}