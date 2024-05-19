//324815083
//cohen.shirel098@gmail.com
#include "doctest.h"
#include "Algorithms.hpp"

using namespace std;


TEST_CASE("Test isConnected") {
    ariel::Graph g;

    // Test case for an undirected connected graph with non-negative weights
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 2},
        {0, 2, 0}};
    g.loadGraph(graph1);
    CHECK(ariel::Algorithms::isConnected(g) == 1);

    // Test case for a directed connected graph with non-negative weights
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == 0);

    // Test case for an undirected connected graph with negative weights
    vector<vector<int>> graph3 = {
        {0, 2, 0},
        {-1, 0, 1},
        {0, -1, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isConnected(g) == 1);

    // Test case for a directed connected graph with negative weights
    vector<vector<int>> graph4 = {
        {0, 1, 0, 0, 0},
        {0, 0, -1, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, -1},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isConnected(g) == 0);

    // Test case for an undirected disconnected graph with negative weights
    vector<vector<int>> graph5 = {
        {0, 1, 0},
        {1, 0, 0},
        {0, 0, 0}};
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::isConnected(g) == 0);

    // Test case for a directed disconnected graph with negative weights
    vector<vector<int>> graph6 = {
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph6);
    CHECK(ariel::Algorithms::isConnected(g) == 0);
}

TEST_CASE("Test shortestPath") {
    ariel::Graph g;
   
    vector<vector<int>> graph1 = {
        {0, 1, 1, 0},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {0, 0, 1, 0},};
    g.loadGraph(graph1);
    // Test shortest path in an undirected graph
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == vector<int>{0,2});
    
    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};

        
    g.loadGraph(graph2);

    // Test with weighted edges and directed graph
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == vector<int>{0, 1, 2});

    vector<vector<int>> graph3 = {
        {0, 1, 1},
        {1, 0, -1},
        {1, -1, 0}};
    g.loadGraph(graph3);

    // Test for negative weight cycle
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == vector<int>{});

    
    vector<vector<int>> graph4 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == vector<int>{});
}
TEST_CASE("Test isContainsCycle")
{
    ariel::Graph g;
   
//"Test isContainsCycle for undirected graph with cycle") {

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}
    };
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isContainsCycle(g) == 1);

//"Test isContainsCycle for directed graph without cycle") {
    
    vector<vector<int>> graph3 = {
        {0, 1, 0},
        {0, 0, 1},
        {0, 0, 0}
    };
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isContainsCycle(g) == 0);


//"Test isContainsCycle for directed graph with cycle") {
  
    vector<vector<int>> graph4 = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 0, 0}
    };
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isContainsCycle(g) == 1);


//"Test isContainsCycle for graph with negative edge weights and cycle") {
   
    vector<vector<int>> graph5 = {
        {0, -1, 1},
        {1, 0, 0},
        {0, 1, 0}
    };
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::isContainsCycle(g) == 1);


//"Test isContainsCycle for graph with negative edge weights and cycle") {
    
    vector<vector<int>> graph6 = {
        {0, -1, 0},
        {1, 0, 0},
        {0, 0, 0}
    };
    g.loadGraph(graph6);
    CHECK(ariel::Algorithms::isContainsCycle(g) == 1);

}

TEST_CASE("Test isBipartite") {
    ariel::Graph g;

    // Test case for a simple bipartite graph
    vector<vector<int>> graph1 = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}};
    g.loadGraph(graph1);
    vector<vector<int>> expected1 = {{0, 2}, {1, 3}};
    CHECK(ariel::Algorithms::isBipartite(g) == expected1);

    // Test case for a non-bipartite graph
    vector<vector<int>> graph2 = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isBipartite(g) == vector<vector<int>>{{0}}); // Expecting vector of 0

    // Test case for a graph with negative weights
    vector<vector<int>> graph3 = {
        {0, -1, 0},
        {-1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph3);
    vector<vector<int>> expected3 = {{0, 2}, {1}};
    CHECK(ariel::Algorithms::isBipartite(g) == expected3);

    // Test case for a disconnected graph
    vector<vector<int>> graph4 = {
        {0, 1, 0, 0},
        {1, 0, 0, 1},
        {0, 0, 0, 1},
        {0, 1, 1, 0}};
    g.loadGraph(graph4);
    vector<vector<int>> expected4 = {{0, 3}, {1, 2}};
    CHECK(ariel::Algorithms::isBipartite(g) == expected4);

};





TEST_CASE("Test negativeCycle") {
    ariel::Graph g;

    // Case 1: Graph with no negative cycle
    vector<vector<int>> graph1 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph1);
    CHECK(ariel::Algorithms::negativeCycle(g) == vector<int>{});

    vector<vector<int>> graph4 = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::negativeCycle(g) == vector<int>{});
}


TEST_CASE("Test invalid graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph));
}
