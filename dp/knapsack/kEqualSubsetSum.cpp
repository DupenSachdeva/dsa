#include<iostream>
#include<vector>

using namespace std;

bool find(vector<int> &arr,int curindex,int k,int mask,int ktotal,int sumToGenerate){
     
     if(k==0)
        return  true;
    

     int cursum = 0;
     int sum = 0;
     for(int i=0;i<arr.size();i++){
        if(mask & (1<<i))
        cursum += arr[i];

        sum += arr[i];
     }

     cursum = cursum - (ktotal-k)*sumToGenerate;

     if(cursum==sumToGenerate){
        return find(arr,0,k-1,mask,ktotal,sumToGenerate);
     }

     if(curindex == arr.size())
       return false;



     bool take = false;
     if(cursum + arr[curindex] <= sumToGenerate && !(mask & (1<<curindex))){

        take = find(arr,curindex+1,k,mask | 1<<curindex,ktotal,sumToGenerate);

     }

     bool nontake = find(arr,curindex+1,k,mask,ktotal,sumToGenerate);

     return take | nontake ;
}
int main(){

    vector<int> arr = {4,3,2,3,5,2,1};
    int k = 4;

    int sum = 0;

    for(auto it:arr)
    sum += it;
    
    int mask = 0;
    cout<< find(arr,0,k,mask,k,sum/k);
    return 0;
}