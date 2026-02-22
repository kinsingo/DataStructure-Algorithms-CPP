/*
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

template <class T>
struct Vertex
{
	T name;
	vector<Vertex<T>*> neighbors;
	vector<int> weights;
	Vertex(T name)
	{
		this->name = name;
	}
	void addNeighbor(Vertex<T>* neighbor)
	{
		neighbors.push_back(neighbor);
	}

	void addNeighbor(Vertex<T>* neighbor, int weight)
	{
		neighbors.push_back(neighbor);
		weights.push_back(weight);
	}
};

vector<Vertex<char>*> CreatePositiveWeightedDirectedGraph()
{
	Vertex<char>* A = new Vertex<char>('A');
	Vertex<char>* B = new Vertex<char>('B');
	Vertex<char>* C = new Vertex<char>('C');
	Vertex<char>* D = new Vertex<char>('D');
	Vertex<char>* E = new Vertex<char>('E');
	Vertex<char>* F = new Vertex<char>('F');
	Vertex<char>* G = new Vertex<char>('G');
	Vertex<char>* H = new Vertex<char>('H');

	
	 // Simplified Layout:
	 //
	 //             A
	 //            / \
	 //         3 /   \ 6
	 //          /     \
	 //         v   4   v
	 //         B ----> C
	 //        /\     / \
	 //     11/  \4  /8  \ 11
	 //      /    \ /     \
	 //     v  +4  vv   2  v
	 //     E <---  D  ---> G
	 //      \      |5     /
	 //       \     v     /
	 //       9\    F    /2
	 //         \   |   /
	 //          \  |1 /
	 //           \ | /
	 //            vvv
	 //             H
	



	A->addNeighbor(B, 3);
	A->addNeighbor(C, 6);

	B->addNeighbor(C, 4);
	B->addNeighbor(D, 4);
	B->addNeighbor(E, 11);

	C->addNeighbor(D, 8);
	C->addNeighbor(G, 11);

	D->addNeighbor(E, 4);//D->addNeighbor(E, -4);
	D->addNeighbor(F, 5);
	D->addNeighbor(G, 2);

	E->addNeighbor(H, 9);

	F->addNeighbor(H, 1);

	G->addNeighbor(H, 2);

	vector<Vertex<char>*> graph;
	graph.push_back(A);
	graph.push_back(B);
	graph.push_back(C);
	graph.push_back(D);
	graph.push_back(E);
	graph.push_back(F);
	graph.push_back(G);
	graph.push_back(H);

	return graph;
}

void DisplayInfo(Vertex<char>* node, unordered_map<Vertex<char>*, int> distanceMap, unordered_map<Vertex<char>*, Vertex<char>*> previousMap)
{
	cout << node->name << ":" << distanceMap[node];
	if (previousMap.find(node) == previousMap.end())
		cout << endl;
	else
	{
		cout << "(";
		while (previousMap.find(node) != previousMap.end())
		{
			cout << " <- " << previousMap[node]->name;
			node = previousMap[node];
		}
		cout << ")" << endl;
	}
}

void DijkstraShortestDistances(vector<Vertex<char>*> weightedVertexes, Vertex<char>* start, Vertex<char>* end = nullptr)
{
	priority_queue<pair<int, Vertex<char>*>,
		vector<pair<int, Vertex<char>*>>,
		greater<pair<int, Vertex<char>*>>> minHeap;

	unordered_map<Vertex<char>*, int> distanceMap;
	unordered_set<Vertex<char>*> visited;
	unordered_map<Vertex<char>*, Vertex<char>*> previousMap;

	for (Vertex<char>* v : weightedVertexes)
		distanceMap[v] = INT32_MAX;
	distanceMap[start] = 0;

	minHeap.push({ distanceMap[start], start });

	while (minHeap.empty() == false)
	{
		if (visited.find(end) != visited.end())
			break; //최종 목적지 도달, 다른곳 더 알아볼 필요 없음

		pair<int, Vertex<char>*> node = minHeap.top();
		minHeap.pop();
		int current_distance = node.first;
		Vertex<char>* current = node.second;

		// Skip if already processed
		if (visited.find(current) != visited.end())
			continue;

		// Skip outdated distance information
		if (current_distance > distanceMap[current])
			continue;

		for (int j = 0; j < current->neighbors.size(); j++)
		{
			Vertex<char>* neighbor = current->neighbors[j];
			int weight = current->weights[j];
			int newDistance = current_distance + weight;
			if (distanceMap[neighbor] > newDistance)
			{
				previousMap[neighbor] = current;
				distanceMap[neighbor] = newDistance;
				minHeap.push({ newDistance, neighbor });
			}
		}

		visited.insert(current);
	}


	if (end)
	{
		Vertex<char>* node = end;
		DisplayInfo(node, distanceMap, previousMap);
	}
	else
	{
		for (Vertex<char>* node : weightedVertexes)
			DisplayInfo(node, distanceMap, previousMap);
	}
}


int main()
{
	vector<Vertex<char>*> weightedVertexes = CreatePositiveWeightedDirectedGraph();
	Vertex<char>* A = weightedVertexes[0];
	Vertex<char>* D = weightedVertexes[3];
	Vertex<char>* H = weightedVertexes.back();

	DijkstraShortestDistances(weightedVertexes, A);
	cout << endl;
	DijkstraShortestDistances(weightedVertexes, A, D);
	cout << endl;
	DijkstraShortestDistances(weightedVertexes, A, H);
	cout << endl;
	DijkstraShortestDistances(weightedVertexes, D);
	cout << endl;

	system("pause");
	return 0;
}
*/