#include "Graph.hpp"
//using namespace std;


void ariel:: Graph:: loadGraph (const vector<vector<int> > matrix){
    if (matrix.size() != matrix[0].size()) {
        cerr << "Error: matrix is not square." << endl;
        return;
    }

    // Clear previous data
    mat.clear();

    // Copy the input matrix
    mat = matrix;     
}

int ariel:: Graph:: getNumVertices() const { 
    int size;
    size= mat.size();
    return size; } 

int ariel:: Graph:: getEdge(int i, int j) { 
    int ans =mat[i][j];
    return ans; } 

void ariel:: Graph:: printGraph() const{
    for (int i = 0; i < mat.size(); i++) {
            std:: cout << "{";
            for (int j = 0; j < mat[i].size(); j++) {
                std::cout << mat[i][j];
                if (j != mat[i].size() - 1) {
                    cout << ", ";
                }
            }
            std:: cout << "}" <<std:: endl;
        }

};

