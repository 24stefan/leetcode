/*
 *name:  Container With Most Water
 * description: You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

 * */


//------------------------------------------------------------------------------------------------------------
//---------------------------------SOLUTION-------------------------------------------------------------------
class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int i = 0; // left pointer
        int j = height.size() - 1; // right pointer
        int res = 0; // max area found

        // calculate AREA:
            while (i < j) {
                res = max(res, (j - i) * min(height[i], height[j]));
                // two pointers in action
                if (height[i] < height[j]) i++;
                 else j--;
            }
              return res;
                }
};
