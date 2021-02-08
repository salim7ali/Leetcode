class Solution {
    
public:
    
    int superEggDrop(int K, int N) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        vector<vector<int>> dp(K+1, vector<int> (N+1));
        
        for(int i=1; i<=K; i++){
            // dp[i][0] = 0;
            dp[i][1] = 1;
        }
        for(int j=2; j<=N; j++)
            dp[1][j] = j;
        
        for(int e=2; e<=K; e++){
            for(int f=2; f<=N; f++){
                
                int bestC;
                for(int currFloor=1; currFloor<=f; currFloor++){
                    int breaksAtFloorCount = dp[e-1][currFloor-1];
                    int survivesAtFloorCount = dp[e][f-currFloor];

                    int worstAtFloor = max(breaksAtFloorCount, survivesAtFloorCount);

                    if(currFloor==1)
                        bestC = worstAtFloor;
                    else
                        bestC = min(bestC, worstAtFloor);
                }
                dp[e][f] = 1+bestC;
            }
        }
        int result = dp[K][N];
        return result;
    }
};