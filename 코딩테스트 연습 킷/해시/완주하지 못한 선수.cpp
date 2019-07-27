#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	map<string, int> check;

	for (auto name : participant)
		++check[name];
	for (auto name : completion)
	{
		--check[name];
        if(check[name] == 0)
		    check.erase(name);
	}
	answer = check.begin()->first;

	return answer;
}