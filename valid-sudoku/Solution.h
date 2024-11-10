#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9];
        bool col[9];
        bool block[9];
        for(int i=0; i<9;i++){
            fill(row,row+9,false);
            fill(col,col+9,false);
            fill(block,block+9,false);
            for(int j=0;j<9;j++){
                //check row
                if(board[i][j]!='.'){
                    if(row[board[i][j]-'1']){
                        return false;
                    }
                    row[board[i][j]-'1']=true;
                }
                //check col
                if(board[j][i]!='.'){
                    if(col[board[j][i]-'1']){
                        return false;
                    }
                    col[board[j][i]-'1']=true;
                }
                //check block
                int r = 3*(i/3)+j/3;
                int c = 3*(i%3)+j%3;
                if(board[r][c]!='.'){
                    if(block[board[r][c]-'1']){
                        return false;
                    }
                    block[board[r][c]-'1']=true;
                }
            }
        }
        return true;
    }
};