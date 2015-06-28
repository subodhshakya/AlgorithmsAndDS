/*
Given a directed graph, design an algorithm to find out whether there is a route between two nodes.
*/

#include<iostream>
#include<queue>

using namespace std;

#pragma region Explanation
/*
This problem can be solved by just simple graph traversal, such as depth first search or
breadth first search. We start with one of the two nodes and, during traversal, check if
the other node is found. We should mark any node found in the course of the algorithm
is 'already visited' to avoid cycles and repetition of the nodes.

Code used below provides an iterative implementation of breadth first search.
*/
#pragma endregion

const int MAX = 5;

bool isRoute(int a, int b, bool graph[][MAX])
{
	queue<int> Que;
	bool visited[MAX] = {false};
	Que.push(a);
	visited[a] = true;
	int tmp;
	while (!Que.empty())
	{
		tmp = Que.front();
		Que.pop();
		for (int i = 0; i < MAX; i++)
		{
			if (graph[tmp][i] && !visited[i])
			{
				if (b == i)
				{
					return true;
				}
				Que.push(i);
				visited[i] = true;
			}
		}
	}
	return false;
}

int main()
{
	bool graph[MAX][MAX] = {
		{ false, true, false, true, false},
		{ false, false, true, true, true },
		{ false, false, false, true, false },
		{ false, false, false, false, false },
		{ false, false, false, true, false }
	};
	if (isRoute(0, 2, graph))
	{
		cout << "There is a route!!!" << endl;
	}
	else
	{
		cout << "No route!!!" << endl;
	}
}

#pragma region discussion
/*
DFS => Easier to implement by using recursion but isn't good to find shortest path
BFS => It is better because it can find the shortest path even though it is harder to implement
*/
#pragma endregion