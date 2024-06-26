//324815083
//cohen.shirel098@gmail.com

#include <iostream>
#include <vector>
using namespace std;
namespace ariel{
class Graph{

    private:
    vector<vector<int>> mat;

    public:
    // Constructor
    Graph(size_t numVertices);
    Graph(){}
    // Destructor
    ~Graph();

    void loadGraph (const vector<vector<int>> matrix);
    void printGraph() const;
    size_t getNumVertices() const; 
    int getEdge(size_t i, size_t j) const;
    int getNumEdges() const;
    bool isDirected() const;
    void setEdge(size_t i, size_t j, int val);

    //part 2
    bool isContainedIn(const Graph& other) const;

    vector<vector<int>> operator+=(const Graph& other);
    vector<vector<int>> operator-=(const Graph& other);
    vector<vector<int>> operator+(const Graph& other) const;
    vector<vector<int>> operator-(const Graph& other) const;
    void operator+() const; // Unary +
    void operator-(); // Unary -

    bool operator>(const Graph& other) const;
    bool operator>=(const Graph& other) const;
    bool operator<(const Graph& other) const;
    bool operator<=(const Graph& other) const;
    bool operator==(const Graph& other) const;
    bool operator!=(const Graph& other) const;

    void operator++();
    void operator++(int);
    void operator--();
    void operator--(int);

    void operator*(int scalar);
    vector<vector<int>> operator*(const Graph& other) const;

};
}
