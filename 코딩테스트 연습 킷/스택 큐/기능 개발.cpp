#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	queue<int*> featuresQ;

	for (int i = 0; i < progresses.size(); ++i)
		featuresQ.push(&progresses[i]);

	int startPos = 0;
	while (!featuresQ.empty())
	{
		for (int i = startPos; i < progresses.size(); ++i)
			progresses[i] += speeds[i];

		if (*featuresQ.front() >= 100)
		{
			int cnt = 0;
			while (!featuresQ.empty() && *featuresQ.front() >= 100)
			{
				featuresQ.pop();
				++cnt, ++startPos;
			}
			answer.push_back(cnt);
		}
	}

	return answer;
}
