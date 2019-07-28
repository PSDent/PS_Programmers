#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
using TruckInfo = pair<int, int>; // 무게, 탈출 시간

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0, nowTime = 0;

	queue<int> truckQ;
	queue<TruckInfo> bridgeQ;
	for (auto truck : truck_weights)
		truckQ.push(truck);

	while (!truckQ.empty() || !bridgeQ.empty())
	{
		if (!bridgeQ.empty() && bridgeQ.front().second == answer)
		{
			weight += bridgeQ.front().first;
			bridgeQ.pop();
		}

		if (!truckQ.empty() && (weight - truckQ.front()) >= 0)
		{
			weight -= truckQ.front();
			bridgeQ.push(make_pair(truckQ.front(), answer + bridge_length));
			truckQ.pop();
		}

		++answer;
	}

	return answer;
}
