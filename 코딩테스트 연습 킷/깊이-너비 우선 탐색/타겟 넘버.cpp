#include <string>
#include <vector>

using namespace std;

int targetVal, cnt;
vector<int> *pNumbers;

void DFS(int val, int nextPos)
{
	if (nextPos == pNumbers->size())
	{
		if (val == targetVal) ++cnt;
		return;
	}

	DFS(val + (*pNumbers)[nextPos], nextPos + 1);
	DFS(val - (*pNumbers)[nextPos], nextPos + 1);
}

int solution(vector<int> numbers, int target) {
	int answer = 0;
	targetVal = target;
	pNumbers = &numbers;

	DFS(numbers[0], 1);
	DFS(-numbers[0], 1);

	answer = cnt;
	return answer;
}