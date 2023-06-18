#include <vector>
#include <iostream>
using namespace std;

int countArr[26]; // 전역에 배열선언하면 자동으로 0으로 초기화

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  cin >> s;

  for (auto tmp : s) // s에서 문자열 하나씩 꺼내기
  {
    countArr[tmp - 'a']++;
  }
  for (int i = 0; i < 26; i++)
  {
    cout << countArr[i] << " ";
  }
}

/**
int main()
{
  // 문자열 입력받기
  string word;
  vector<int> alpaArr(26, 0);

  cin >> word;

  // 문자열 길이만큼 반복문 돌리기
  for (int i = 0; i < word.size(); i++)
  {
    // i번째 문자열이 a(97) ~ z(122) 에 포함되는지
    if (97 <= int(word[i]) && int(word[i]) <= 122)
    {
      // alpaArr[asciiNum-97] 값을 1 증가시키기
      alpaArr[int(word[i]) - 97] += 1;
    }
  }

  // alpaArr[] 전체 출력
  for (int i = 0; i < 26; i++)
  {
    cout << alpaArr[i] << ' ';
  }
}
*/