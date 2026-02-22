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
    T data;
    vector<Vertex<T>*> neighbors;
    Vertex(T data)
    {
        this->data = data;
    }
    void addNeighbor(Vertex<T>* neighbor)
    {
        neighbors.push_back(neighbor);
    }
};

void AddDirectedEdge(Vertex<int>* from, Vertex<int>* to)
{
    from->addNeighbor(to);
}

void AddUndirectedEdge(Vertex<int>* a, Vertex<int>* b)
{
    a->addNeighbor(b);
    b->addNeighbor(a);
}

vector<Vertex<int>*> CreateUndirectedGraph()
{
    Vertex<int>* _1 = new Vertex<int>(1);
    Vertex<int>* _2 = new Vertex<int>(2);
    Vertex<int>* _3 = new Vertex<int>(3);
    Vertex<int>* _4 = new Vertex<int>(4);
    Vertex<int>* _5 = new Vertex<int>(5);
    Vertex<int>* _6 = new Vertex<int>(6);
    Vertex<int>* _7 = new Vertex<int>(7);
    Vertex<int>* _8 = new Vertex<int>(8);

    AddUndirectedEdge(_1, _2);
    AddUndirectedEdge(_1, _4);
    AddUndirectedEdge(_1, _3);

    AddUndirectedEdge(_2, _3);

    AddUndirectedEdge(_3, _5);
    AddUndirectedEdge(_3, _4);

    AddUndirectedEdge(_4, _5);
    AddUndirectedEdge(_4, _8);

    AddUndirectedEdge(_5, _7);
    AddUndirectedEdge(_5, _6);

    vector<Vertex<int>*> graph;
    graph.push_back(_1);
    graph.push_back(_2);
    graph.push_back(_3);
    graph.push_back(_4);
    graph.push_back(_5);
    graph.push_back(_6);
    graph.push_back(_7);
    graph.push_back(_8);

    return graph;
}

vector<Vertex<int>*> CreateDirectedGraph()
{
    Vertex<int>* _1 = new Vertex<int>(1);
    Vertex<int>* _2 = new Vertex<int>(2);
    Vertex<int>* _3 = new Vertex<int>(3);
    Vertex<int>* _4 = new Vertex<int>(4);
    Vertex<int>* _5 = new Vertex<int>(5);
    Vertex<int>* _6 = new Vertex<int>(6);
    Vertex<int>* _7 = new Vertex<int>(7);
    Vertex<int>* _8 = new Vertex<int>(8);
    Vertex<int>* _9 = new Vertex<int>(9);
    Vertex<int>* _10 = new Vertex<int>(10);
    Vertex<int>* _11 = new Vertex<int>(11);

    AddDirectedEdge(_1, _2);
    AddDirectedEdge(_1, _3);
    AddDirectedEdge(_2, _3);
    AddDirectedEdge(_3, _10);
    AddDirectedEdge(_10, _11);

    AddDirectedEdge(_5, _7);
    AddDirectedEdge(_5, _6);

    AddDirectedEdge(_8, _9);

    vector<Vertex<int>*> graph;
    graph.push_back(_1);
    graph.push_back(_2);
    graph.push_back(_3);
    graph.push_back(_4);
    graph.push_back(_5);
    graph.push_back(_6);
    graph.push_back(_7);
    graph.push_back(_8);
    graph.push_back(_9);
    graph.push_back(_10);
    graph.push_back(_11);

    return graph;
}

void BFS(Vertex<int>* node)
{
    if (node == nullptr)
        return;

    unordered_set<Vertex<int>*> visited;
    queue<Vertex<int>*> queue;
    visited.insert(node);
    queue.push(node);

    while (queue.empty() == false)
    {
        Vertex<int>* current = queue.front();
        queue.pop();
        cout << current->data << " ";

        for (Vertex<int>* neighbor : current->neighbors)
        {
            if (visited.find(neighbor) == visited.end())
            {
                queue.push(neighbor);
                visited.insert(neighbor);
            }
        }
    }
    cout << endl;
}

void DFS(Vertex<int>* node, unordered_set<Vertex<int>*>& visited)
{
    visited.insert(node);
    cout << node->data << " ";

    for (Vertex<int>* neighbor : node->neighbors)
        if (visited.find(neighbor) == visited.end())
            DFS(neighbor, visited);
}

void DFS(Vertex<int>* node)
{
    if (node == nullptr)
        return;

    unordered_set<Vertex<int>*> visited;
    DFS(node, visited);
    cout << endl;
}

void findConnectedComponents(vector<Vertex<int>*> vertexes)
{
    int count = 0;
    unordered_set<Vertex<int>*> visited;
    for (Vertex<int>* v : vertexes)
    {
        if (visited.find(v) == visited.end())
        {
            count++;
            DFS(v, visited);
            cout << endl;
        }
    }
    cout << "there are " << count << " connected components" << endl;
}

//Using BFS
void findShortestPathInUnweightedGraph(vector<Vertex<int>*> vertexes, Vertex<int>* start, Vertex<int>* end)
{
    unordered_set<Vertex<int>*> visited;
    queue<Vertex<int>*> queue;
    unordered_map<Vertex<int>*, Vertex<int>*> previous;
    visited.insert(start);
    queue.push(start);

    while (queue.empty() == false)
    {
        Vertex<int>* current = queue.front();
        queue.pop();
        for (Vertex<int>* neighbor : current->neighbors)
        {
            if (visited.find(neighbor) == visited.end())//not found
            {
                previous[neighbor] = current;
                queue.push(neighbor);
                visited.insert(neighbor);
            }
        }
    }

    cout << "shorted path from " << start->data << " to " << end->data << " : ";
    Vertex<int>* current = end;
    stack<Vertex<int>*> paths;
    paths.push(current);
    while (current != start)
    {
        if (previous.find(current) == previous.end())//not found
        {
            cout << "no path" << endl;
            return;
        }
        paths.push(previous[current]);
        current = previous[current];
    }

    while (paths.empty() == false)
    {
        Vertex<int>* c = paths.top();
        paths.pop();
        if (c != end)
            cout << c->data << " -> ";
        else
            cout << c->data << endl;
    }
}

int main()
{
    vector<Vertex<int>*> vertexes = CreateDirectedGraph();
    findConnectedComponents(vertexes);
    cout << endl;
    findShortestPathInUnweightedGraph(vertexes, vertexes.front(), vertexes.back());
    findShortestPathInUnweightedGraph(vertexes, vertexes.front(), vertexes[5]);
    findShortestPathInUnweightedGraph(vertexes, vertexes[4], vertexes[5]);

    system("pause");
    return 0;
}
*/