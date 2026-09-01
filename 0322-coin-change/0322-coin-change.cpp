class Solution {
public:
    int helper(vector<int>&coins,vector<vector<int>>&dp,int idx , int amount){
        if(idx==0)
        {
            if(amount%coins[idx]==0) return amount/coins[idx];
              return 1e9;
        }
        if(dp[idx][amount]!=-1) return dp[idx][amount];
        int pick = 1e9;
        int notpick = 0+helper(coins,dp,idx-1,amount);
        if(coins[idx]<=amount)
        {
            pick= 1+helper(coins,dp,idx,amount-coins[idx]);
        }
        return dp[idx][amount] = min(pick,notpick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        if(amount==0) return 0;
        int ans = 0;
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        ans = helper(coins,dp,n-1,amount);
        return ans==1e9? -1: ans;
    }
};