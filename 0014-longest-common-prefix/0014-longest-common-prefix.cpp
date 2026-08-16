class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n= strs.size();
        string one = strs[0];
      
        for(int i = 1;i<n;i++)
        {
            int j = 0;
            while(j<one.size()&& j<strs[i].size()&& one[j]==strs[i][j]){
                j++;
            }
            one=one.substr(0,j);
        }
        return one;
    }
};