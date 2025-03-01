// givan an array of size n , find highest gcd for 3, 4, 5, 6, 7,......n numbers

#include<iostream>
#include<vector>
#include<map>
#include<math.h>

using namespace std;

void findFactors(int no , map<int,int> &mp){

    int sqrt_no = no/2;

    for(int i=1;i<=sqrt_no;i++){

        if(no%i==0){
            mp[i]++;
        }
    }
    mp[no]++;
}

vector<int> find(vector<int> &arr){
    
    int n = arr.size();

    map<int,int> mp;

    for(int i=0;i<n;i++){

        int no = arr[i];

        findFactors(no,mp);
    }

    vector<int> ans(n+1);

    auto it = mp.rbegin();
    
    int i=1;
    while(it!=mp.rend() && i<=n){

           if(it->second >= i){
            ans[i] = it->first;
            i++;
           }

           else{
            it++;
           }
    }

    return ans;
}
int main(){
    
    int n;
    cout<<"write array size";
    cin>>n;

    vector<int> arr(n);
    
    cout<<"write array values";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<int> ans = find(arr);

    cout<<"ans for gcd is";
    for(int i=1;i<=n;i++){
        cout<<endl<<"answer for "<<i<<"  ";
        cout<<ans[i];
    }
    return 0;
}