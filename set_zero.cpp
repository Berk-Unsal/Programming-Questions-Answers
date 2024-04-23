#include <iostream>
#include <vector>



/*
    Set Matrix Zeroes
    
    Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

    You must do it in place.

*/

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int columns = matrix[0].size();

        vector<vector<bool>> records(rows,vector<bool>(columns,false));



        for(int i=0;i<rows;i++){
            for(int y=0;y<columns;y++){
                if(matrix[i][y] == 0 ){
                    records[i][y] = true;
                }
            }
        }
        
        for(int i=0;i<rows;i++){
            for(int y=0;y<columns;y++){
                if(records[i][y]){
                    for(int j=0;j<rows;j++){
                        matrix[j][y] = 0;
                    }
                    for(int j=0;j<columns;j++){
                        matrix[i][j] = 0;
                    }
                }
            }
        }
    }
};