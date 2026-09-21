class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int count = 0;
        int maxCount = 0;
        int start = 0;

        for (int i = 0; i < s.length(); i++) {

            mp[s[i]]++;

            while (mp[s[i]] > 1) {
                mp[s[start]]--;
                start++;
            }

            count = i - start + 1;
            maxCount = max(maxCount, count);
        }

        return maxCount;
    }
};