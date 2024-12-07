#include <iostream>
#include <vector>
using namespace std;
int recKnapSack01(vector<int> &wt,vector<int> &price,int w,int n){
          
          if(w==0 || n==0)
          return 0;

          int take = 0;
          if(w-wt[n-1]>=0)
          take = price[n-1] + recKnapSack01(wt,price,w-wt[n-1],n-1);

          int nontake = recKnapSack01(wt,price,w,n-1);

          return max(take,nontake);
}
int memoRecKnapSack(vector<int> wt,vector<int> price,int w,int n,vector<vector<int>> &dp){
        
         if(w==0 || n==0)
          return 0;
          
          if(dp[n][w]!=-1)
          return dp[n][w];

          int take = 0;
          if(w-wt[n-1]>=0)
          take = price[n-1] + recKnapSack01(wt,price,w-wt[n-1],n-1);

          int nontake = recKnapSack01(wt,price,w,n-1);

          return dp[n][w] = max(take,nontake);
}

int topDown(vector<int> wt,vector<int> price,int w,int n){
     
        vector<vector<int>> dp(n+1,vector<int>(w+1,0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=w;j++){
                
                int take = 0;

                if(j-wt[i-1]>=0)
                take = price[i-1] + dp[i-1][j-wt[i-1]];

                int nontake = dp[i-1][j];

                dp[i][j] = max(take,nontake);
            }
        }

        return dp[n][w];
}
int main(){

       vector<int> wt,price;
       int weight = 15;
       wt = {5,2,6,7,10};
       price = {3,4,7,2,8};
       

       cout<< recKnapSack01(wt,price,weight,5)<<endl;

       vector<vector<int>> dp(5+1,vector<int>(weight+1,-1));

       cout<< "memoized result is"<< memoRecKnapSack(wt,price,weight,5,dp)<<endl;
       
       cout<<"top down result is "<< topDown(wt,price,weight,5);

       return 0;
       
}

