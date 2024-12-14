#include<iostream>
#include<vector>
#include<map>
using namespace std;
int find(vector<vector<string>> &people , map<string,int> &skills ,int mask,int i , int curskills){
        
        if(i==-1)
            return curskills==mask ? 0 : 1e9;

        if(curskills==mask)
            return 0;
        
        int newskills = 0;
        for(int j=0;j<people[i].size();j++){
            
            int skillno = skills[people[i][j]];
            newskills = newskills | (1<<skillno);
            
        }
                                                                                    
        int take = 1 + find(people,skills,mask,i-1,(curskills | newskills));
        int nontake = find(people,skills,mask,i-1,curskills);
        
        return min(take,nontake);
    } 
int main() {
    vector<string> req_skills = {"java", "nodejs", "reactjs"};
    vector<vector<string>> people = {{"java"}, {"nodejs"}, {"nodejs", "reactjs"}};

    int n = req_skills.size();
    int mask = (1 << n) - 1; 

    map<string, int> skills;
    for (int i = 0; i < n; i++) {
        skills[req_skills[i]] = i;
    }

    vector<vector<int>> dp(people.size() + 1, vector<int>(mask + 1, 1e9)); 
    vector<int> ans; 

     for (int i = 0; i <= people.size(); i++) {
        dp[i][mask] = 0;
    }

    for (int i = 1; i <= people.size(); i++) {
        
        for (int curskill = 0; curskill <= mask; curskill++) {
            
            int newskills = 0;

            for (int j = 0; j < people[i - 1].size(); j++) {
                int skillno = skills[people[i - 1][j]];
                newskills |= (1 << skillno);
            }

            int take = 1 + dp[i - 1][curskill | newskills];
            int nontake = dp[i - 1][curskill];

            dp[i][curskill] = min(take, nontake);
        }
    }
        
        int curskill = 0;
        int i = people.size();
        
        while(curskill != mask){
            
            int newskills = 0;
            for(int j=0;j<people[i-1].size();j++){
                int skillno = skills[people[i-1][j]];
                newskills |= (1<<skillno) ;
            }
            
            int take = dp[i-1][curskill | newskills];
            int nontake = dp[i-1][curskill];
            
            if(take < nontake){
                ans.push_back(i-1);
                curskill |= newskills;
            }
            
            i--;
        }
        
        
       
        cout<<"people are"<<endl;
        for(auto it:ans)
         cout<<it<<endl;

    
    return 0;
}