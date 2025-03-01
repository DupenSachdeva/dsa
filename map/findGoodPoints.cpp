#include<iostream>
#include<vector>
#include<map>

using namespace std;
int find(vector<pair<int,int>> &points , int n){

    map<int,pair<int,int>> hori;

    map<int,pair<int,int>> ver;

    for(auto it:points){
        int x = it.first;
        int y = it.second;
        if(ver.count(x)){
            if(y>ver[x].first)
            ver[x].first = y;

            if(y<ver[x].second)
            ver[x].second = y;
        }

        else{
            ver[x] = {y,y};
        }

        if(hori.count(y)){
            
            if(x > hori[y].first)
            hori[y].first = x;

            if(x<hori[y].second)
            hori[y].second = x;

        }

        else{
            hori[y] = {x,x};
        }
    }

    int ans = 0;

    for(auto it:points){

        int x = it.first;
        int y = it.second;

        if(x!=hori[y].first && x!=hori[y].second && y!=ver[x].first && y!=ver[x].second)
        ans++;
    }

    return ans;
}
int main(){
    int n;
    cin >>n;

    cout<<"write no of points";

    vector<pair<int,int>> points ;

    for(int i=0;i<n;i++){
        int x;
        cout<<"x";
        cin>>x;
        
        int y;
        cout<<"y";
        cin>>y;

        points.push_back({x,y});
    }

    cout<<"good points are"<<find(points , n);
}