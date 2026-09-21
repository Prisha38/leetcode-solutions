class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;

        int left = 0;
        int maxCount = 0;

        for (int right = 0; right < s.length(); right++) {

            // Add the new character
            mp[s[right]]++;

            // Remove characters until duplicate is gone
            while (mp[s[right]] > 1) {
                mp[s[left]]--;
                left++;
            }

            // Find current window length
            maxCount = max(maxCount, right - left + 1);
        }

        return maxCount;
    }
};