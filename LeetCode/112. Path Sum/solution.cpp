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

class Solution
{
    public:
        bool hasPathSum(TreeNode* root, int targetSum)
        {
            if(root == NULL)
            {
                return false;
            }
            else if(root->left == NULL && root->right == NULL)
            {
                if(targetSum - root->val == 0)
                {
                    return true;
                }
                return false;
            }
            else
            {
                if(root->left != NULL && hasPathSum(root->left, targetSum - root->val))
                {
                    return true;
                }
                if(root->right != NULL && hasPathSum(root->right, targetSum - root->val)) 
                {
                    return true;
                } 
            }
            return false;
        }
};