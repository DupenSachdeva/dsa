#include<iostream>

#include<vector>
#include<stack>
using namespace std;

int find(string s){

    stack<char> st;

    int n = s.size();
    int ans = 0;
    for(int i=0;i<n;i++){

        if(s[i] == 'x'){

            if(!st.empty() && st.top() == 'y')
            ans++;


            else
            st.push('x');

        }

        if(s[i] == 'y'){
            
            if(st.empty() || st.top() == 'y' || st.top() == 'z')
            st.push('y');

            else{

             while(!st.empty() && st.top() == 'x'){
                st.pop();
                ans++;
             }

             st.push('z');

            
        }
            
        }

    }

    return ans;

}
int main(){
    
    string s;

    cout<<"write string";
    cin>> s;

    cout<<"power is " << find(s);
    return 0;
}