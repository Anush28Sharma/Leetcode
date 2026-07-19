class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>freq(128,0);
        int left = 0;
        int right = 0;
        int count = t.size();
        int start = 0;
        int minlen = INT_MAX;

        for(int i =0;i<t.size();i++)
        {
            freq[t[i]]++;
        }

        while(right<s.size())
        {
            if(freq[s[right]]>0)
            count--;

            freq[s[right]]--;
            right++;

            while(count==0)
            {
                if(right-left<minlen)
                {
                    minlen = right-left;
                    start =left;
                }

                freq[s[left]]++;

                if(freq[s[left]]>0)
                count++;

                left++;
            }
        }
        if(minlen ==INT_MAX) return"";
        return s.substr(start,minlen);
        
    }
};