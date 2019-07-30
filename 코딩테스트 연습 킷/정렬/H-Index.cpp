#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
	int answer = 0;

	sort(citations.begin(), citations.end(), greater<int>());

	for (int h = 0; h <= citations[0]; ++h)
	{
		int i = 0, len = citations.size();
		for (i; i < len; ++i)
			if (citations[i] < h)
				break;

		if (i >= h && len - i <= h)
			answer = h;
	}

	return answer;
}