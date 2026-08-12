class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int ele;
        int count = 0;
        for(int i =0;i<n;i++)
        {
            if(count ==0)
            {
                ele = nums[i];
                count=1;
            }
            else if(ele==nums[i]) count++;
            else count--;
        }

        for(int i = 0;i<n;i++)
        {
            if(nums[i]==ele) ans++;
        }
        if(ans>n/2) return ele;
        return -1;
        
    }
};