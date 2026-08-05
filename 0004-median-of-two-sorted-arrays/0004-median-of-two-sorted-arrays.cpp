//too complex to understand 
//skip it for most of the time
//optimal solution is BINARY SEARCH
//this is cleaner version

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        // Always perform binary search on the smaller array.
        // This keeps the time complexity O(log(min(n1, n2))).
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int n1 = nums1.size();
        int n2 = nums2.size();

        int low = 0;
        int high = n1;

        while (low <= high) {

            // Partition (cut) position in first array.
            int cut1 = low + (high - low) / 2;

            // Partition position in second array.
            // Total elements on the left side should be (n1+n2+1)/2.
            int cut2 = (n1 + n2 + 1) / 2 - cut1;

            // Elements immediately left of both partitions.
            int left1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int left2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];

            // Elements immediately right of both partitions.
            int right1 = (cut1 == n1) ? INT_MAX : nums1[cut1];
            int right2 = (cut2 == n2) ? INT_MAX : nums2[cut2];

            // Correct partition found.
            if (left1 <= right2 && left2 <= right1) {

                // Even total number of elements.
                if ((n1 + n2) % 2 == 0) {
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                }

                // Odd total number of elements.
                return max(left1, left2);
            }

            // We have taken too many elements from nums1.
            if (left1 > right2) {
                high = cut1 - 1;
            }

            // We have taken too few elements from nums1.
            else {
                low = cut1 + 1;
            }
        }

        // This line is never reached.
        return 0.0;
    }
};