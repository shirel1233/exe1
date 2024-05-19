//324815083
//cohen.shirel098@gmail.com
#include <iostream>
#include <vector>
#include "Graph.hpp"
namespace ariel{
class Algorithms{
    public:
    using IndexType= typename std:: vector<int>::size_type;
    static int isConnected(Graph);
    static vector<int> shortestPath(Graph,int,int);
    static int isContainsCycle(Graph);
    static vector<vector<int>> isBipartite(Graph);
    static vector<int> negativeCycle(Graph);
    static void dfs(IndexType, std::vector<std::vector<int>>&, std::vector<int>&);

    static vector<vector<int>> reverseEdges(Graph&);
    static int bellmanFord(Graph& , vector<int>&, vector<int>&);
    
    static int hasCycleDFS(Graph&, IndexType, std::vector<bool>&, std::vector<bool>&);


     
};
}
