#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
// Data structure to store a graph edge
struct Edge {
    int src, dest;
};
 
// A class to represent a graph object
class Graph
{
public:
    // a vector of vectors to represent an adjacency list
    vector<vector<int>> adjList;
 
    // Graph Constructor
    Graph(vector<Edge> const &edges, int N)
    {
        // resize the vector to hold `N` elements of type `vector<int>`
        adjList.resize(N);
 
        // add edges to the undirected graph
        for (auto &edge: edges)
        {
            adjList[edge.src].push_back(edge.dest);
            adjList[edge.dest].push_back(edge.src);
        }
    }
};
 
// Perform BFS on the graph starting from vertex `v`
bool BFS(Graph const &graph, int v, int N)
{
    // to keep track of whether a vertex is discovered or not
    vector<bool> discovered(N);
 
    // stores the level of each vertex in BFS
    vector<int> level(N);
 
    // mark the source vertex as discovered and
    // set its level to 0
    discovered[v] = true, level[v] = 0;
 
    // create a queue to do BFS and enqueue
    // source vertex in it
    queue<int> q;
    q.push(v);
 
    // loop till queue is empty
    while (!q.empty())
    {
        // dequeue front node
        v = q.front();
        q.pop();
 
        // do for every edge `v —> u`
        for (int u: graph.adjList[v])
        {
            // if vertex `u` is explored for the first time
            if (!discovered[u])
            {
                // mark it as discovered
                discovered[u] = true;
 
                // set level one more than the level of the parent node
                level[u] = level[v] + 1;
 
                // enqueue vertex
                q.push(u);
            }
            // if the vertex has already been discovered and the
            // level of vertex `u` and `v` are the same, then the
            // graph contains an odd-cycle and is not bipartite
            else if (level[v] == level[u]) {
                return false;
            }
        }
    }
 
    return true;
}
 
int main()
{
    // vector of graph edges as per the above diagram
    vector<Edge> edges = {
        {1, 2}, {2, 3}, {2, 8}, {3, 4}, {4, 6}, {5, 7},
        {5, 9}, {8, 9}
        // if we add edge `2 —> 4`, the graph becomes non-bipartite
    };
 
    // total number of nodes in the graph
    int N = 10;
 
    // build a graph from the given edges
    Graph graph(edges, N);
 
    // Perform BFS traversal starting from vertex 1
    if (BFS(graph, 1, N)) {
        cout << "The graph is bipartite";
    }
    else {
        cout << "The graph is not bipartite";
    }
 
    return 0;
}


