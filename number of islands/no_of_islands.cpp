// https://leetcode.com/problems/number-of-islands/
#include <vector>
// #include<bits/stdc++.h>
#include<iostream>
using namespace std;
class Solution {
    int count =0;

    void DFS(vector<vector<char>>& grid, int row, int col){
        vector<vector<int>> LTRB = {{row, col-1}, //leftI, leftJ
                                    {row-1, col},// topI, topJ
                                    {row, col+1},// rightI, rightJ
                                    {row+1,col},// downI, downJ
                                   };
        for(int k=0; k<LTRB.size(); k++){
            if(0<=LTRB[k][0] && LTRB[k][0]<grid.size() && 0<=LTRB[k][1] && LTRB[k][1]<grid[0].size()){

                if(grid[LTRB[k][0]][LTRB[k][1]] == '1'){// if unvisited
                    grid[LTRB[k][0]][LTRB[k][1]] = '2';// set to visited
                    DFS(grid, LTRB[k][0], LTRB[k][1]);
                }
            }
        }
    }
public:

    void dispIslands(vector<vector<char>>& grid){
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                cout<<grid[i][j]<<' ';
            }
            cout<<'\n';
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    count += 1;

                    grid[i][j] = '2';
                    DFS(grid, i, j);
                }        
            }
        }
        return count;
    }
};

int main(){
   vector<vector<char>> grid = {{'1','1','0','0','0'},
                                {'1','1','0','0','0'},
                                {'0','0','1','0','0'},
                                {'0','0','0','1','1'}};
    
    Solution testCase1;

    cout<<"Before\n";
    testCase1.dispIslands(grid);
    cout<<"No of Islands:\n";
    cout<<testCase1.numIslands(grid);
    cout<<"After\n";
    testCase1.dispIslands(grid);
}