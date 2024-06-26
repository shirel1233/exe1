//324815083
//cohen.shirel098@gmail.com

#include "Graph.hpp"
#include <stdexcept>
using namespace std;

// Constructor that initializes the matrix with zeros
ariel::Graph::Graph(size_t numVertices) : mat(numVertices, vector<int>(numVertices, 0)) {
    // mat is initialized to an numVertices x numVertices matrix with all zeros
}

// Destructor
ariel::Graph::~Graph() {
    // No need to explicitly delete anything, since we're using std::vector
}

void ariel::Graph::loadGraph(const vector<vector<int>> matrix) {
    if (matrix.size() != matrix[0].size()) {
        throw std::invalid_argument("Error: matrix is not square.");
    }
    // Copy the input matrix
    mat = matrix;
    // Ensure the diagonal elements are zero
    for (size_t i = 0; i < mat.size(); ++i) {
        mat[i][i] = 0;
    }     
}


size_t ariel::Graph::getNumVertices() const {
    size_t n = mat.size();
    return n;
};

// Helper function to check if the graph is directed
bool ariel::Graph:: isDirected() const {
    // Assuming the graph is undirected if mat[i][j] == mat[j][i] for all i, j
    for (size_t i = 0; i < mat.size(); i++) {
        for (size_t j = 0; j < mat[i].size(); j++) {
            if (mat[i][j] != mat[j][i]) {
                return true;
            }
        }
    }
    return false;
};


int ariel::Graph:: getNumEdges() const {
    int numEdges = 0;
    for (size_t i = 0; i < mat.size(); i++) {
        for (size_t j = i + 1; j < mat[i].size(); j++) {
            if (mat[i][j] != 0) {
                // For directed graphs, count all non-zero values
                numEdges++;
            
            }
        }
    }
    // For undirected graphs, divide by 2 since each edge is counted twice
    if (!isDirected()) {
        numEdges /= 2;
    }
    return numEdges;
}

void ariel::Graph:: setEdge(size_t i, size_t j, int val){
    if (i >= mat.size() || j >= mat.size()) {
        cerr << "Error: Invalid indices." << endl;
        return; // Return some default value indicating error
    }
    if(i!=j){
        mat[i][j]=val;
    }else{
        mat[i][j]=0;
    }
}

