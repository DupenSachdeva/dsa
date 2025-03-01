#include<iostream>
#include<vector>
#include<map>

using namespace std;

int find(vector<int> &a , vector<int> &b){

    int n = a.size();

    int i = 0;
    int j = 0;

    int prevIndex = -1;

    map<int,int> mp;

    for(int i=0;i<n;i++)
    mp[b[i]] = i;

    int ans = 0;

    while(j<n){
        
        if(mp[a[j]] > prevIndex){
            prevIndex = mp[a[j]];

            j++;
            ans = max(ans , j - i );
        }
        else{
            i = j;
            prevIndex = -1;
        }

    }

    return n - ans;
}
int main(){
    
    int n , m;

    cout<<"write a size :";
    cin>>n;

   
    
    vector<int> a(n) , b(n);

    cout<<"write a elements";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    cout<<"write b elements";
    for(int i=0;i<n;i++){
        cin>>b[i];
    }

    cout<<"ans is "<<find(a,b);

    return 0;
}