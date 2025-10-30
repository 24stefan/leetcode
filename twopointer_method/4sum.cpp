class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // Result container to store all unique quadruplets that sum up to the target
        vector<vector<int>> ans;

        // Sort the array to easily handle duplicates and apply the two-pointer technique
        sort(nums.begin(), nums.end());

        // Get the size of the input array
        int n = nums.size();

        // ----- OUTER LOOP (first element of quadruplet) -----
        for (int i = 0; i < n - 3; i++) {
            // Skip duplicates for the first element to avoid repeated quadruplets
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // ----- SECOND LOOP (second element of quadruplet) -----
            for (int j = i + 1; j < n - 2; j++) {
                // Skip duplicates for the second element
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                // Initialize two pointers for the remaining two elements
                int l = j + 1;       // left pointer (third number)
                int r = n - 1;       // right pointer (fourth number)

                // ----- TWO-POINTER SEARCH -----
                // Move 'l' and 'r' towards each other to find pairs that complete the quadruplet
                while (l < r) {
                    // Calculate the sum of the four selected numbers
                    // Cast to long long to prevent integer overflow for large inputs
                    long long sum = (long long)nums[i] + nums[j] + nums[l] + nums[r];

                    // If the sum exactly matches the target, we found a valid quadruplet
                    if (sum == target) {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});

                        // Skip duplicate values for the 3rd number
                        while (l < r && nums[l] == nums[l + 1]) l++;

                        // Skip duplicate values for the 4th number
                        while (l < r && nums[r] == nums[r - 1]) r--;

                        // Move both pointers inward after recording the valid quadruplet
                        l++;
                        r--;
                    }
                    // If the current sum is smaller than the target,
                    // we need a larger value → move the left pointer to the right
                    else if (sum < target) l++;

                    // If the current sum is larger than the target,
                    // we need a smaller value → move the right pointer to the left
                    else r--;
                }
            }
        }

        // Return the list of all unique quadruplets
        return ans;
    }
};

