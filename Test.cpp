#include "doctest.h"
#include "Algorithms.hpp"
//#include "Graph.hpp"

using namespace std;

TEST_CASE("Test isConnected")
{
    ariel::Graph g;
    vector<vector<int> > graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel:: Algorithms:: isConnected(g) == 1);

    vector<vector<int> > graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == 0);
}


TEST_CASE("isConnectedTest") {
    // Create a connected graph
    std::vector<std::vector<int> > connectedMatrix = {
        {0, 1, 0, 0, 0},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {0, 0, 0, 1, 0}
    };

    ariel::Graph graph;
    graph.loadGraph(connectedMatrix);

    // Check if the graph is connected
    int result = ariel::Algorithms::isConnected(graph);

    // The graph should be connected, so the result should be 1
    CHECK(result == 1);
}

TEST_CASE("isConnectedDisconnectedTest") {
    // Create a disconnected graph
    vector<vector<int> > disconnectedMatrix = {
        {0, 1, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}
    };

    ariel::Graph graph;
    graph.loadGraph(disconnectedMatrix);

    // Check if the graph is connected
    int result = ariel::Algorithms::isConnected(graph);

    // The graph should be disconnected, so the result should be 0
    CHECK(result == 0);
}

// Add more test cases as needed to cover different scenarios








TEST_CASE("Test isConnected") {
    ariel::Graph g;
    vector<vector<int> > graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected( g) == 1);
}

TEST_CASE("Test shortestPath")
{
    ariel::Graph g;
    vector<vector<int> > graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");

    vector<vector<int> > graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "-1");
}
TEST_CASE("Test isContainsCycle")
{
    ariel::Graph g;
    vector<vector<int> > graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);

    vector<vector<int> > graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);
}
TEST_CASE("Test isBipartite")
{
    ariel::Graph g;
    vector<vector<int> > graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    vector<vector<int> > expectedBipartition = {{0, 2}, {1}};

    // Call the isBipartite function and store the result
    vector<vector<int> > bipartition = ariel::Algorithms::isBipartite(g);

    // Compare the result with the expected bipartition
    CHECK((bipartition == expectedBipartition));

    vector<vector<int> > graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    vector<vector<int> > expectedBipartition1 = {{0}};
    vector<vector<int> > bipartition1=ariel::Algorithms::isBipartite(g);
    CHECK(bipartition1 == expectedBipartition1);

    vector<vector<int>> graph3 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3);
    std::vector<std::vector<int> > expectedBipartition2 = {{0,2,4},{1,3}};
    std::vector<std::vector<int> > bipartition2=ariel::Algorithms::isBipartite(g);
    CHECK(bipartition2 == expectedBipartition2);
}
TEST_CASE("Test invalid graph")
{
    ariel::Graph g;
    vector<vector<int> > graph = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph));
}
