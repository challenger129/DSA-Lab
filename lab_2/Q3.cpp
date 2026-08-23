#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void convertingIntoSparseMatrix(vector<vector<int> > &mat){
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int> > sparseMatrix;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] != 0){
                    vector<int> row;
                    row.push_back(i);
                    row.push_back(j);
                    row.push_back(mat[i][j]);
                    sparseMatrix.push_back(row);
                }
            }
        }
        cout << "Sparse Matrix Representation:\n";
        for(size_t k = 0; k < sparseMatrix.size(); k++){
            cout << sparseMatrix[k][0] << " " << sparseMatrix[k][1] << " " << sparseMatrix[k][2] << "\n";
        }
    }
};
int main(){
    vector<vector<int> > mat(3, vector<int>(3));
    mat[0][0] = 0; mat[0][1] = 0; mat[0][2] = 3;
    mat[1][0] = 4; mat[1][1] = 0; mat[1][2] = 0;
    mat[2][0] = 0; mat[2][1] = 5; mat[2][2] = 0;
    Solution s;
    s.convertingIntoSparseMatrix(mat);
    return 0;
}