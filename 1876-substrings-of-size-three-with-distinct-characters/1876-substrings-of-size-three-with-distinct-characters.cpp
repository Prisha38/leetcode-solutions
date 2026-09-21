class Solution {
public:
    int countGoodSubstrings(string s) {
        int count = 0;

        for (int i = 0; i + 2 < s.length(); i++) {
            unordered_map<char, int> mp;

            mp[s[i]]++;
            mp[s[i + 1]]++;
            mp[s[i + 2]]++;

            if (mp.size() == 3) {
                count++;
            }
        }

        return count;
    }
};