#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

struct Node
{
	vector<int> next;
};

int preorder(vector<Node> nodes, vector<bool>* visited, int num)
{
	int res = 0;
	(*visited)[num] = true;

	for (int i = 0; i < nodes[num].next.size(); i++)
	{
		if ((*visited)[nodes[num].next[i]]) continue;
		res += preorder(nodes, visited, nodes[num].next[i]);
	}

	return ++res;
}

int solution(int n, vector<vector<int>> wires) {
	int answer = 100;

	vector<Node> nodes(n);

	for (int i = 0; i < wires.size(); i++)
	{
		nodes[wires[i][0] - 1].next.push_back(wires[i][1] - 1);
		nodes[wires[i][1] - 1].next.push_back(wires[i][0] - 1);
	}

	for (int i = 0; i < wires.size(); i++)
	{
		int a = wires[i][0] - 1;
		int b = wires[i][1] - 1;

		vector<bool> visited(n, 0);
		visited[a] = true;
		visited[b] = true;

		int a_count = preorder(nodes, &visited, a);
		int b_count = preorder(nodes, &visited, b);

		int res = abs(a_count - b_count);
		if (answer > res) answer = res;
	}

	return answer;
}