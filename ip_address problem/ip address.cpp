//Question: change string = "10.233.56.2" such that each '.' character is enclosed in '[' followed by ']'

#include <bits/stdc++.h>
#include <strings>
using namespace std;
int main(){
    string addr= "10.233.56.2";
    string output;

    for(int i=0; i<addr.length(); i++){
        if(addr[i] != '.')
            output += addr[i];
        else{
            output += '[';
            output += addr[i];
            output += ']';
        }
    }

    cout<<"IP address: "<<addr;
    cout<<"\nModified IP: "<<output;
}