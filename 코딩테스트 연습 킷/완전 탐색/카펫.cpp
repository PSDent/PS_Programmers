#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {
	vector<int> answer;

	for (int i = 3;; ++i)
	{
		for (int j = 3; j <= i; ++j)
		{
			if (i * j > brown + red) break;

			if (i * 2 + (j - 2) * 2 == brown && brown + red == i * j)
			{
				answer.push_back(i);
				answer.push_back(j);
				return answer;
			}

		}
	}

	return answer;
}