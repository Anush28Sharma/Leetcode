class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>freq;
        int i =0;
        int k = 2;
        int j =0;
        int maxlen = 0;
        while(j<fruits.size())
        {
            int curr = fruits[j];
            freq[curr]++;
            while(freq.size()>k)
            {
                freq[fruits[i]]--;
                if(freq[fruits[i]]==0) freq.erase(fruits[i]);
                i++;
            }
            maxlen = max(maxlen,j-i+1);
            j++;
        }
        return maxlen;

    }
};