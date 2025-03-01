#include<iostream>
#include<vector>
#include<map>

using namespace std;

int find(vector<int> &arr , int k){

    int i = 1;
    int j = 1;
    int n = arr.size();
    
    int prevSum = 0;
    int cursum = 0;
    int totalSum = 0;
    while(j < n){

        prevSum += arr[j];
        
        while(prevSum > k){

            prevSum -= arr[i];
            cursum -= arr[i]*(j-i);
            totalSum += cursum;
            i++;
        }
        totalSum += prevSum;
        cursum += prevSum;

        j++;
        

    }

    return totalSum;
    
}
int main(){
 
    int n;
    cout<<"write array size";
    cin>>n;

    vector<int> arr(n+1);

    for(int i=1;i<=n;i++)
    cin>>arr[i];
    
    int k;
    cout<<"enter k";
    cin>>k;

    cout<<find(arr,k);

    return 0;
}