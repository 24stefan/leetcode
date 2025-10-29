class Solution {
public:
    // Function to find the sum of three integers in nums
    // that is closest to the given target value.
    int threeSumClosest(vector<int>& nums, int target) {

        int n = nums.size();  
        // n stores the number of elements in the input vector 'nums'.

        std::sort(nums.begin(), nums.end());
        // Sort the array in ascending order.
        // Sorting helps us apply the two-pointer technique efficiently
        // because we can move pointers left/right based on comparison with target.

        int closestSum = 0;
        // This will store the sum of three numbers that is closest to 'target'.
        // Initially set to 0, but will be updated during iteration.

        int minDiff = INT_MAX;
        // This stores the minimum absolute difference between current sum and target.
        // Initialized to a very large value so that any real difference will be smaller.

        // Iterate over the array, fixing one element at a time.
        // 'i' represents the index of the first number in the triplet.
        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;
            // Two-pointer setup:
            // 'left' starts right after 'i'
            // 'right' starts at the end of the array.

            // While the two pointers do not cross:
            while (left < right) {

                int currentSum = nums[i] + nums[left] + nums[right];
                // Calculate the sum of the triplet (nums[i], nums[left], nums[right]).

                int currentDiff = std::abs(currentSum - target);
                // Compute how far this sum is from the target.

                if (currentDiff < minDiff) {
                    // If the new difference is smaller than the smallest difference so far:
                    minDiff = currentDiff;       // Update the smallest difference.
                    closestSum = currentSum;     // Update the closest sum.
                }

                if (currentSum < target) {
                    // If current sum is smaller than target, we need a bigger sum.
                    // Move the left pointer to the right (increase sum).
                    left++;
                } else {
                    // If current sum is greater than or equal to target,
                    // move the right pointer to the left (decrease sum).
                    right--;
                }
            }
        }

        return closestSum;
        // After checking all possible triplets, return the closest sum found.
    }
};

