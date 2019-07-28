#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int cnt[3];

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	int pick[3][10] = { {1, 2, 3, 4, 5}, {2, 1, 2, 3, 2, 4, 2, 5}, {3, 3, 1, 1, 2, 2, 4, 4, 5, 5} };
	int pos1 = 0, pos2 = 0, pos3 = 0;

	for (auto ans : answers)
	{
		pos1 %= 5; pos2 %= 8; pos3 %= 10;

		if (pick[0][pos1] == ans) ++cnt[0];
		if (pick[1][pos2] == ans) ++cnt[1];
		if (pick[2][pos3] == ans) ++cnt[2];
		++pos1, ++pos2, ++pos3;
	}

	int maxVal = max(cnt[0], max(cnt[1], cnt[2]));
	for (int i = 0; i < 3; ++i)
		if (cnt[i] == maxVal)
			answer.push_back(i + 1);

	return answer;
}