class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        if(p.size()>s.size()) return ans;

        vector<int>freq1(26,0);
        vector<int>freq2(26,0);

        for(int i =0;i<p.size();i++)
        {
            freq1[p[i]-'a']++;
        }

        int window  = p.size();
        for(int i =0;i<window;i++)
        {
            freq2[s[i]-'a']++;
        }

        if(freq1 ==freq2) {
            ans.push_back(0);
        }

        for(int i =window;i<s.size();i++)
        {
            freq2[s[i]-'a']++;
            freq2[s[i-window]-'a']--;
            if(freq1==freq2) {
                ans.push_back(i-window+1);
            }
        }
return ans;
    }
};