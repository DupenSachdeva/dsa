#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int findNextIndex(vector<vector<int>> &jobs, int i,int endTime){
        
        int last = jobs.size()-1;
        
        if(i>last)
            return last+1;
        
        int l = i;
        int r = last;
        
        
        while(l<=r)
        {
            int mid = (l+r)/2;
            
            if(jobs[mid][0]>=endTime)
                r=mid-1;
            
            else
                l=mid + 1;
            
            
        }
        
        return l;
    }
int main(){
        
        vector<int> startTime,endTime,profit;
        startTime = {1,2,3,3};
        endTime = {3,4,5,6};
        profit = {50,10,40,70};
        vector<vector<int>> jobs;
        int n = startTime.size();
        
        for(int i=0;i<n;i++)
            jobs.push_back({startTime[i],endTime[i],profit[i]});
        
        sort(jobs.begin(),jobs.end() , []( vector<int> &a,vector<int> &b){
            return a[0] < b[0];
        });
            
        vector<int> dp(n+1,0);
        
        for(int i=n-1;i>=0;i--){
            
            int nextIndex = findNextIndex(jobs,i+1,jobs[i][1]); 
            int take = jobs[i][2] + dp[nextIndex];
            
            int nontake = dp[i+1];
            
            dp[i] = max(take,nontake);
        }
        
        cout<<dp[0];
    return 0;
}