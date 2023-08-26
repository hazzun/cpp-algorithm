#include <iostream>
#include <list>
using namespace std;

const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;

void insert(int addr, int num)
{
  dat[unused] = num;
  pre[unused] = addr;
  nxt[unused] = nxt[addr];
  if (nxt[addr] != -1)
    pre[nxt[addr]] = unused;
  nxt[addr] = unused;

  unused++;
}

void erase(int addr)
{
  /**
   * 삭제할 노드의 이전노드의 nxt를 삭제할 노드의 nxt로
   * 삭제할 노드의 다음노드의 pre를 삭제할 노드의 pre로
   */
  nxt[pre[addr]] = nxt[addr];
  if (nxt[addr] != -1)
    pre[nxt[addr]] = pre[addr];
}

void traverse()
{
  int cur = nxt[0];
  while (cur != -1)
  {
    cout << dat[cur] << ' ';
    cur = nxt[cur];
  }
  cout << "\n\n";
}

int main()
{
  fill(pre, pre + MX, -1);
  fill(nxt, nxt + MX, -1);

  // 사용자로부터 문자열 입력받고
  string inputText;
  cin >> inputText;
  // list에 넣어주기
  for (char i : inputText)
  {
    insert()
  }

  // cursor는 리스트의 끝을 가리키고 있음
  auto cursor = listText.end();
  // cursor--;
  // cout << *cursor << "<- cursor의 위치 \n";

  // 몇개의 명령어를 입력받을건지 물어보고
  int n;
  cin >> n;

  while (n > 0)
  {
    // 명령어 입력받기
    char cmd, word;
    cin >> cmd;
    // 단어를 추가하는 명령어(P) 일 때
    if (cmd == 'P')
    {
      cin >> word;
      listText.insert(cursor, word);
    }
    // 커서를 왼쪽으로 이동하라는 명령어(L) 일 때
    if (cmd == 'L')
    {
      if (cursor != listText.begin())
        cursor--;
    }
    // 커서를 오른쪽으로 이동하라는 명령어(D) 일 때
    if (cmd == 'D')
    {
      if (cursor != listText.end())
        cursor++;
    }
    // 커서 왼쪽의 문자를 삭제하라는 명령어(B) 일 때
    if (cmd == 'B')
    {
      if (cursor != listText.begin())
        cursor = listText.erase(--cursor);
    }
    n--;
  }

  for (auto i : listText)
    cout << i;
}