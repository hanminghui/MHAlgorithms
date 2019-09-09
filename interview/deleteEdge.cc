// C++ program to check if removing an 
// edge disconnects a graph or not. 
#include<bits/stdc++.h> 
using namespace std; 
  
// Graph class represents a directed graph 
// using adjacency list representation 
class Graph 
{ 
    int V;    // No. of vertices 
    list<int> *adj; 
    void DFS(int v, bool visited[]); 
public: 
    Graph(int V);   // Constructor 
  
    // function to add an edge to graph 
    void addEdge(int v, int w); 
  
    // Returns true if graph is connected 
    bool isConnected(); 
  
    bool isBridge(int u, int v); 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int u, int v) 
{ 
    adj[u].push_back(v); // Add w to v’s list. 
    adj[v].push_back(u); // Add w to v’s list. 
} 
  
void Graph::DFS(int v, bool visited[]) 
{ 
    // Mark the current node as visited and print it 
    visited[v] = true; 
  
    // Recur for all the vertices adjacent to 
    // this vertex 
    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (!visited[*i]) 
            DFS(*i, visited); 
} 
  
// Returns true if given graph is connected, else false 
bool Graph::isConnected() 
{ 
    bool visited[V]; 
    memset(visited, false, sizeof(visited)); 
  
    // Find all reachable vertices from first vertex 
    DFS(0, visited); 
  
    // If set of reachable vertices includes all, 
    // return true. 
    for (int i=1; i<V; i++) 
       if (visited[i] == false) 
           return false; 
  
    return true; 
} 
  
// This function assumes that edge (u, v) 
// exists in graph or not, 
bool Graph::isBridge(int u, int v) 
{ 
    // Remove edge from undirected graph 
    adj[u].remove(v); 
    adj[v].remove(u); 
  
    bool res = isConnected(); 
  
    // Adding the edge back 
    addEdge(u, v); 
  
    // Return true if graph becomes disconnected 
    // after removing the edge. 
    return (res == false); 
} 

vector<pair<int,int>> criticalConnections(int numOfServers,
		int numOfConnections,
		vector<pair<int,int>> connections)
{
	vector<pair<int, int>> result;
	if(numOfServers == 0 || numOfConnections == 0 || connections.empty())
		return result;
	Graph g(numOfServers);
	for(auto c : connections)
	{
		g.addEdge(c.first-1, c.second-1);
	}
	for(auto c : connections)
	{
		if(g.isBridge(c.first-1, c.second-1))
		{
			result.push_back(pair<int,int> (c.first, c.second));
		}
	}
	return result;
}
  
// Driver code 
int main() 
{ 
	int numOfServers = 5;
	int numOfConnections = 5;
	vector<pair<int,int>> connections;
	connections.push_back(pair<int,int> (1,2));
	connections.push_back(pair<int,int> (1,3));
	connections.push_back(pair<int,int> (2,3));
	connections.push_back(pair<int,int> (1,4));
	connections.push_back(pair<int,int> (4,5));
	vector<pair<int,int>> key;
	key = criticalConnections(numOfServers, numOfConnections,
			connections);
	for(auto k : key)
	{
		std::cout << k.first << "," << k.second << std::endl;
	}
  
    return 0; 
} 
