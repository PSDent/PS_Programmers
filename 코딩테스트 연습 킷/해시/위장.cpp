#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> clothesCounts;

int solution(vector<vector<string>> clothes) {
	int answer = 1;
	unordered_map<string, int> clotheTypes;

	for (auto clothe : clothes)
	{
		if (clotheTypes[clothe[1]])
			++clotheTypes[clothe[1]];
		else
			clotheTypes[clothe[1]] = 1;
	}

	for (auto type : clotheTypes)
		answer *= (type.second + 1);

	return answer - 1;
}