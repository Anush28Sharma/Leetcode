class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0, j = 0, n = chars.size();

        while (j < n) {
            int start = j;

            while (j < n && chars[j] == chars[start])
                j++;

            chars[i++] = chars[start];

            int count = j - start;

            if (count > 1) {
                string s = to_string(count);
                for (char c : s)
                    chars[i++] = c;
            }
        }

        return i;
    }
};