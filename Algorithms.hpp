//324815083
//cohen.shirel098@gmail.com
//

#include <iostream>
#include <vector>
#include "Graph.hpp"
namespace ariel{
class Algorithms{

    public:
    static int isConnected(Graph& g);
    static vector<int> shortestPath(Graph& g, size_t a, size_t b);
    static int isContainsCycle(Graph& g);
    static vector<vector<int>> isBipartite(Graph& g);
    static vector<int> negativeCycle(Graph& g);

    private:
    static void dfs(size_t n, Graph& g, vector<int>& v);
    static Graph reverseEdges(Graph& g);
    static int bellmanFord(Graph& g, vector<int>& a, vector<int>& b);
    static int hasCycleDFS(Graph& g, size_t n, vector<bool>& v, vector<bool>&);
};
}
