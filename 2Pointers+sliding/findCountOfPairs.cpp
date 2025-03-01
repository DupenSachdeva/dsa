// find count of pairs such that L<= a[i] + a[j] <= R

#include<iostream>
#include<vector>


using namespace std;

int find(vector<int> &arr , int L){
     int n  = arr.size();


     int i = 0;
     int j = n-1;
     int count = 0;
     while(i<j){
          if(arr[i] + arr[j] > L){
            j--;
          }

          else{
            count += j - i;
            i++;
          }
     }

     return count;
}
int main(){
    
    int n;

    cout<<"enter array size";
    cin >> n; 

    vector<int> arr(n);

    for(int i=0;i<n;i++)
    cin >> arr[i];

    int R,L;
    
    cout<<"write L and R";
    cin>>L;
    cin>>R;

    cout<<"count of pairs is" << find(arr,R) - find(arr,L-1);
    return 0;
}