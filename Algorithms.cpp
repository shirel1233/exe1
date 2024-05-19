//324815083
//cohen.shirel098@gmail.com
#include "Algorithms.hpp"
#include <climits>
#include <queue>
#include <algorithm>

    void ariel ::Algorithms::dfs(ariel:: Algorithms:: IndexType v, std::vector<std::vector<int>>& g, std::vector<int>& visited) {
        visited[v] = 1;
        for (IndexType i = 0; i < g[v].size(); i++) {
            if (g[v][i] && !visited[i]) {
                dfs(i, g, visited);
            }
        }
    };

    vector<vector<int>> ariel::Algorithms::reverseEdges(Graph& g) {
    IndexType n = (IndexType)g.getNumVertices();
    // Initialize reversedGraph with size n x n
    vector<vector<int>> reversedGraph(static_cast<size_t>(n), vector<int>(static_cast<size_t>(n), 0));

    for (IndexType i = 0; i < n; i++) { // Use IndexType for loop indices
        for (IndexType j = 0; j < n; j++) { // Use IndexType for loop indices
            reversedGraph[static_cast<size_t>(j)][static_cast<size_t>(i)] = g.getEdge(i, j);
        }
    }
    return reversedGraph;
}


    int ariel ::Algorithms::isConnected(Graph g) {
        IndexType n = (IndexType)g.getNumVertices();
        vector<int> vis1(n, 0), vis2(n, 0);

        // Initialize beforeReversedGraph with size n x n
        vector<vector<int>> beforeReversedGraph(n, vector<int>(n, 0));

        // Populate beforeReversedGraph with the edges of the original graph
        for (IndexType i = 0; i < n; i++) { // Use IndexType for loop indices
            for (IndexType j = 0; j < n; j++) { // Use IndexType for loop indices
                beforeReversedGraph[j][i] = g.getEdge(i, j);
            }
        }

        // Call DFS for correct direction
        dfs(0, beforeReversedGraph, vis1);

        // Get the reversed graph
        vector<vector<int>> reversedGraph = reverseEdges(g);

        // Call DFS for reverse direction
        dfs(0, reversedGraph, vis2);

        for (IndexType i = 0; i < n; ++i) { // Use IndexType for loop indices
            // If any vertex is not visited in any direction, the graph is not connected
            if (!vis1[i] && !vis2[i]) {
                return 0;
            }
        }

        // If the graph is connected
        return 1;
    };
#include <vector>
#include <limits>
#include <queue>

