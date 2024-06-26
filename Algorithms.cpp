//324815083
//cohen.shirel098@gmail.com

#include "Algorithms.hpp"
#include <climits>
#include <queue>
#include <algorithm>
#include <vector>
#include <limits>
#define INF 999999
using namespace std;

void ariel ::Algorithms::dfs(size_t v, ariel:: Graph & g, std::vector<int>& visited) {
    // Mark the current vertex as visited
    visited[v] = 1;
    size_t n = g.getNumVertices();

    for (size_t i = 0; i < n; i++) {
        int val = g.getEdge(v, i);
        if ( val!=0 && !visited[i]) {
            dfs(i, g, visited);
        }
    }
};

ariel:: Graph ariel::Algorithms::reverseEdges(Graph& g) {
    size_t n = g.getNumVertices();
    // Initialize reversedGraph with size n x n
    Graph reversedGraph(n);
    for (size_t i = 0; i < n; i++) { 
        for (size_t j = 0; j < n; j++) { 
            reversedGraph.setEdge(j, i, g.getEdge(i,j));
        }
    }
    return reversedGraph;
}


int ariel ::Algorithms::isConnected(Graph &g) {
    size_t n = g.getNumVertices();
    vector<int> vis1(n, 0), vis2(n, 0);

    // Initialize beforeReversedGraph with size n x n
    ariel :: Graph beforeReversedGraph(n);

    // Populate beforeReversedGraph with the edges of the original graph
    for (size_t i = 0; i < n; i++) { 
        for (size_t j = 0; j < n; j++) { 
            beforeReversedGraph.setEdge(j,i, g.getEdge(i, j));
        }
    }

    // Call DFS for correct direction
    dfs(0, beforeReversedGraph, vis1);

    // Get the reversed graph
    Graph reversedGraph = reverseEdges(g);

    // Call DFS for reverse direction
    dfs(0, reversedGraph, vis2);

    for (size_t i = 0; i < n; ++i) { 
        // If any vertex is not visited in any direction, the graph is not connected
        if (!vis1[i] && !vis2[i]) {
            return 0;
        }
    }

    // If the graph is connected
    return 1;
};


vector<int> ariel::Algorithms::shortestPath(Graph& g, size_t start, size_t end) {
    size_t n = g.getNumVertices();
    vector<int> distance(n, INF);
    vector<int> parent(n, -1);
    distance[start] = 0;

    // Relax edges (n - 1) times
    for (size_t i = 0; i < n - 1; ++i) {
        for (size_t u = 0; u < n; ++u) {
            for (size_t v = 0; v < n; ++v) {
                int weight = g.getEdge(u, v);
                if (weight != 0 && distance[u] != INF && distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                    parent[v] = u;
                }
            }
        }
    }

    // Check for negative cycles
    for (size_t u = 0; u < n; u++) {
        for (size_t v = 0; v < n; v++) {
            int weight = g.getEdge(u, v);
            if (weight != 0 && distance[u] != INF && distance[u] + weight < distance[v]) {
                // Negative cycle detected
                return vector<int>(); // Indicate negative cycle
            }
        }
    }

    // Reconstruct the shortest path
    vector<int> shortestPath;
    size_t current = end;
    while (current != start) {
        shortestPath.push_back(current);
        current = (size_t)parent[current];
        if (current == -1) {
            return vector<int>(); // No path exists from start to end
        }
    }
    shortestPath.push_back(start);
    reverse(shortestPath.begin(), shortestPath.end());

    // Check if the path contains only the start vertex
    if (shortestPath.size() == 1) {
        return vector<int>(); // No path exists from start to end
    }

    return shortestPath;
}



