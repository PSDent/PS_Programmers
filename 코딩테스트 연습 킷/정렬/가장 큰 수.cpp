#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const int& left, const int& right)
{
	string leftStr = to_string(left), rightStr = to_string(right);

	return stoi(leftStr + rightStr) > stoi(rightStr + leftStr);
}

string solution(vector<int> numbers) {
	string answer = "";

	sort(numbers.begin(), numbers.end(), cmp);

	if (numbers[0] == 0) return "0";

	for (auto num : numbers)
		answer += to_string(num);

	return answer;
}