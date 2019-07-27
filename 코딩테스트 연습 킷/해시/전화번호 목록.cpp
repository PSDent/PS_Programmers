#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;

	unordered_map<string, bool> prefixs;
	for (auto phoneNum : phone_book)
	{
		if (prefixs.find(phoneNum) != prefixs.end()) return false;

		string str = "";
		for (int i = 0; i < phoneNum.size() - 1; ++i)
		{
			str += phoneNum[i];
			prefixs[str] = true;
		}
	}

	for (auto phoneNum : phone_book)
		if (prefixs.find(phoneNum) != prefixs.end()) return false;

	return answer;
}