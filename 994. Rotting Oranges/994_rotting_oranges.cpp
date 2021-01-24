#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(int i, int j, int maxRow, int maxCol){
        if(i>=0 && i<maxRow && j>=0 && j<maxCol)
            return true;
        else
            return false;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int, int>, int>> Q;
        int maxTime =0;

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]==2)
                    Q.push({{i, j}, 0});
            }
        }

        int adj[4][2] = {{-1, 0}, {0, 1}, {1, 0},{0, -1}};

        while (!Q.empty()){
            int row = Q.front().first.first;
            int col = Q.front().first.second;
            int time = Q.front().second;
            // cout<<"(1)"<<row<<col<<time<<"\n";
            Q.pop();

            for(int i=0; i<4; i++){
                int rowAdj = row+adj[i][0];
                int colAdj = col+adj[i][1];
                
                // cout<<"(2)"<<rowAdj<<colAdj<<"\n";

                if(isValid(rowAdj, colAdj, grid.size(), grid[0].size()) && (grid[rowAdj][colAdj]==1)){
                    grid[rowAdj][colAdj]= 2;
                    Q.push({{rowAdj, colAdj}, time+1});
                    
                    maxTime = max(time+1, maxTime);
                }
            }
        }
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                // cout<<grid[i][j]<<" ";
                if(grid[i][j]==1)
                    return -1;
            }
        }
        return maxTime;
    }
    
    
};