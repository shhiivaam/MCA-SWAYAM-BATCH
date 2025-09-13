class Solution {
public:
    string frequencySort(string s) {
        vector<int> freq(128, 0);         //(nLogn)
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            freq[ch]++;  
        }
        vector<int> sortedFreq = freq;
        sort(sortedFreq.begin(), sortedFreq.end());
        reverse(sortedFreq.begin(), sortedFreq.end());
        string ans = "";
        for (int f : sortedFreq) {
            if (f > 0) {
                for (int i = 0; i < 128; i++) {
                    if (freq[i] == f) {
                        freq[i] = -1;
                        char ch = (char)i;
                        while (f--) ans += ch;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
