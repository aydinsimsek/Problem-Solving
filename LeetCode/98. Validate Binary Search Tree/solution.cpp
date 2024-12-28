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

#include <climits>

class Solution
{
    private:
        void checkValidBST(TreeNode *root, long long int &prevVal, bool &result)
        {
            if(root != NULL)
            {
                checkValidBST(root->left, prevVal, result);
                if(prevVal >= root->val)
                {
                    result = false;
                    return;
                }
                prevVal = root->val;
                checkValidBST(root->right, prevVal, result);
            }
        }

    public:
        bool isValidBST(TreeNode* root)
        {
            long long int prevVal = LLONG_MIN;
            bool res = true;
            checkValidBST(root, prevVal, res);
            return res;
        }
};