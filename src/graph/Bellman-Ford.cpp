//#include <iostream>
//#include <vector>
//#include <cstdlib>
//#include <ctime>
//#include <unordered_set>
//#include <unordered_map>
//#include <queue>
//#include <stack>
//using namespace std;
//
//template <class T>
//struct Vertex
//{
//	T name;
//	vector<Vertex<T>*> neighbors;
//	vector<int> weights;
//	Vertex(T name)
//	{
//		this->name = name;
//	}
//	void addNeighbor(Vertex<T>* neighbor)
//	{
//		neighbors.push_back(neighbor);
//	}
//
//	void addNeighbor(Vertex<T>* neighbor, int weight)
//	{
//		neighbors.push_back(neighbor);
//		weights.push_back(weight);
//	}
//};
//
//vector<Vertex<char>*> CreateWeightedDirectedGraph()
//{
//	Vertex<char>* _0 = new Vertex<char>('0');
//	Vertex<char>* _1 = new Vertex<char>('1');
//	Vertex<char>* _2 = new Vertex<char>('2');
//	Vertex<char>* _3 = new Vertex<char>('3');
//	Vertex<char>* _4 = new Vertex<char>('4');
//	Vertex<char>* _5 = new Vertex<char>('5');
//	Vertex<char>* _6 = new Vertex<char>('6');
//	Vertex<char>* _7 = new Vertex<char>('7');
//	Vertex<char>* _8 = new Vertex<char>('8');
//	Vertex<char>* _9 = new Vertex<char>('9');
//
//	_0->addNeighbor(_1, 5);
//
//	_1->addNeighbor(_2, 20);
//	_1->addNeighbor(_5, 30);
//	_1->addNeighbor(_6, 60);
//
//	_2->addNeighbor(_3, 10);
//	_2->addNeighbor(_4, 75);
//
//	_3->addNeighbor(_2, -15);
//
//	_4->addNeighbor(_9, 100);
//
//	_5->addNeighbor(_4, 25);
//	_5->addNeighbor(_6, 5);
//	_5->addNeighbor(_8, 50);
//
//	_6->addNeighbor(_7, -50);
//
//	_7->addNeighbor(_8, -10);
//
//	vector<Vertex<char>*> graph;
//	graph.push_back(_0);
//	graph.push_back(_1);
//	graph.push_back(_2);
//	graph.push_back(_3);
//	graph.push_back(_4);
//	graph.push_back(_5);
//	graph.push_back(_6);
//	graph.push_back(_7);
//	graph.push_back(_8);
//	graph.push_back(_9);
//
//	return graph;
//}
//
//
//void BellmanFord_ShortestPath(vector<Vertex<char>*> weightedVertexes, Vertex<char>* start)
//{
//	unordered_map<Vertex<char>*, int> distanceMap;
//	for (Vertex<char>* v : weightedVertexes)
//		distanceMap[v] = INT32_MAX;
//	distanceMap[start] = 0;
//
//	int V = weightedVertexes.size();
//	// Relax all edges V-1 times
//	for (int i = 0; i < V - 1; i++)
//	{
//		for (Vertex<char>* current : weightedVertexes)
//		{
//			// Skip if current vertex is unreachable (overflow 방지)
//			if (distanceMap[current] == INT32_MAX)
//				continue;
//
//			for (size_t j = 0; j < current->neighbors.size(); j++)
//			{
//				Vertex<char>* neighbor = current->neighbors[j];
//				int weight = current->weights[j];
//				if (distanceMap[current] + weight < distanceMap[neighbor])
//					distanceMap[neighbor] = distanceMap[current] + weight;
//
//			}
//		}
//	}
//
//	// Detect and propagate negative cycles
//	for (int i = 0; i < V - 1; i++)
//	{
//		for (Vertex<char>* current : weightedVertexes)
//		{
//			// Skip if unreachable
//			if (distanceMap[current] == INT32_MAX)
//				continue;
//
//			// Process if current is affected by negative cycle OR has valid distance
//			for (size_t j = 0; j < current->neighbors.size(); j++)
//			{
//				Vertex<char>* neighbor = current->neighbors[j];
//				int weight = current->weights[j];
//
//				// If current is in negative cycle, propagate to all neighbors
//				if (distanceMap[current] == INT32_MIN)
//					distanceMap[neighbor] = INT32_MIN;
//
//				// Or if we can still relax, mark as negative cycle
//				else if (distanceMap[current] + weight < distanceMap[neighbor])
//					distanceMap[neighbor] = INT32_MIN;
//			}
//		}
//	}
//
//	//검증 완료
//	for (const auto& pair : distanceMap)
//	{
//		cout << "Distance from " << start->name << " to " << pair.first->name << " is ";
//		if (pair.second == INT32_MAX)
//			cout << "UNREACHABLE" << endl;
//		else if (pair.second == INT32_MIN)
//			cout << "NEGATIVE INFINITY (negative cycle)" << endl;
//		else
//			cout << pair.second << endl;
//	}
//}
//
//int main()
//{
//
//	vector<Vertex<char>*> weightedVertexes = CreateWeightedDirectedGraph();
//	BellmanFord_ShortestPath(weightedVertexes, weightedVertexes[0]);
//	system("pause");
//	return 0;
//}
