class Solution {
public:
        int maxi = 0;
        int mini = INT_MAX;
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        for(int i = 0;i<n;i++)
        {
            mini = min(mini,arr[i]);
            maxi = max(maxi,arr[i]-mini);
        }
        return maxi;
    }
};