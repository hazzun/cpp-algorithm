#include <vector>
#include <iostream>
using namespace std;

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