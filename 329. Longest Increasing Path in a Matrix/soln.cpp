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
    
    void dfs(vector<vector<int>> &matrix, vector<vector<int>> &dp, int &maxPathLength, int i, int j){
        //                                  R      B      L      T
        vector<pair<int, int>> neighbor = {{0,1},{1,0},{0,-1},{-1,0}};
        bool neighborFound = false;

        for(int k=0; k<4; k++){
            int neighRow = i+neighbor[k].first;
            int neighCol = j+neighbor[k].second;
            
            if(isValid(neighRow, neighCol, matrix) == false)
                continue;
            
            if(dp[neighRow][neighCol] != INT_MIN  && (matrix[neighRow][neighCol]>matrix[i][j])){ // visited neighbor case
                dp[i][j] = max(dp[i][j], 1+dp[neighRow][neighCol]);
                neighborFound = true;   
            }else if((dp[neighRow][neighCol] == INT_MIN) && (matrix[neighRow][neighCol]>matrix[i][j])){ //not visited 
                dfs(matrix, dp, maxPathLength, neighRow, neighCol);
                neighborFound = true;
            }

            maxPathLength = max(maxPathLength, dp[i][j]);
        }
        if(neighborFound == false)
            dp[i][j] = 1;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ROWS = matrix.size();
        int COLS = matrix[0].size();
        vector<vector<int>> dp(ROWS, vector<int>(COLS, INT_MIN));

        int maxPathLength = 1;
        for(int i=0; i<ROWS; i++){
            for(int j=0; j<COLS; j++){
                // not visited
                if(dp[i][j] == INT_MIN){
                    dfs(matrix, dp, maxPathLength, i, j);
                }
            }
        }

        return maxPathLength;
    }
};