int ariel::Algorithms::bellmanFord(Graph& g, std::vector<int>& distance, std::vector<int>& parent) {

    // Get the number of vertices in the graph
    size_t n = g.getNumVertices();

    // Initialize distance and parent arrays
    distance.assign(n, INT_MAX);
    parent.assign(n, -1);

    // Set distance to source vertex as 0
    distance[0] = 0;

    // Relax edges repeatedly
    for (size_t i = 0; i < n - 1; ++i) {
        for (size_t u = 0; u < n; ++u) {
            for (size_t v = 0; v < n; ++v) {
                int weight = g.getEdge(u, v);
                // If there's an edge from u to v and it shortens the distance
                if (weight != 0 && distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                    // Update distance and parent arrays
                    distance[v] = distance[u] + weight;
                    parent[v] = u;
                }
            }
        }
    }

    // Check for negative cycles
    for (size_t u = 0; u < n; ++u) {
        for (size_t v = 0; v < n; ++v) {
            int weight = g.getEdge(u, v);
            // If there's an edge from u to v and it shortens the distance further
            if (weight != 0 && distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                // Negative cycle detected
                return 1;
            }
        }
    }

    // No negative cycle found
    return 0;
}


int ariel ::Algorithms::hasCycleDFS(Graph& g, size_t v, std::vector<bool>& visited, std::vector<bool>& inStack) {

    visited[v] = true;
    inStack[v] = true;

    size_t n = g.getNumVertices();
    for (size_t u = 0; u < n; u++) {
        if (g.getEdge(v, u) != 0) {
            if (!visited[u]&& hasCycleDFS(g, u, visited, inStack)){
                    return true;
            } else if (inStack[u]) {
                return true;
            }
        }
    }
    inStack[v] = false;
    return false;
};

    
int ariel ::Algorithms::isContainsCycle(Graph&g) {
    
    size_t n = g.getNumVertices();
    vector<bool> visited(n, false);
    vector<bool> inStack(n, false);

    for (size_t i = 0; i < n; ++i) {
        if (!visited[i] && hasCycleDFS(g, i, visited, inStack)) {
            return true; // Cycle detected
        }
    }

    return false; // No cycle detected
};

vector<vector<int>> ariel::Algorithms::isBipartite(Graph& g) {
    size_t V = g.getNumVertices();
    vector<int> color(V, -1); // Initialize all vertices with no color

    for (size_t i = 0; i < V; i++) {
        if (color[i] == -1) { // If vertex i is not colored
            std::queue<int> q;
            q.push(i);
            color[i] = 0; // Color vertex i with 0

            while (!q.empty()) {
                size_t u = (size_t)q.front();
                q.pop();
                for (size_t v = 0; v < V; v++) {
                    if (g.getEdge(u, v) != 0 || g.getEdge(v, u) != 0) {
                        // If there is an edge between u and v (accounting for both directed and undirected edges)
                        // or if the weight of the edge is not zero in a weighted graph
                        if (color[v] == -1) { // If vertex v is not colored
                            color[v] = 1 - color[u]; // Color vertex v with the opposite color of u
                            q.push(v);
                        } else if (color[v] == color[u]) {
                            // If adjacent vertices have the same color
                            return {{0}}; // Graph is not bipartite, return empty vector
                        }
                    }
                }
            }
        }
    }

    vector<vector<int>> bipartition(2); // Vector to store bipartition
    for (size_t i = 0; i < V; i++) {
        bipartition[(size_t)color[i]].push_back(i); // Assign vertices to their respective partitions
    }

    return bipartition; // Return the bipartition
}

std::vector<int> ariel::Algorithms::negativeCycle(Graph& g) {
    std::vector<int> distance, parent;
    size_t n = g.getNumVertices();

    if (bellmanFord(g, distance, parent)) {

        // Negative cycle found, now trace back to find the cycle
        int cycleStart = -1;
        for (size_t u = 0; u < n; ++u) {
            for (size_t v = 0; v < n; ++v) {
                int weight = g.getEdge(u, v);
                if (weight != 0 && distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                    // Negative cycle detected
                    cycleStart = static_cast<int>(v);
                    break;
                }
            }
            if (cycleStart != -1) break;
        }

        // Find a vertex on the cycle
        int cycleVertex = cycleStart;
        for (size_t i = 0; i < n; ++i) {
            cycleVertex = parent[static_cast<size_t>(cycleVertex)];
        }

        // Trace back the cycle
        std::vector<int> cycle;
        int current = cycleVertex;
        do {
            cycle.push_back(current);
            current = parent[static_cast<size_t>(current)];
        } while (current != cycleVertex);
        cycle.push_back(current);

        std::reverse(cycle.begin(), cycle.end()); // Reverse to get the correct order
        return cycle;
    }

    // No negative cycle found
    return std::vector<int>();
}
