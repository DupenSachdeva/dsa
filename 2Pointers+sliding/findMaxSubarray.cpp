// find max sub array length such that each element is distinct

#include<iostream>
#include<vector>
#include<map>

using namespace std;

int find(vector<int> &arr , int n){

    map<int,int> mp;

    int s = 0;
    int e = 0;
    int ans = 0;
    while(e<n){

        mp[arr[e]]++;
        while(mp.size() < e-s+1){

            mp[arr[s]]--;

            if(mp[arr[s]]==0)
            mp.erase(arr[s]);

            s++;
        }

        ans = max(ans , e - s + 1);
        e++;
    }
    return ans;
}
int main(){
    
    int n;
    vector<int> arr;

    cin >> n;

    for(int i=0;i<n;i++){
    int ele;
    cin>>ele;
    arr.push_back(ele);
    }

    cout<<"max subarray is" << find(arr,n);
   

    return 0;
}