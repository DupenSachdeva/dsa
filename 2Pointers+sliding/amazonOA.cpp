// you are given an array , uniqueness value of an array is no of distinct elements in it , we have to put all these uniqueness values inside a new array , sort them ans find the median.


#include<iostream>
#include<vector>
#include<map>

using namespace std;

int countSubArrays(vector<int> &arr , int k){

    int n = arr.size();

    map<int,int> mp;

    int i = 0;
    int j = 0;
    int ans = 0;
    for( j=0,i=0;j<n;j++){

        mp[arr[j]]++;

        while(mp.size() > k){

            ans += j-i;
            mp[arr[i]]--;
            if(mp[arr[i]]==0)
            mp.erase(mp[arr[i]]);

            i++;
        }
    }

    while(i<n){
        ans += n-1-i;
        i++;
    }

    return ans;


}
int find(vector<int> &arr){
    
     int n = arr.size();
     int totalValues = (n*(n+1))/2;

     int ansValueno = (totalValues+1)/2;

     int i = 0;

     int j = n;
     
     int mid = (i+j)/2;
     vector<int> count(n+1,0);

     while(i<=j){

           count[mid] = countSubArrays(arr,mid);

           if(count[mid] == ansValueno)
           return mid;

           if(count[mid] > ansValueno){

               count[mid-1] = countSubArrays(arr,mid-1);
               if(count[mid-1] < ansValueno)
               return mid;

               if(count[mid-1] > ansValueno){
                j = mid-1;
               }
           }

           else if(count[mid] < ansValueno){
            i = mid+1;
           }
           mid = (i+j)/2;
     }

     return mid;

}
int main(){
    int n;
    cin>> n;
    cout<<"write array size";
    cin>>n ;

    vector<int> arr(n);
    for(int i=0;i<n;i++)
    cin>>arr[i];

    cout<<"ans is " << find(arr);

    return 0;
}