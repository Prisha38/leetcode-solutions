
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int total = 0;

        int currMax = 0;
        int maxSum = nums[0];

        int currMin = 0;
        int minSum = nums[0];

        for (int x : nums) {

            // Maximum normal subarray
            currMax = max(x, currMax + x);
            maxSum = max(maxSum, currMax);

            // Minimum subarray
            currMin = min(x, currMin + x);
            minSum = min(minSum, currMin);

            total += x;
        }

        // All numbers are negative
        if (maxSum < 0)
            return maxSum;

        // Maximum circular subarray
        int circularSum = total - minSum;

        return max(maxSum, circularSum);
    }
};