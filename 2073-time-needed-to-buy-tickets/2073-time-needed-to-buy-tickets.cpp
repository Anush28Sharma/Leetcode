class Solution {
public:
    int timeRequiredToBuy(vector<int>& arr, int k) {
        int n= arr.size();
     
        int ans =0;
        for(int i = 0;i<n;i++)
        {
            if(i<=k)
            {
                ans+=min(arr[i],arr[k]);

            }
            else{
                ans+=min(arr[i],arr[k]-1);
            }

        }
        
        return ans;
    }
};