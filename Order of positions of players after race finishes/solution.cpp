// Given an array A, where A[i] = j denotes the fact that player j finished the race before player i, and for the winner of race let's  say player k, A[k]=-1.  
// You need to print the order of the positions of players after race finishes

// Follow up: What if the data (array A) got courrupted, how will you take care of that. Return  -1 if there data is courrupted and order of player otherwise.

#include<bits/stdc++.h>
using namespace std;

class Race{
    vector<int> before_after_vec;
    map<int, int> before_after_hm;
public:
    Race(vector<int> before_after_vec){
        this->before_after_vec = before_after_vec;
    }

    void genOrderOfPositions(){
        for(int i=0; i<before_after_vec.size(); i++){
            int before_player_num = before_after_vec[i];
            int after_player_num = i;
            before_after_hm[before_player_num] = after_player_num;
        }

        int curr_player_num = before_after_hm[-1];
        cout<<curr_player_num<<" ";
        while (1){
            if(before_after_hm.find(curr_player_num) == before_after_hm.end())
                break;
            curr_player_num = before_after_hm[curr_player_num];
            cout<<curr_player_num<<" ";
        }
    }
};

int main(){
    // race results: 2, 3, 0, 4, 1
    vector<int> before_after_vec = {3, 4, -1, 2, 0};
    
    Race obj1(before_after_vec);
    obj1.genOrderOfPositions();

}