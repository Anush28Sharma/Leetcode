class Solution {
public:
    int compress(vector<char>& chars) {
        int i =0;
        int j =0;
        int n= chars.size();
        while(j<n)
        {
            int start = j;
            while(j<n && chars[j]==chars[start]) j++;

            chars[i++] = chars[start];
            int count = j-start;

            if(count>1)
            {
                string st = to_string(count);
                for(auto x:st)
                {
                    chars[i++] = x;
                }
            }


        }
        return i;
    }

};