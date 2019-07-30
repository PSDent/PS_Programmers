#include <string>
#include <vector>
#include <queue>

using namespace std;

bool visited[200];

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;

	for (int i = 0; i < n; ++i)
	{
		if (visited[i]) continue;
		visited[i] = true;

		queue<int> nodesQ;
		nodesQ.push(i);
		while (!nodesQ.empty())
		{
			int nowIdx = nodesQ.front(); nodesQ.pop();

			for (int j = 0; j < n; ++j)
			{
				if (!visited[j] && computers[nowIdx][j])
				{
					nodesQ.push(j);
					visited[j] = true;
				}
			}
		}

		++answer;
	}

	return answer;
}