using namespace std;
vector<int> ariel::Algorithms::shortestPath(Graph g, int start, int end) {
    IndexType n = (IndexType)g.getNumVertices();
    vector<int> distance(n, numeric_limits<int>::max());
    vector<int> parent(n, -1);
    distance[static_cast<size_t>(start)] = 0;

    // Relax edges (V - 1) times
    for (IndexType i = 0; i < n - 1; ++i) {
        for (IndexType u = 0; u < n; ++u) {
            for (IndexType v = 0; v < n; ++v) {
                int weight = g.getEdge(u, v);
                if (weight != 0 && distance[u] != numeric_limits<int>::max() && distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                    parent[v] = u;
                }
            }
        }
    }

    // Check for negative cycles
    for (IndexType u = 0; u < n; ++u) {
        for (IndexType v = 0; v < n; ++v) {
            int weight = g.getEdge(u, v);
            if (weight != 0 && distance[u] != numeric_limits<int>::max() && distance[u] + weight < distance[v]) {
                // Negative cycle detected
                return vector<int>(); // Indicate negative cycle
            }
        }
    }

    // Reconstruct the shortest path
    vector<int> shortestPath;
    int current = end;
    while (current != start) {
        shortestPath.push_back(current);
        current = parent[static_cast<size_t>(current)];
        if (current == -1) {
            return vector<int>(); // No path exists from start to end
        }
    }
    shortestPath.push_back(start);
    reverse(shortestPath.begin(), shortestPath.end());

    // Check if the path contains only the start vertex
    if (shortestPath.size() == 1 && shortestPath[0] == start) {
        return vector<int>(); // No path exists from start to end
    }

    return shortestPath;
}



    int ariel::Algorithms::bellmanFord(Graph& g, std::vector<int>& distance, std::vector<int>& parent) {
    // Alias for size type
    using IndexType = typename std::vector<int>::size_type;

    // Get the number of vertices in the graph
    IndexType n = static_cast<IndexType>(g.getNumVertices());

    // Initialize distance and parent arrays
    distance.assign(n, INT_MAX);
    parent.assign(n, -1);

    // Set distance to source vertex as 0
    distance[0] = 0;

    // Relax edges repeatedly
    for (IndexType i = 0; i < n - 1; ++i) {
        for (IndexType u = 0; u < n; ++u) {
            for (IndexType v = 0; v < n; ++v) {
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
    for (IndexType u = 0; u < n; ++u) {
        for (IndexType v = 0; v < n; ++v) {
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


    int ariel ::Algorithms::hasCycleDFS(Graph& g, IndexType v, std::vector<bool>& visited, std::vector<bool>& inStack) {

        visited[v] = true;
        inStack[v] = true;

        IndexType n = (IndexType)g.getNumVertices();
        for (IndexType u = 0; u < n; u++) {
            if (g.getEdge(v, u) != 0) {
                if (!visited[u]) {
                    if (hasCycleDFS(g, u, visited, inStack))
                        return true;
                } else if (inStack[u]) {
                    return true;
                }
            }
        }
        inStack[v] = false;
        return false;
    };

    
    int ariel ::Algorithms::isContainsCycle(Graph g) {
        
        IndexType n = (IndexType)g.getNumVertices();
        vector<bool> visited(n, false);
        vector<bool> inStack(n, false);

        for (IndexType i = 0; i < n; ++i) {
            if (!visited[i] && hasCycleDFS(g, i, visited, inStack)) {
                return true; // Cycle detected
            }
        }

        return false; // No cycle detected
    };

    std::vector<std::vector<int>> ariel::Algorithms::isBipartite(Graph g) {
    using IndexType = typename std::vector<int>::size_type;

    int V = (IndexType)g.getNumVertices();
    std::vector<int> color((IndexType)V, -1); // Initialize all vertices with no color

    for (IndexType i = 0; i < static_cast<IndexType>(V); i++) {
        if (color[i] == -1) { // If vertex i is not colored
            std::queue<int> q;
            q.push(i);
            color[i] = 0; // Color vertex i with 0

            while (!q.empty()) {
                int u = (IndexType)q.front();
                q.pop();
                for (IndexType v = 0; v < static_cast<IndexType>(V); v++) {
                    if (g.getEdge((IndexType)u, v) != 0 || g.getEdge(v, (IndexType)u) != 0) {
                        // If there is an edge between u and v (accounting for both directed and undirected edges)
                        // or if the weight of the edge is not zero in a weighted graph
                        if (color[(IndexType)v] == -1) { // If vertex v is not colored
                            color[v] = 1 - color[(IndexType)u]; // Color vertex v with the opposite color of u
                            q.push(v);
                        } else if (color[v] == color[(IndexType)u]) {
                            // If adjacent vertices have the same color
                            return {{0}}; // Graph is not bipartite, return empty vector
                        }
                    }
                }
            }
        }
    }

    std::vector<std::vector<int>> bipartition(2); // Vector to store bipartition
    for (IndexType i = 0; i < V; i++) {
        bipartition[(IndexType)color[(IndexType)i]].push_back((IndexType)i); // Assign vertices to their respective partitions
    }

    return bipartition; // Return the bipartition
}


    std::vector<int> ariel::Algorithms::negativeCycle(Graph g) {

    // Perform Bellman-Ford algorithm to detect negative cycle
    std::vector<int> distance, parent;
    if (bellmanFord(g, distance, parent)) {
        // Negative cycle found, now trace back to find the cycle
        IndexType n = (IndexType)g.getNumVertices();
        for (IndexType u = 0; u < n; u++) {
            if (distance[u] == INT_MIN) { // Found a vertex in the negative cycle
                // Trace back from this vertex to find the cycle
                IndexType cycleStart = u;
                IndexType current = u;
                std::vector<int> cycle;
                do {
                    cycle.push_back(static_cast<int>(current));
                    current = static_cast<IndexType>(parent[current]);
                } while (current != cycleStart);
                std::reverse(cycle.begin(), cycle.end()); // Reverse the cycle to get correct order
                return cycle;
            }
        }
    }
    // No negative cycle found
    return std::vector<int>();
}

