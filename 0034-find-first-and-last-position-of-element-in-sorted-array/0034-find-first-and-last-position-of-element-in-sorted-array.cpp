class Solution {
public:


    int lower_bound(vector<int>& nums, int target)
    {
         int lo =0;
    int hi = nums.size()-1;
    int ans =hi+1;
    while(lo<=hi)
    {
        int mid = lo+(hi-lo)/2;
        if(nums[mid]>=target)
        {
            ans = mid;
            hi = mid-1;
        }
        else lo = mid+1;
    }
    return ans;
    }


     int upper_bound(vector<int>& nums, int target)
    {
         int lo =0;
    int hi = nums.size()-1;
    int ans =hi+1;
    while(lo<=hi)
    {
        int mid = lo+(hi-lo)/2;
        if(nums[mid]>target)
        {
            ans = mid;
            hi = mid-1;
        }
        else lo = mid+1;
    }
    return ans-1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
    int lo =0;
    int hi = 0;
    vector<int>ans;
    int val1 =-1;
    int val2 =-1;
     val1 = lower_bound(nums,target);
    if (val1 == nums.size() || nums[val1] != target)
        return {-1, -1};

     val2 = upper_bound(nums,target);
     ans.push_back(val1);
     ans.push_back(val2);
     return ans;

        
    }
};