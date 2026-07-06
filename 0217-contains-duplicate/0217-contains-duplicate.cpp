class Solution {
public:
    bool containsDuplicate(vector<int>& arr) {
        int n = arr.size();
        if(n==1) return false;
        sort(arr.begin(),arr.end());
        for(int i =1;i<n;i++)
        {
            if(arr[i]==arr[i-1]) return true;
        }
        return false;
    }
};