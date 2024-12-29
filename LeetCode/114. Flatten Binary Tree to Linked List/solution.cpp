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
        void flatten(TreeNode* root)
        {
            TreeNode *currNode = root;
            while(currNode != NULL)
            {
                if(currNode->left != NULL)
                {
                    TreeNode *rightmost = currNode->left;
                    while(rightmost->right != NULL)
                    {
                        rightmost = rightmost->right;
                    }
                    rightmost->right = currNode->right;
                    currNode->right = currNode->left;
                    currNode->left = NULL;
                }
                currNode = currNode->right;
            }
        }
};