#include <string>
#include <vector>
#include <queue>

using namespace std;

using Document = pair<int, int>;

int solution(vector<int> priorities, int location) {
	int answer = 0;

	queue<Document> printer;
	priority_queue<int> priority;

	for (int i = 0; i < priorities.size(); ++i)
	{
		printer.push(make_pair(priorities[i], i));
		priority.push(priorities[i]);
	}

	while (!printer.empty())
	{
		if (printer.front().first == priority.top())
		{
			if (printer.front().second == location)
				return priorities.size() - printer.size() + 1;
			printer.pop(), priority.pop();
		}
		else
		{
			Document temp = printer.front();
			printer.pop();
			printer.push(temp);
			
		}
	}

	return answer;
}