class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int res = 0;
        while(left<right)
        {
            int width = right - left;
            if(height[left]<height[right])
            {
                res = max(res,height[left] * width);
                left ++;
            }
            else
            {
                res = max(res,height[right] * width);
                right--;
            }
        }

        return res;
    }
};