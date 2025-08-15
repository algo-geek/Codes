// given startTime, endTime and profit arrays, return maximum profit 

// if l->r, endpoints imp, ends sorted
// if r->l, strtpoints imp, starts sorted (here)
// standing at i, find lower bound of ith endtime- (just greater than equal to) 
// (to find first non overlapping interval)
// if one such interval found, all others after that interval will also not overlap with i
// idea: dp[i]=max(profit[i]+dp[nearest j which is non overlapping], dp[i+1]);


int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
     
        int n=profit.size();
        vector<int>dp(n+1,0);
      
        vector<tuple<int,int,int>>time;
        for(int i=0;i<n;i++)
        time.emplace_back(startTime[i], endTime[i], profit[i]);
        sort(time.begin(), time.end());
        sort(startTime.begin(), startTime.end());
        for(int i=n-1;i>=0;i--){
            int prev=lower_bound(startTime.begin(), startTime.end(), get<1>(time[i]))-startTime.begin();
            int prof=get<2>(time[i]);
            dp[i]=max(dp[i+1], dp[prev]+prof);
        }
        return dp[0];
    }
