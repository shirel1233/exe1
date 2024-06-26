#include <iostream>
#include <vector>
using namespace std;
namespace ariel{
class Graph{
    private:
    vector<vector<int> > mat;
    public:
    void loadGraph (const vector<vector<int> > matrix);
    void printGraph() const;
    int getNumVertices() const; 
    int getEdge(int i, int j); 
};
}