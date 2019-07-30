#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;

	for (auto cmd : commands)
	{
		vector<int> copy(array);
		int s = cmd[0] - 1, e = cmd[1], at = cmd[2] - 1;

		std::sort(copy.begin() + s, copy.begin() + e);
        
		answer.emplace_back(copy[s + at]);
	}

	return answer;
}