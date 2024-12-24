/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <vector>

class Solution
{
    private:
        TreeNode *constructBST(std::vector<int> &nums, int startIdx, int endIdx)
        {
            if(startIdx > endIdx)
            {
                return NULL;
            }
            int midIdx = startIdx + (endIdx - startIdx) / 2;
            TreeNode *currNode = new TreeNode(nums[midIdx]);
            currNode->left = constructBST(nums, startIdx, midIdx-1);
            currNode->right = constructBST(nums, midIdx+1, endIdx);
            return currNode;
        }

    public:
        TreeNode* sortedArrayToBST(std::vector<int>& nums)
        {
            return constructBST(nums, 0, nums.size()-1);
        }
};