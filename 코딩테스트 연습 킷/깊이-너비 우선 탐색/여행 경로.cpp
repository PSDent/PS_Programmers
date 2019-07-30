#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

int totalCnt = 0;
unordered_map<string, vector<string>> airports;
vector<string> answers;

void DFS(string ticket, string path, int cnt, unordered_map<string, bool> &visited)
{
	if (cnt == totalCnt)
	{
		answers.push_back(path + ',' + ticket);
		return;
	}

	if (airports.find(ticket) == airports.end()) return;

	auto v = airports[ticket];
	for (int i = 0; i < v.size(); ++i)
	{
		string nextTicket = v[i];
		if (visited.find(ticket + nextTicket + to_string(i)) != visited.end()) continue;

		visited.insert(make_pair(ticket + nextTicket + to_string(i), true));
		DFS(nextTicket, path + ',' + ticket, cnt + 1, visited);
		visited.erase(ticket + nextTicket + to_string(i));
	}
}

vector<string> solution(vector<vector<string>> tickets) {
	vector<string> answer;

	for (auto ticket : tickets)
	{		
		++totalCnt;
		if (airports.find(ticket[0]) == airports.end())
			airports.insert(make_pair(ticket[0], vector<string>()));
		airports[ticket[0]].push_back(ticket[1]);
	}

	unordered_map<string, bool> visited;
	DFS("ICN", "", 0, visited);

	sort(answers.begin(), answers.end(), less<string>());
	istringstream iss(answers[0]);
	string token;

	getline(iss, token, ',');
	while (getline(iss, token, ','))
		answer.push_back(token);

	return answer;
}