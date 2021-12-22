#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";

	unordered_map<string, int> um;
	for (auto& i : participant) um[i]++;
	for (auto& i : completion) um[i]--;
	for (auto& i : um)
	{
		if (i.second > 0)
		{
			answer = i.first;
			break;
		}
	}

	return answer;
}