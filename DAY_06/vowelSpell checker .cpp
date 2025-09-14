#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_set<string> exactSet;
    unordered_map<string, string> caseMap;
    unordered_map<string, string> vowelMap;

    string toLower(const string &s) {
        string res = s;
        for (char &c : res) c = tolower(c);
        return res;
    }

    string maskVowels(const string &s) {
        string res = s;
        for (char &c : res) {
            char lower = tolower(c);
            if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u')
                c = '*';
            else
                c = lower;
        }
        return res;
    }

public:
    vector<string> spellchecker(vector<string> &wordlist, vector<string> &queries) {
        exactSet.clear();
        caseMap.clear();
        vowelMap.clear();
        for (const string &word : wordlist) {
            exactSet.insert(word);

            string lower = toLower(word);
            if (!caseMap.count(lower)) caseMap[lower] = word;

            string masked = maskVowels(word);
            if (!vowelMap.count(masked)) vowelMap[masked] = word;
        }
        vector<string> result;
        for (const string &q : queries) {
            if (exactSet.count(q)) {
                result.push_back(q);
                continue;
            }

            string lowerQ = toLower(q);
            if (caseMap.count(lowerQ)) {
                result.push_back(caseMap[lowerQ]);
                continue;
            }

            string maskedQ = maskVowels(q);
            if (vowelMap.count(maskedQ)) {
                result.push_back(vowelMap[maskedQ]);
                continue;
            }

            result.push_back("");
        }
        return result;
    }
};
