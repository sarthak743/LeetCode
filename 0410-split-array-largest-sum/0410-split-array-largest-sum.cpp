//cleaned code by gpt

class Solution {
public:
    // Returns true if we can split the array into at most
    // 'maxSubarrays' subarrays such that each subarray sum
    // does not exceed 'maxAllowedSum'.
    bool isPossible(int maxAllowedSum, vector<int>& nums, int maxSubarrays) {
        int currentSum = 0;
        int subarrayCount = 1;     // first subarray

        for (int num : nums) {
            currentSum += num;

            // Need to start a new subarray
            if (currentSum > maxAllowedSum) {
                subarrayCount++;
                currentSum = num;
            }
        }

        return subarrayCount <= maxSubarrays;
    }

    int splitArray(vector<int>& nums, int k) {
        // Minimum possible answer is the largest element.
        int low = *max_element(nums.begin(), nums.end());

        // Maximum possible answer is the sum of all elements.
        int high = accumulate(nums.begin(), nums.end(), 0);

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isPossible(mid, nums, k))
                high = mid - 1;
            else
                low = mid + 1;
        }

        // First feasible answer.
        return low;
    }
};