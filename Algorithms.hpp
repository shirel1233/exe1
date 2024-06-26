#include <iostream>
#include <vector>
#include "Graph.hpp"
namespace ariel{
class Algorithms{
    public:
    static int isConnected(Graph);
    static vector<int> shortestPath(Graph,int,int);
    static int isContainsCycle(Graph);
    static vector<vector<int> > isBipartite(Graph);
    static vector<int> negativeCycle(Graph);
    //static void dfs(int, vector<vector<int> >, std::vector<bool>&);
    static void dfs(int, vector<vector<int> >, vector<bool>&);

    static vector<vector<int> > reverseEdges(Graph&);
    static int bellmanFord(Graph& , vector<int>&, vector<int>&);
    static int hasCycleDFS(Graph&, int, vector<bool>&,vector<bool>&);
};
}
