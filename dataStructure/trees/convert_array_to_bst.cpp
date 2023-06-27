class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return bst(nums,0,nums.size()-1);
    }
    TreeNode* bst(std::vector<int>& nums,int start,int end){
        if(start>end){
            return NULL;
        }
        int mid = start+(end-start)/2;
        TreeNode* result = new TreeNode(nums[mid]);

        result->left=bst(nums,start,mid-1);
        result->right=bst(nums,mid+1,end);

        return result;
    }
};