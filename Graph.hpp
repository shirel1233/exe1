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
    using IndexType= typename std:: vector<int>::size_type;
    void loadGraph (const vector<vector<int>> matrix);
    void printGraph() const;
    int getNumVertices(); 
    int getEdge(IndexType i, IndexType j);
};
}
