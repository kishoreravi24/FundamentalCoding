class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int maxArea = 0;
        while(left<right){
            //Find height
            int cuurentHeight = std::min(height[left],height[right]);
            //Find width
            int width = right-left;
            //Find Area
            int area = width * cuurentHeight;
            //MaxArea
            maxArea = std::max(area,maxArea);

            if(height[left]<height[right]){
                left++;
            }else{
                right--;
            }
        }
        return maxArea;
    }
};