#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	priority_queue<int, vector<int>, greater<int>> foods;

	for (auto food : scoville)
		foods.push(food);

	while (foods.top() < K)
	{
		if (foods.size() <= 1) return -1;

		int newFood = foods.top(); foods.pop();
		newFood += foods.top() * 2; foods.pop();
		foods.push(newFood);
		++answer;
	}

	return answer;
}