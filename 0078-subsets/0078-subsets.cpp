class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int>>&ans, int i , vector<int>&val)
    {
       
        if(i==nums.size()){
            ans.push_back({val});
            return;
        }
        val.push_back(nums[i]);
        helper(nums,ans,i+1,val);
        val.pop_back();
        helper(nums,ans,i+1,val);
;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
         vector<int>val;
        helper(nums,ans,0,val);
        return ans;
    }
};