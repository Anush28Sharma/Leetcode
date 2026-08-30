class Solution {
public: 
    int helper(vector<int>&nums, int idx, int k,vector<vector<int>>&dp)
    
    {
        if(idx==0)
        {
            if(k==0 && nums[idx]==0) return 2;
            if(k==0 || nums[idx]==k) return 1;
            return 0;
        }
        if(dp[idx][k]!=-1) return dp[idx][k];
        int pick = 0;
        int notpick = helper(nums,idx-1,k,dp);
        if(nums[idx]<=k)
        {
            pick = helper(nums,idx-1,k-nums[idx],dp);
        }
        return dp[idx][k] = pick+notpick;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum =0;

        for(int i = 0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        if(sum-target<0) return 0;
        if((sum-target)%2!=0) return 0;
        int k = (sum - target)/2;
        vector<vector<int>>dp(nums.size(),vector<int>(k+1,-1));
        return helper(nums,nums.size()-1,k,dp);
        
    }
};