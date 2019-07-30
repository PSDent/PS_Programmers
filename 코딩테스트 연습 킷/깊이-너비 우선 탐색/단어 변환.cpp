#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

unordered_map<string, bool> wordsMap;
vector<char> letterList[10];

int minCnt = 99999999;

void DFS(string word, int depth, string target, unordered_map<string, bool> visited)
{
	if (depth > 0 && wordsMap.find(word) == wordsMap.end()) return;

	if (word == target) {
		minCnt = min(minCnt, depth);
		return;
	}

	if (visited.find(word) != visited.end()) return;
	visited.insert(make_pair(word, true));

	for (int i = 0; i < word.size(); ++i)
	{
		for (char letter = 'a'; letter <= 'z'; ++letter)
		{
			string tempWord(word);
			tempWord[i] = letter;
			DFS(tempWord, depth + 1, target, visited);
		}
	}
}

int solution(string begin, string target, vector<string> words) 
{
	for (auto word : words)
		wordsMap.insert(make_pair(word, false));

	unordered_map<string, bool> visited;
	DFS(begin, 0, target, visited);
	
	if (minCnt == 99999999)
		return 0;

	return minCnt;
}