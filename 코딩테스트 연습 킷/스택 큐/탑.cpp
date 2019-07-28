#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

using Tower = pair<int, int>;

vector<int> solution(vector<int> heights) {
	vector<int> answer;

	stack<Tower> leftStack, rightStack;

	for (int i = 0; i < heights.size(); ++i)
		leftStack.emplace(make_pair(heights[i], i));

	while (!leftStack.empty())
	{
		rightStack.push(leftStack.top());
		leftStack.pop();

		while (!rightStack.empty())
		{
			if (leftStack.empty()) break;

			if (rightStack.top().first < leftStack.top().first)
			{
				answer.emplace_back(leftStack.top().second + 1);
				rightStack.pop();
			}
			else
				break;
		}
	}

	reverse(answer.begin(), answer.end());
	while (!rightStack.empty())
	{
		answer.insert(answer.begin() + rightStack.top().second, 0);
		rightStack.pop();
	}
	return answer;
}
