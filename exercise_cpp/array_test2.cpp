#include <bits/stdc++.h>
using namespace std;

int func1(int N)
{
  return -1;
}

int func2(int arr[], int N)
{
  int cnt = 0;
  for (int i = 0; i < N; i++)
  {
    for (int j = i + 1; j < N; j++)
    {
      if (arr[j] == 100 - arr[i])
        cnt++;
    }
  }
  return cnt;
}

int func3(int N)
{
  return -1;
}

int func4(int N)
{
  return -1;
}

void test1()
{
  cout << "****** func1 test ******\n";
  int n[3] = {16, 34567, 27639};
  int ans[3] = {60, 278812814, 178254968};
  for (int i = 0; i < 3; i++)
  {
    int result = func1(n[i]);
    cout << "TC #" << i << '\n';
    cout << "expected : " << ans[i] << " result : " << result;
    if (ans[i] == result)
      cout << " ... Correct!\n";
    else
      cout << " ... Wrong!\n";
  }
  cout << "*************************\n\n";
}

void test2()
{
  cout << "****** func2 test ******\n";
  int arr[4][8] = {{1, 52, 48}, {50, 42}, {4, 13, 63, 87}, {10, 42, 90, 38, 23, 13, 77, 58}};
  int n[4] = {3, 2, 4, 8};
  int ans[4] = {1, 0, 1, 3};
  for (int i = 0; i < 4; i++)
  {
    int result = func2(arr[i], n[i]);
    cout << "TC #" << i << '\n';
    cout << "expected : " << ans[i] << " result : " << result;
    if (ans[i] == result)
      cout << " ... Correct!\n";
    else
      cout << " ... Wrong!\n";
  }
  cout << "*************************\n\n";
}

void test3()
{
  cout << "****** func3 test ******\n";
  int n[3] = {9, 693953651, 756580036};
  int ans[3] = {1, 0, 1};
  for (int i = 0; i < 3; i++)
  {
    int result = func3(n[i]);
    cout << "TC #" << i << '\n';
    cout << "expected : " << ans[i] << " result : " << result;
    if (ans[i] == result)
      cout << " ... Correct!\n";
    else
      cout << " ... Wrong!\n";
  }
  cout << "*************************\n\n";
}

void test4()
{
  cout << "****** func4 test ******\n";
  int n[3] = {5, 97615282, 1024};
  int ans[3] = {4, 67108864, 1024};
  for (int i = 0; i < 3; i++)
  {
    int result = func4(n[i]);
    cout << "TC #" << i << '\n';
    cout << "expected : " << ans[i] << " result : " << result;
    if (ans[i] == result)
      cout << " ... Correct!\n";
    else
      cout << " ... Wrong!\n";
  }
  cout << "*************************\n\n";
}

int main(void)
{
  // test1();
  test2();
  // test3();
  // test4();
}