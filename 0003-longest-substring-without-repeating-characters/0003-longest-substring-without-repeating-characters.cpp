class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int count = 0;
        int maxCount = 0;
        int j = 0;

        for (int i = 0; i < s.length(); i++) {

            mp[s[i]]++;

            while (mp[s[i]] > 1) {
                mp[s[j]]--;
                j++;
            }

            count = i - j + 1;
            maxCount = max(maxCount, count);
        }

        return maxCount;
    }
};