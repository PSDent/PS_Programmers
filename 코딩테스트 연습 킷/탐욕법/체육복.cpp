#include <string>
#include <vector>
#include <cstring>

using namespace std;

int gymSuit[31];

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;

	for (int i = 1; i <= n; ++i)
		gymSuit[i] = 1;
	for (auto lostStudent : lost)
		--gymSuit[lostStudent];
	for (auto reserveStudent : reserve)
		++gymSuit[reserveStudent];

	for (int i = 1; i <= n; ++i)
	{
		if (gymSuit[i] == 2)
		{
			if (i - 1 >= 1 && gymSuit[i - 1] == 0)
			{
				gymSuit[i] = 1;
				gymSuit[i - 1] = 1;
			}
			else if (i + 1 <= n && gymSuit[i + 1] == 0)
			{
				gymSuit[i] = 1;
				gymSuit[i + 1] = 1;
			}
		}
	}

	for (int i = 1; i <= n; ++i)
		if (gymSuit[i])
			++answer;

	return answer;
}