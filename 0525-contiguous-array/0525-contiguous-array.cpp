class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>mp;
        mp[0]=-1;

        int prefixSum = 0;
        int maxi = 0;
        for(int i =0;i<nums.size();i++)
        {
            if(nums[i]==0) prefixSum--;
            else prefixSum++;

            if(mp.find(prefixSum)!= mp.end())
            {
                maxi = max(maxi,i-mp[prefixSum]);
            }
            else{
                mp[prefixSum] = i;
            }
        }
        return maxi;
    }

};