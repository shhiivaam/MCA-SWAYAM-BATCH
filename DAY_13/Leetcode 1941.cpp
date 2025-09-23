class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int freq[26] = {0};
        for (char c : s) {
            freq[c - 'a']++;
        }
        int target = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) {
                target = freq[i];
                break;
            }
        }
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0 && freq[i] != target)
                return false;
        }
        return true;
    }
};
