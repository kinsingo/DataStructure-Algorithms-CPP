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



vector<Vertex<char>*> CreateDirectedGraph()
{
	Vertex<char>* A = new Vertex<char>('A');
	Vertex<char>* B = new Vertex<char>('B');
	Vertex<char>* C = new Vertex<char>('C');
	Vertex<char>* D = new Vertex<char>('D');
	Vertex<char>* E = new Vertex<char>('E');
	Vertex<char>* F = new Vertex<char>('F');
	Vertex<char>* G = new Vertex<char>('G');
	Vertex<char>* H = new Vertex<char>('H');
	Vertex<char>* I = new Vertex<char>('I');
	Vertex<char>* J = new Vertex<char>('J');
	Vertex<char>* K = new Vertex<char>('K');

	//
	//Graph Structure (Directed):
	//
	//          A
	//         /\
	//        /  \
	//       v    v
	//       B    D
	//       |   / \
	//       |  /   \
	//       v v     v
	//        E      F <--- C
	//      / \     / \
	//     /   \   /   \
	//    v     v v     v
	//    H      G ----> I
	//     \   /
	//      \ /
	//       v
	//       J      K (isolated vertex)
	//
	//Edge List:
	//A -> B, D
	//B -> E
	//C -> F
	//D -> E, F
	//E -> H, G
	//F -> G, I
	//G -> J, I
	//H -> J
	//I -> (none)
	//J -> (none)
	//K -> (none)
	//

	A->addNeighbor(B);
	A->addNeighbor(D);

	B->addNeighbor(E);

	C->addNeighbor(F);

	D->addNeighbor(E);
	D->addNeighbor(F);

	E->addNeighbor(H);
	E->addNeighbor(G);

	F->addNeighbor(G);
	F->addNeighbor(I);

	G->addNeighbor(J);
	G->addNeighbor(I);

	H->addNeighbor(J);


	vector<Vertex<char>*> graph;
	graph.push_back(A);
	graph.push_back(B);
	graph.push_back(C);
	graph.push_back(D);
	graph.push_back(E);
	graph.push_back(F);
	graph.push_back(G);
	graph.push_back(H);
	graph.push_back(I);
	graph.push_back(J);
	graph.push_back(K);

	return graph;
}

//Including Minus Edge
vector<Vertex<char>*> CreateWeightedDirectedGraph()
{
	Vertex<char>* A = new Vertex<char>('A');
	Vertex<char>* B = new Vertex<char>('B');
	Vertex<char>* C = new Vertex<char>('C');
	Vertex<char>* D = new Vertex<char>('D');
	Vertex<char>* E = new Vertex<char>('E');
	Vertex<char>* F = new Vertex<char>('F');
	Vertex<char>* G = new Vertex<char>('G');
	Vertex<char>* H = new Vertex<char>('H');


	//
	// Simplified Layout:
	//
	//              A
	//             / \
	//          3 /   \ 6
	//           /     \
	//          v   4   v
	//          B ----> C
	//         /\     / \
	//      11/  \4  /8  \ 11
	//       /    \ /     \
	//      v  -4  vv   2  v
	//      E <---  D  ---> G
	//       \      |5     /
	//        \     v     /
	//        9\    F    /2
	//          \   |   /
	//           \  |1 /
	//            \ | /
	//             vvv
	//              H
	//



	A->addNeighbor(B, 3);
	A->addNeighbor(C, 6);

	B->addNeighbor(C, 4);
	B->addNeighbor(D, 4);
	B->addNeighbor(E, 11);

	C->addNeighbor(D, 8);
	C->addNeighbor(G, 11);

	D->addNeighbor(E, -4);
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

void TopologicalSort(Vertex<char>* v, unordered_set<Vertex<char>*>& visited, stack<Vertex<char>*>& stack)
{
	visited.insert(v);

	for (Vertex<char>* neighbor : v->neighbors)
		if (visited.find(neighbor) == visited.end())
			TopologicalSort(neighbor, visited, stack);

	stack.push(v);
}

vector<Vertex<char>*> TopologicalSort(vector<Vertex<char>*> vertexes)
{
	unordered_set<Vertex<char>*> visited;
	stack<Vertex<char>*> stack;

	for (Vertex<char>* v : vertexes)
		if (visited.find(v) == visited.end())
			TopologicalSort(v, visited, stack);

	vector<Vertex<char>*> topOrderedVertexes;
	cout << "TOP Sort : ";
	while (stack.empty() == false)
	{
		Vertex<char>* node = stack.top();
		topOrderedVertexes.push_back(node);
		cout << node->name << " ";
		stack.pop();
	}
	cout << endl;

	return topOrderedVertexes;
}

void FindShortestDistances(vector<Vertex<char>*> weightedVertexes)
{
	vector<Vertex<char>*> topOrderedVertexes = TopologicalSort(weightedVertexes);
	Vertex<char>* start = topOrderedVertexes[0];
	unordered_map<Vertex<char>*, int> distanceMap;
	for (Vertex<char>* v : topOrderedVertexes)
		distanceMap[v] = INT32_MAX;//나머지 distance 는 max 로
	distanceMap[start] = 0;//시작 node 는 distance 0 으로

	for (Vertex<char>* current : topOrderedVertexes)
	{
		for (int j = 0; j < current->neighbors.size(); j++)
		{
			Vertex<char>* neighbor = current->neighbors[j];
			int weight = current->weights[j];
			int newDistance = (weight + distanceMap[current]);

			if (distanceMap[neighbor] > newDistance)
				distanceMap[neighbor] = newDistance;
		}
	}

	for (auto result : distanceMap)
	{
		Vertex<char>* v = result.first;
		int d = result.second;
		cout << v->name << " : " << d << endl;
	}
}

void FindLongestDistances(vector<Vertex<char>*> weightedVertexes)
{
	vector<Vertex<char>*> topOrderedVertexes = TopologicalSort(weightedVertexes);
	Vertex<char>* start = topOrderedVertexes[0];
	unordered_map<Vertex<char>*, int> distanceMap;
	for (Vertex<char>* v : topOrderedVertexes)
		distanceMap[v] = INT32_MIN;//나머지 distance 는 min 으로
	distanceMap[start] = 0;//시작 node 는 distance 0 으로

	for (Vertex<char>* current : topOrderedVertexes)
	{
		for (int j = 0; j < current->neighbors.size(); j++)
		{
			Vertex<char>* neighbor = current->neighbors[j];
			int weight = current->weights[j];
			int newDistance = (weight + distanceMap[current]);

			//if (distanceMap[neighbor] > newDistance)
			if (distanceMap[neighbor] < newDistance)
				distanceMap[neighbor] = newDistance;
		}
	}

	for (auto result : distanceMap)
	{
		Vertex<char>* v = result.first;
		int d = result.second;
		cout << v->name << " : " << d << endl;
	}
}


int main()
{
	vector<Vertex<char>*> vertexes = CreateDirectedGraph();
	TopologicalSort(vertexes);

	vector<Vertex<char>*> weightedVertexes = CreateWeightedDirectedGraph();

	cout << endl << "shortest distances" << endl;
	FindShortestDistances(weightedVertexes);

	cout << endl << "longest distances" << endl;
	FindLongestDistances(weightedVertexes);

	system("pause");
	return 0;
}
*/