

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int sum = 0;

        // First k elements
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }

        int maxSum = sum;

        // Slide the window
        int j=0;
        for (int i = k; i < nums.size(); i++) {

            sum = sum - nums[j] + nums[i];

            maxSum = max(maxSum, sum);

            j++;
        }

        return (double)maxSum / k;
    }
};