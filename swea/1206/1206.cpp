#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int test_case;
	int T;
	freopen("input.txt", "r", stdin);
	for (int k = 0; k < 10; k++)
	{
		cin >> T;

		vector<int> v;
		int answer = 0;

		for (test_case = 1; test_case <= T; ++test_case)
		{
			int tmp;
			cin >> tmp;
			v.push_back(tmp);
		}

		for (int i = 2; i < v.size() - 2; i++)
		{
			int maxNum = -1;
			for (int j = -2; j <= 2; j++)
			{
				if (j == 0)
					continue;
				maxNum = max(maxNum, v[i + j]);
			}
			if (maxNum >= v[i])
				continue;
			else
				answer += (v[i] - maxNum);
		}
		cout << "#" << k + 1 << " " << answer << "\n";
	}
	return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}