class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n =s.size();
        int i =0;
        int j = 0;
        vector<int>freq(256,0);
        int maxlen =0;
        while(j<n)
        {
            int curr =s[j];
            while(freq[curr]>0)
            {
                freq[s[i]]--;
                i++;

            }
            maxlen = max(maxlen,j-i+1);
            freq[curr]++;
            j++;
        }
        return maxlen;
        
    }
};