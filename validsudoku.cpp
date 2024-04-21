#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>


using namespace std;


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char,bool> map;
        
        for(int i=0;i<9;i++){
            map['1'] = false;
            map['2'] = false;
            map['3'] = false;
            map['4'] = false;
            map['5'] = false;
            map['6'] = false;
            map['7'] = false;
            map['8'] = false;
            map['9'] = false;
            map['.'] = true;
            for(int j=0;j<9;j++){
                if(map[board[i][j]] && board[i][j] != '.'){
                    return false;
                }
                if(!map[board[i][j]]){
                    map[board[i][j]] = true;
                }
            }
        }


        for(int i=0;i<9;i++){
            map['1'] = false;
            map['2'] = false;
            map['3'] = false;
            map['4'] = false;
            map['5'] = false;
            map['6'] = false;
            map['7'] = false;
            map['8'] = false;
            map['9'] = false;
            map['.'] = true;
            for(int j=0;j<9;j++){
                if(map[board[j][i]] && board[j][i] != '.'){
                    return false;
                }
                if(!map[board[j][i]]){
                    map[board[j][i]] = true;
                }
            }
        }
        int row_index = -3;
        int column_index = -3;
        
        for(int i=0;i<9;i++){  
            column_index += 3;
            if(i % 3 == 0){
                row_index += 3;
                column_index = 0;
            }

            map['1'] = false;
            map['2'] = false;
            map['3'] = false;
            map['4'] = false;
            map['5'] = false;
            map['6'] = false;
            map['7'] = false;
            map['8'] = false;
            map['9'] = false;
            map['.'] = true;
            int inner_row = row_index;
            for(int y=0;y<3;y++){
                int inner_column = column_index;
                for(int k=0;k<3;k++){
                    if(map[board[inner_row][inner_column]] && board[inner_row][inner_column] != '.'){
                        return false;
                    }
                    if(!map[board[inner_row][inner_column]]){
                        map[board[inner_row][inner_column]] = true;
                    }
                    inner_column++;
                }
                inner_row++;
            }
        }
        
        return true;

        
    }
};
