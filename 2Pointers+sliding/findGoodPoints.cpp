// giveb two array A and B , find good point in B  , a point is good if after removing that point , B becomes a subsequence of A.

#include<iostream>
#include<vector>

using namespace std;

void findPrefix(vector<int> &a , vector<int> &b , vector<int> &prefix){
    int n = a.size();
    int m = b.size();

    int i = 0;
    int j = 0;

    while(i<n && j<m){

        if(a[i] == b[j]){
            prefix[j] = i;
            j++;
        }

        i++;
    }
}

void findSuffix(vector<int> &a , vector<int> &b , vector<int> &suffix){
    int n = a.size();
    int m = b.size();

    int i = n-1;
    int j = m-1;

    while(i>=0 && j>=0){

        if(a[i] == b[j]){
            suffix[j] = i;
            j--;
        }

        i--;
    }
}
int find(vector<int> &a , vector<int> &b){

    int n = a.size();
    int m = b.size();
    
    vector<int> prefix(m,-1);
    vector<int> suffix(m,-1);

    findPrefix(a,b,prefix);

    findSuffix(a,b,suffix);
    
    int count = 0;
    for(int i=0;i<m;i++){
        int p = i-1>=0 ? prefix[i-1] : -2;
        int s = i+1<m ? suffix[i+1] : m;

        if(p!=-1 && s!=-1 && p < s)
        count++;
    }
    return count;

}
int main(){
      
    int n,m;

    cout<<"write a size";
    cin>>n;

    cout<<"write b size";
    cin>>m;
    
    vector<int> a(n);
    vector<int> b(m);
    cout<<"write a ele";
    for(int i=0;i<n;i++)
    cin>>a[i];

    cout<<"write b elements";
    for(int i=0;i<m;i++)
    cin>>b[i];

    cout<<"good points in b are"<<find(a,b);
}