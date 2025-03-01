//  given an array A , find the xor of all the subarrays in it and find the kth largest .

#include<iostream>
#include<map>
#include<vector>

using namespace std;

void addBits(vector<int> &bits , int no){

    for(int i=0;i<=10;i++){

         if(no & (1<<i))
         bits[i]++;
    }
}

int findOrValue(vector<int> &bits){
    int ans = 0;

    for(int i=0;i<=10;i++){
        if(bits[i] > 0){
            ans = ans | (1<<i);
        }
    }

    return ans;
}

void removeBits(vector<int> &bits , int no){

    for(int i=0;i<=10;i++){

        if(no & (1<<i))
        bits[i]--;
    }
}
int findSubArrays(vector<int> &arr , int k){
    vector<int> bits(11,0);

    int n = arr.size();

    int i = 1;
    int j = 1;
    int orValue = 0;

    int count = 0;
    while(j<n){

        addBits(bits,arr[j]);
        
        orValue = findOrValue(bits);

        while(orValue > k){

            removeBits(bits,arr[i]);

            orValue = findOrValue(bits);

            i++;
        }

        count += j - i + 1;

        j++;



    }

    return count;
}
int find(vector<int> &arr , int k){
    int n = arr.size();

    int smallestOr = 1e9;
    int maxOr = 0;

    for(auto it:arr){
    smallestOr = min(smallestOr,it);
    maxOr |= it;
   }

   int i = smallestOr;
   int j = maxOr;
   int mid = (i+j)/2;
   pair<int,int> ans = {1e9,1e9};

   while(i<=j){

       int subArrayCount = findSubArrays(arr,mid);
       
       if(subArrayCount == k)
       return mid;

       if(subArrayCount>k){
            ans = {subArrayCount , mid};
            j = mid-1;
       }

       else{
        i = mid+1;
       }

       mid = (i+j)/2;
   }

   return ans.second;

}
int main(){

    int n;
    cout<<"write arr size";
    cin>>n;

    vector<int> arr(n+1);

    cout<<"write array elements";

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    int k;
    cout<<"write k";
    cin>>k;
    

    cout<< " ans is " << find(arr , k);

}