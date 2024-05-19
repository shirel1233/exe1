//324815083
//cohen.shirel098@gmail.com
#include "Graph.hpp"
using namespace std;


void ariel::Graph::loadGraph(const vector<vector<int>> matrix) {
    if (matrix.size() != matrix[0].size()) {
        throw std::invalid_argument("Error: matrix is not square.");
    }

    // Clear previous data
    mat.clear();

    // Copy the input matrix
    mat = matrix;     
}


int ariel::Graph::getNumVertices() {
    // Use IndexType for n
    IndexType n = mat.size();
    return n;
};

int ariel::Graph::getEdge(IndexType i, IndexType j) {
    // Check if indices are valid
    if (i >= mat.size() || j >= mat.size()) {
        cerr << "Error: Invalid indices." << endl;
        return -1; // Return some default value indicating error
    }

    // Return the value at the specified indices in the adjacency matrix
    int ans = mat[i][j];
    return ans;
};


void ariel::Graph::printGraph() const {
    for (size_t i = 0; i < mat.size(); ++i) {
        for (size_t j = 0; j < mat[i].size(); ++j) {
            cout << mat[i][j];
            if (j != mat[i].size() - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
}
