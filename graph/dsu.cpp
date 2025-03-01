#include<iostream>
#include<vector>
#include<set>
using namespace std;

class dsu
{
private:
    /* data */
    vector<int> size;
    vector<int> parent;
public:

     dsu(int n){

        size.resize(n+1,1);

        parent.resize(n+1,0);

        for(int i=0;i<=n;i++)
        parent[i] = i;
     }

     void unionBySize(int n1,int n2){
        
        int p1 = findParent(n1);
        int p2 = findParent(n2);

        if(p1==p2)
        return ;

        int s1 = size[p1];
        int s2 = size[p2];
        if(s1 >= s2){
            
            parent[p2] = p1;
            size[p1] += size[p2]; 
           
        }

        else{

            parent[p1] = parent[p2];
            size[p2] += size[p1];
        }
     }

     int findParent(int node){
          if(parent[node] == node)
          return node;

          return parent[node] = findParent(parent[node]);
     }
    
};


int main(){
    
    int n;

    cout<<"write no of vertices";
    cin>>n;

    vector<pair<int,int>> edges;
    
    int m;
    cout<<"write no of edges";
    cin>>m;
    
    cout<<"enter edges";
    for(int i=1;i<=m;i++){
          int f,s;
          cin>>f;
          cin>>s;

          edges.push_back({s,f});
    }
    
    dsu ds1(n);
    for(auto it:edges){
           
        ds1.unionBySize(it.first,it.second);

    }

    set<int> components;

    for(int i=1;i<=n;i++){
        int p1 = ds1.findParent(i);
        if(components.find(p1)==components.end())
        components.insert(p1);
    }

    cout<<components.size();
    return 0;
}