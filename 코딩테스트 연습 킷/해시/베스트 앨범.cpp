#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

using AlbumPair = std::pair<string, int>;

std::vector<int> g_plays;

bool cmp(const AlbumPair& left, const AlbumPair& right)
{
	if (left.second > right.second)
		return true;
	else
		return false;
}

bool MusicCmp(const int& left, const int& right)
{
	if (g_plays[left] > g_plays[right])
		return true;
	else if (g_plays[left] == g_plays[right])
	{
		if (left < right)
			return true;
		else
			return false;
	}
	else
		return false;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;

	g_plays = plays;

	std::unordered_map<string, int> genreCnt;
	std::unordered_map<string, std::vector<int>> musicList;

	for (int i = 0; i < genres.size(); ++i)
	{
		if (genreCnt.find(genres[i]) == genreCnt.end())
			genreCnt[genres[i]] = plays[i];
		else
			genreCnt[genres[i]] += plays[i];
		musicList[genres[i]].emplace_back(i);
	}

	std::vector<AlbumPair> cntVector;
	for (auto album : genreCnt)
		cntVector.emplace_back(album);

	std::sort(cntVector.begin(), cntVector.end(), cmp);
	for (auto music : cntVector)
		std::sort(musicList[music.first].begin(), musicList[music.first].end(), MusicCmp);

	for (auto album : cntVector)
	{
		std::vector<int>& music = musicList[album.first];
		answer.emplace_back(music[0]);
		if (music.size() > 1)
			answer.emplace_back(music[1]);
	}

	return answer;
}