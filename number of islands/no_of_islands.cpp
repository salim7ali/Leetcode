// https://leetcode.com/problems/number-of-islands/

class Solution {
    int count =0;
public:
    void DFS(vector<vector<char>>& grid, int row, int col){
        vector<vector<int>> LTRB = {{row, col-1}, //leftI, leftJ
                                    {row-1, col},// topI, topJ
                                    {row, col+1,// rightI, rightJ
                                    {row+1,col},// downI, downJ
                                   };
        for(int k=0; k<LRTB.size(); k++){
           if(grid[LRTB[k][0]][LRTB[k][1]] == '1'){// if unvisited
               grid[LRTB[k][0]][LRTB[k][1]] = '2';// set to visited
               DFS(grid, i, j);
            }
        }

    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    count += 1;
                    // grid[i][j] = '2';
                    
                    DFS(grid, i, j);
                }        
            }
        }
    }
};