// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

class Solution {
public:
    bool isValid(int neighRow, int neighCol, vector<vector<int>> &matrix){
        int ROWS = matrix.size();
        int COLS = matrix[0].size();

        if(neighRow>=0 && neighRow<ROWS && neighCol>=0 && neighCol<COLS)
            return true;
        return false;        
    }
    
    void dfs(vector<vector<int>> &matrix, vector<vector<int>> &dp, int &maxPathLength, int i, int j, vector<pair<int, int>> &neighbor){
        dp[i][j] = 1;

        for(int k=0; k<4; k++){
            int neighRow = i+neighbor[k].first;
            int neighCol = j+neighbor[k].second;
            
            // handles case when child looking at parent for traversal as well  
            if((isValid(neighRow, neighCol, matrix) == false) || (matrix[neighRow][neighCol]<=matrix[i][j]))
                continue;
            
            if(dp[neighRow][neighCol] != INT_MIN){ // visited neighbor case
                dp[i][j] = max(dp[i][j], 1+dp[neighRow][neighCol]);
            }else{ //   dp[neighRow][neighCol] == INT_MIN)  not visited case 
                dfs(matrix, dp, maxPathLength, neighRow, neighCol, neighbor);
                // update current as unvisited node/neighbor is resolved for dp
                dp[i][j] =  max(dp[i][j], 1+dp[neighRow][neighCol]);
            }

            // update after visiting every neighbor
            maxPathLength = max(maxPathLength, dp[i][j]);
        }
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ROWS = matrix.size();
        int COLS = matrix[0].size();
        vector<vector<int>> dp(ROWS, vector<int>(COLS, INT_MIN));
        //                                  R      B      L      T
        vector<pair<int, int>> neighbor = {{0,1},{1,0},{0,-1},{-1,0}};

        int maxPathLength = 1;
        for(int i=0; i<ROWS; i++){
            for(int j=0; j<COLS; j++){
                // not visited
                if(dp[i][j] == INT_MIN){
                    dfs(matrix, dp, maxPathLength, i, j, neighbor);
                }
            }
        }

        return maxPathLength;
    }
};