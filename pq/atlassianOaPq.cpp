#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
using namespace std;

int find(vector<pair<int,int>> &arr, int n){
         
         sort(arr.begin() , arr.end() , [](pair<int,int> &a , pair<int,int> &b){

            return a.first < b.first;
         });

         map<int, priority_queue<int> > mp;
         map<int,int> sum;
         set<int> vis;

         for(int i=0;i<n;i++){

            
                mp[arr[i].first].push(arr[i].second);
                sum[arr[i].first] += arr[i].second; 
            
         }
         int ans = 0;
         for(int i = 0; i<n;i++){

            if(vis.find(arr[i].first) != vis.end())
            continue;

            int curNo = arr[i].first;

            priority_queue<int> pq;
            int prevSum = sum[arr[i].first];


            while(!mp[curNo].empty()){
                pq.push(mp[curNo].top());
                mp[curNo].pop();

                
            }
            mp.erase(curNo);
            

            while(pq.size() > 1){
                 
                 

                 ans += prevSum - pq.top();
                 prevSum -= pq.top();
                 pq.pop();

                 vis.insert(curNo);
                 curNo++;

                 if(mp.count(curNo)>0){
                        prevSum += sum[curNo];
                        while(!mp[curNo].empty()){
                         pq.push(mp[curNo].top());
                         mp[curNo].pop();
                        }
                          
                 }




            }

         }

         return ans;

}
int main(){
    
    vector<pair<int,int>> arr;

    int n ;

    cin>> n;

    for(int i=0;i<n;i++){
        int no,cost;
        cin>> no;
        cin>> cost;

        arr.push_back({no,cost});
    }

    cout<< "min. cost to make distinct elements is "<< find(arr,n);
    return 0;
}