class Solution {
public:
    int canBeTypedWords(string s, string bb) {
        int ans = 0;
        int k = 0;
        int wrdc = 0;
        while (k <= s.length()) {
            bool ok = false;
            while (k < s.length() && s[k] != ' ') {
                for (int i = 0; i < bb.length(); i++) {
                    if (s[k] == bb[i]) ok = true;
                }
                k++;
            }
            if (!ok) ans++;
            wrdc++;
            k++; 
        }
        return ans;
    }
};
