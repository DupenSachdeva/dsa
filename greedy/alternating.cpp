#include<bits/stdc++.h>

using namespace std;

int find(string &s){

    int n = s.size();
    
    bool isAlternating = true;

    for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1]){
            isAlternating = false;
        }
    }

    if(isAlternating)
    return 0;

    int ones = 0;
    int zeroes = 0;

    for(auto it:s){
        if(it=='1')
        ones++;
        else
        zeroes++;
    }

    if(zeroes == ones || abs(zeroes - ones)==1)
    return 1;

    if(abs(zeroes-ones) <=3)
    return 2;

    return 3;
}
int main(){


    string s;
    cout<<"write alternating string";

    cin>>s;

    cout<<"ans is "<<find(s);
}