int ariel::Graph::getEdge(size_t i, size_t j)const {
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
    for (size_t i = 0; i < mat.size(); i++) {
        for (size_t j = 0; j < mat[i].size(); j++) {
            cout << mat[i][j];
            if (j != mat[i].size() - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
}

//part 2

// Helper function to check if the current graph is contained in another graph
bool ariel::Graph::isContainedIn(const Graph& other) const {
// Check if the adjacency matrix of the current graph is a submatrix of the other graph's adjacency matrix
    if (*this==other) { 
        return false;
    } 
    for (size_t i = 0; i < mat.size(); i++) {
        for (size_t j = 0; j < mat[i].size(); j++) {
            if (mat[i][j] != 0 && other.mat[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}


vector<vector<int>> ariel::Graph:: operator+=(const Graph& other) {
    if (mat.size() != other.mat.size()) {
        throw std::invalid_argument("Error: Matrices must have same dimensions for addition.");
    }
    for (size_t i = 0; i < mat.size(); i++) {
        for (size_t j = 0; j < mat[i].size(); j++) {
            if(i==j){
                mat[i][j]=0;
            }else{
                mat[i][j] += other.mat[i][j];
            }
            
        }
    }
    return mat;
}

vector<vector<int>> ariel::Graph::operator-=(const Graph& other) {
    if (mat.size() != other.mat.size()) {
        throw std::invalid_argument("Error: Matrices must have same dimensions for subtraction.");
    }
    for (size_t i = 0; i < mat.size(); i++) {
        for (size_t j = 0; j < mat[i].size(); j++) {
            if(i==j){
                mat[i][j]=0;
            }else{
                mat[i][j] -= other.mat[i][j];
            }
            
        }
    }
    return mat;
}

vector<vector<int>> ariel::Graph::operator+(const Graph& other) const {
    vector<vector<int>> result( mat.size());
    if (mat.size() != other.mat.size() || mat[0].size() != other.mat[0].size()) {
        throw std::invalid_argument("Error: Matrices must have same dimensions for addition.");
    }
    for (size_t i = 0; i < mat.size(); i++) {
        for (size_t j = 0; j < mat[i].size(); j++) {
            result[i][j] = mat[i][j] + other.mat[i][j];
        }
    }
    return result;
}

vector<vector<int>> ariel::Graph::operator-(const Graph& other) const {
    vector<vector<int>> result( mat.size());
    if (mat.size() != other.mat.size() || mat[0].size() != other.mat[0].size()) {
        throw std::invalid_argument("Error: Matrices must have same dimensions for subtraction.");
    }
    for (size_t i = 0; i < mat.size(); i++) {
        for (size_t j = 0; j < mat[i].size(); j++) {
            result[i][j] = mat[i][j] - other.mat[i][j];
        }
    }
    return result;
}

// Unary operator (+)
void ariel::Graph::operator+() const {
}
// Unary operator (-)
void ariel::Graph::operator-() {
    for (size_t i = 0; i < mat.size(); i++) {
        for (size_t j = 0; j < mat[i].size(); j++) {
            mat[i][j] = -mat[i][j];
        }
    }
}

void ariel::Graph::operator++() {
    for (size_t i = 0; i < mat.size(); i++) {
        for (size_t j = 0; j < mat[i].size(); j++) {
            if(i==j){
                mat[i][j]=0;
            }else{
                ++mat[i][j];
            }
        }
    }
}

void  ariel::Graph::operator--() {
    for (size_t i = 0; i < mat.size(); i++) {
        for (size_t j = 0; j < mat[i].size(); j++) {
            if(i==j){
                mat[i][j]=0;
            }else{
                --mat[i][j];
            }
        }
    }
}

void ariel::Graph::operator--(int) {
    for (size_t i = 0; i < mat.size(); i++) {
        for (size_t j = 0; j < mat[i].size(); j++) {
            if(i==j){
                mat[i][j]=0;
            }else{
                mat[i][j]--;
            }
        }
    }
}
 void ariel::Graph::operator++(int) {
    for (size_t i = 0; i < mat.size(); i++) {
        for (size_t j = 0; j < mat[i].size(); j++) {
            if(i==j){
                mat[i][j]=0;
            }else{
                mat[i][j]++;
            }
        }
    }
}

void ariel::Graph:: operator*(int scalar) {
    for (size_t i = 0; i < mat.size(); i++) {
        for (size_t j = 0; j < mat[i].size(); j++) {
            mat[i][j]= mat[i][j]*scalar;
        }
    }
}

vector<vector<int>> ariel::Graph:: operator*(const Graph& other) const{
    if (mat.size() != other.mat.size()) {
        throw std::invalid_argument("Error: Matrices must have same dimensions for addition.");
    }
    vector<vector<int>> result (mat.size());

    for (size_t i = 0; i < mat.size(); i++) {
        for (size_t j = 0; j < mat[i].size(); j++) {
            for (size_t k = 0; k < mat.size(); k++) {
                result[i][j] += mat[i][k] * other.mat[k][j];
            }
        }
    }
    return result;
}


bool ariel::Graph:: operator==(const Graph& other) const {
    if (mat.size() != other.mat.size()) { 
        //Graphs G1 and G2 will be called equal if they are of the same order of magnitude
        return false;
    }

    for (size_t i = 0; i < mat.size(); i++) {
        for (size_t j = 0; j < mat[i].size(); j++) {
        //contain the same edges (and the weights of the edges are the same)
            if (mat[i][j] != other.mat[i][j]) {
                return false;
            }
        }
    }
    if (*this>other||*this <other) { 
        
        return false;
    } 

    return true;
}
bool ariel::Graph::operator!=(const Graph& other) const {
    return !(*this == other);
}


bool ariel::Graph:: operator<(const Graph& other) const {
    // Check if G1 is directly contained in G2
    if (isContainedIn(other)) {
        return true;
    }
    // Check if G2 is directly contained in G1
    else if (other.isContainedIn(*this)) {
        return false;
    }
    // If neither graph is directly contained in the other
    else {
        // Compare the number of edges
        int numEdges1 = getNumEdges();
        int numEdges2 = other.getNumEdges();
        if (numEdges1 != numEdges2) {
            return numEdges1 < numEdges2;
        }
        // If the number of edges is the same, compare the order of magnitude of the adjacency matrices
        else {
            return mat.size() < other.mat.size();
        }
    }
}

        
bool ariel::Graph::operator>(const Graph& other) const {
    // Implement > using the < operator
    return other < *this;
}

bool ariel::Graph::operator>=(const Graph& other) const {
    // Implement >= using > and ==
    return !(*this < other);
}

bool ariel::Graph::operator<=(const Graph& other) const {
    // Implement <= using < and ==
    return !(*this > other) || (*this == other);
}



