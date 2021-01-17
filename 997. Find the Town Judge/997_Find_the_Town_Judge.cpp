// https://leetcode.com/submissions/detail/442924474/
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<pair<int, int>> result(N+1);
        
        for(int i=0; i<trust.size(); i++){
            result[trust[i][0]].first += 1;
            result[trust[i][1]].second += 1;
            
        }
        for(int i=1; i<result.size(); i++){
            cout<<result[i].first<<" "<<result[i].second<<"\n";
            if(result[i].first == 0 && result[i].second == N-1)
                return i;
        }
        return -1;
    }
};