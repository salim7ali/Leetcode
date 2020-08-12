// match given pattern to text and return index 

// trying to use hash to improve complexity
#include <bits/stdc++.h>
using namespace std;

int patIndex(string text, string pattern){
    int patHash = 0;
    int txtHash = 0;
    int k=0;
    bool match = false;
    
    for(int i=0; i<pattern.length(); i++){
        patHash += (int)(pattern[i]);
    }
    
    for(int i=0; i<pattern.length(); i++){
        txtHash += (int)(text[i]);
    }
    for(int i=1; i+pattern.length()<=text.length(); i++){
        txtHash -= (int)(text[i-1]);
        txtHash += (int)(text[i+pattern.length()-1]);
        if(txtHash == patHash){
            // for(int j=i; j<=i+pattern.length()-1){
            //     if(text[j] != pattern[k])
            //         match = false;
            //     if(match == true && )

            //     k += 1;
            // }
            return i;
        }
    }
    return -1;
}

int main(){
    string text = "Hi. I am priyanka";
    string pattern = "priya";

    cout<<patIndex(text, pattern);
}