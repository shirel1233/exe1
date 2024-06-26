/*
 * Demo program for Exercise 2.
 * Author: Benjamin Saldman.
 */
//324815083
//cohen.shirel098@gmail.com

#include "Algorithms.hpp"
using ariel::Algorithms;
#include <stdexcept>
#include <iostream>
using namespace std;

int main()
{
    ariel::Graph g;
    // 3x3 matrix that represents a connected graph.
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph); // Load the graph to the object.

    g.printGraph(); 
    //cout << "isConnected(g)" << endl;                                   // Should print: "Graph with 3 vertices and 4 edges."
    cout << Algorithms::isConnected(g) << endl;        // Should print: "1" (true).
    vector<int> shortestPath = Algorithms::shortestPath(g, 0, 2);// Should print: {0,1,2}.
        cout << "Shortest path : {";
        for (size_t i = 0; i < shortestPath.size(); ++i) {
            cout << shortestPath[i];
            if (i < shortestPath.size() - 1) {
                cout << ", ";
            }
        }
        cout << "}" << endl;
    
    cout << Algorithms::isContainsCycle(g) << endl;    // Should print: "0" (false).

    std::vector<std::vector<int>> bipartition = Algorithms::isBipartite(g); // Should print: "The graph is bipartite: {{0, 2},{1}}.
    if (bipartition == std::vector<std::vector<int>>{{0}}) {
        cout << "The graph is not bipartite: {{0}}" << endl; 
    } else {
        cout << "The graph is bipartite: ";
        for (size_t i = 0; i < bipartition.size(); ++i) {
            cout << (i == 0 ? "{" : ", {");
            for (size_t j = 0; j < bipartition[i].size(); ++j) {
                cout << bipartition[i][j];
                if (j != bipartition[i].size() - 1) {
                    cout << ", ";
                }
            }
            cout << "}";
        }
        cout << endl;
    }

    // 5x5 matrix that represents a non-connected graph with a cycle.
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};

    g.loadGraph(graph2); // Load the graph to the object.

    g.printGraph();                                    // Should print: "Graph with 5 vertices and 8 edges."
    cout << Algorithms::isConnected(g) << endl;        // Should print: "0" (false).
    vector<int> shortestPath1 = Algorithms::shortestPath(g, 0, 4);
     // Should print: {} (there is no path between 0 and 4).
    cout << "Shortest path : {";
        for (size_t i = 0; i < shortestPath1.size(); ++i) {
            cout << shortestPath1[i];
            if (i < shortestPath1.size() - 1) {
                cout << ", ";
            }
        }
        cout << "}" << endl;
    

    cout << Algorithms::isContainsCycle(g) << endl;    // Should print: "The cycle is: 0->1->2->0".
    
    std::vector<std::vector<int>> bipartition1 = Algorithms::isBipartite(g); // Should print: "The graph is not bipartite: {{0}}
    if (bipartition1 == std::vector<std::vector<int>>{{0}}) {
        cout << "The graph is not bipartite: {{0}}" << endl; 
    } else {
        cout << "The graph is bipartite: ";
        for (size_t i = 0; i < bipartition1.size(); ++i) {
            cout << (i == 0 ? "{" : ", {");
            for (size_t j = 0; j < bipartition1[i].size(); ++j) {
                cout << bipartition1[i][j];
                if (j != bipartition1[i].size() - 1) {
                    cout << ", ";
                }
            }
            cout << "}";
        }
        cout << endl;
    }

    // 5x5 matrix that reprsents a connected weighted graph.
    vector<vector<int>> graph3 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3);  // Load the graph to the object.

    g.printGraph();                                    // Should print: "Graph with 5 vertices and 10 edges."
    cout << Algorithms::isConnected(g) << endl;        // Should print: "1" (true).
    //cout << Algorithms::shortestPath(g, 0, 4) << endl; // Should print: {0,2,3,4}.
    vector<int> shortestPath2 = Algorithms::shortestPath(g, 0, 4);
     // Should print: {} (there is no path between 0 and 4).
    cout << "Shortest path : {";
        for (size_t i = 0; i < shortestPath2.size(); ++i) {
            cout << shortestPath2[i];
            if (i < shortestPath2.size() - 1) {
                cout << ", ";
            }
        }
        cout << "}" << endl;
    

    cout << Algorithms::isContainsCycle(g) << endl;    // Should print: "0" (false).
    
    // 5x4 matrix that reprsents invalid graph.
    vector<vector<int>> graph4 = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    try
    {
        g.loadGraph(graph4); // Load the graph to the object.
    }
    catch (const std::invalid_argument &e)
    {
        cout << e.what() << endl; // Should print: "Invalid graph: The graph is not a square matrix."
    } 
};
