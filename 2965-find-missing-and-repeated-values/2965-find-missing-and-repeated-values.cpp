class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        long long total = n*n;

        long long expectedsum= (total*(total+1))/2;
        long long expectedsumsq=(total*(total+1)*(2*total+1))/6;

        long long actualsum = 0;
        long long actualsumsq = 0;

        for(int i =0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                long long val = grid[i][j];
                actualsum+=val;
                actualsumsq+=val*val;
            }
        }

        long long diff1 = actualsum-expectedsum;
        long long diff2 = actualsumsq-expectedsumsq;

        long long sumofnumbers = diff2/diff1;

        int missing=0;
        int repeated = 0;

        repeated= (sumofnumbers +diff1)/2;
        missing =sumofnumbers-repeated;
       

return {repeated,missing};

        
    }
};