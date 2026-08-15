class Solution {
public:
    string removeOccurrences(string s, string part) {
        string st;
        for(char ch:s)
        {
            st.push_back(ch);
            if(st.size()>=part.size())
            {
                bool match = true;
                for(int j = 0;j<part.size();j++)
                {
                    if(st[st.size()-part.size()+j]!=part[j])
                    {
                        match = false;
                        break;
                    }
                }

                if(match)
                {
                    for(int i =0;i<part.size();i++)
                    {
                        st.pop_back();
                    }

                }
            }
        }
        return st;
        
    }
};