    #include "Algorithms.hpp"
    #include <queue>
    #include <limits.h> // For INT_MAX

    void ariel:: Algorithms:: dfs(int v, vector<vector<int> > g, vector<bool>& visited) {
        visited[v] = true;
        for (int i = 0; i <  g.size(); i++) {
            if (g[v][i]&& !visited[i]) {
                dfs(i, g, visited);
            }
        }
    };



    vector<vector<int> > ariel::Algorithms::reverseEdges(Graph& g) {
    int n = g.getNumVertices();

    // Initialize reversedGraph with size n x n
    vector<vector<int> > reversedGraph(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            reversedGraph[j][i] = g.getEdge(i, j);
        }
    }
    return reversedGraph;
}


    int ariel:: Algorithms:: isConnected(Graph g) {
        int n = g.getNumVertices();
        vector<bool> vis1(n, false), vis2(n, false);

        vector<vector<int> > beforeReversedGraph;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                beforeReversedGraph[j][i] = g.getEdge(i, j);
            }
        }
        
        // Call DFS for correct direction
        dfs(0, beforeReversedGraph, vis1);
        vector<vector<int> > reversedGraph= reverseEdges(g);

        // Call DFS for reverse direction
        dfs(0,reversedGraph, vis2);

        for (int i = 0; i < n; ++i) {
            // If any vertex is not visited in any direction, the graph is not connected
            if (!vis1[i] && !vis2[i]) {
                return 0;
            }
        }

        // If graph is connected
        return 1;
    };


   
    vector<int> ariel:: Algorithms:: shortestPath(Graph g ,int start,int end){

        int n = g.getNumVertices();
        vector<int> distance(n, INT_MAX); // Initialize all distances to infinity
        distance[start] = 0;

        // Relax edges 
        for (int i = 0; i < n - 1; i++) {
            for (int u = 0; u < n; u++) {
                for (int v = 0; v < n; v++) {
                    if (g.getEdge(u, v) != 0 
                    && distance[u] != INT_MAX 
                    && distance[u] + g.getEdge(u, v) < distance[v]) {
                        distance[v] = distance[u] + g.getEdge(u, v);
                    }
                }
            }
        }

        // Check for negative cycles
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if (g.getEdge(u, v) != 0 
                && distance[u] != INT_MAX 
                && distance[u] + g.getEdge(u, v) < distance[v]) {
                    // Negative cycle detected
                    return vector<int>(-1); // -1 to indicate negative cycle
                }
            }
        }

        // Construct the shortest path
        vector<int> shortestPath;
        shortestPath.push_back(end); // Start from the end vertex
        int current = end;
        while (current != start) {
            for (int u = 0; u < n; ++u) {
                int weight = g.getEdge(u, current);
                if (weight != 0 && distance[u] + weight == distance[current]) {
                    shortestPath.push_back(u); // Add the current vertex to the path
                    current = u;
                    break;
                }
            }
        }
        shortestPath.push_back(start); // Add the start vertex to complete the path

        return shortestPath;
    };


    int ariel:: Algorithms:: bellmanFord(Graph& g,vector<int>& distance,vector<int>& parent) {
        int n = g.getNumVertices();
        distance.assign(n, INT_MAX); // Initialize distances to infinity
        parent.assign(n, -1); // Keep track of parent vertex in shortest path
        distance[0] = 0; // Start vertex

        // Relax edges repeatedly to detect negative cycles
        for (int i = 0; i < n - 1; i++) {
            for (int u = 0; u < n; u++) {
                for (int v = 0; v < n; v++) {
                    int weight = g.getEdge(u, v);
                    if (weight != 0 && distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                        distance[v] = distance[u] + weight;
                        parent[v] = u;
                    }
                }
            }
        }

        // Check for negative cycles
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                int weight = g.getEdge(u, v);
                if (weight != 0 
                && distance[u] != INT_MAX 
                && distance[u] + weight < distance[v]) {
                    // Negative cycle detected
                    return 1;
                }
            }
        }
        return 0;
    }

    int ariel:: Algorithms:: hasCycleDFS(Graph& g, int v, vector<bool>& visited, vector<bool>& inStack) {
        visited[v] = true;
        inStack[v] = true;

        // Traverse all adjacent vertices
        for (int u = 0; u < g.getNumVertices(); u++) {
            if (g.getEdge(v, u) != 0) {
                // If the adjacent vertex u is not visited, recursively check for cycle
                if (!visited[u]) {
                    if (hasCycleDFS(g, u, visited, inStack))
                        return true;
                }
                // If adjacent vertex u is already in the recursion stack, a cycle is found
                else if (inStack[u]) {
                    return 1;
                }
            }
        }
        inStack[v] = false;
        return 0;
    }


    int ariel:: Algorithms:: isContainsCycle(Graph g){
        vector<int> distance, parent;
        return bellmanFord(g, distance, parent); //&& לבדוק שאין גם חיוביים
    }; 


    vector<vector<int> > ariel:: Algorithms:: isBipartite(Graph g){
               int V = g.getNumVertices();
        vector<int> color(V, -1); // Initialize all vertices with no color

        for (int i = 0; i < V; i++) {
            if (color[i] == -1) { // If vertex i is not colored
                std::queue<int> q;
                q.push(i);
                color[i] = 0; // Color vertex i with 0

                while (!q.empty()) {
                    int u = q.front();
                    q.pop();

                    for (int v = 0; v < V; v++) {
                        if (g.getEdge(u, v) != 0) { // If there is an edge between u and v
                            if (color[v] == -1) { // If vertex v is not colored
                                color[v] = 1 - color[u]; // Color vertex v with the opposite color of u
                                q.push(v);
                            } else if (color[v] == color[u]) { // If adjacent vertices have the same color
                                return vector<vector<int> >(0); // Graph is not bipartite, return empty vector
                            }
                        }
                    }
                }
            }
        }

        vector<vector<int> > bipartition(2); // Vector to store bipartition
        for (int i = 0; i < V; i++) {
            bipartition[color[i]].push_back(i); // Assign vertices to their respective partitions
        }

        return bipartition; // Return the bipartition
    };


    vector<int> ariel:: Algorithms:: negativeCycle(Graph g){
        vector<int> distance, parent;
        if (bellmanFord(g, distance, parent)) { // Negative cycle found
            vector<int> cycle;
            int cycleStart = -1;
            int n = g.getNumVertices();
            for (int i = 0; i < n; ++i) {
                cycleStart = parent[cycleStart];
            }
            int current = cycleStart;
            cycle.push_back(current);
            current = parent[current];
            while (current != cycleStart) {
                cycle.push_back(current);
                current = parent[current];
            }
            cycle.push_back(cycleStart);
            return cycle;
        }
        return vector<int>(); // No negative cycle found

    };