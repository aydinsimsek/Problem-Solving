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

#define MAX_VAL_AVAILABLE 100000
#define MIN_VAL_AVAILABLE 0

class Solution
{
    private:
        int minDiff = MAX_VAL_AVAILABLE - MIN_VAL_AVAILABLE;
        int prevVal = MIN_VAL_AVAILABLE - 1;

        void calculateMinDiff(TreeNode *root)
        {
            if(root != NULL)
            {
                calculateMinDiff(root->left);
                if(prevVal != MIN_VAL_AVAILABLE - 1)
                {
                    int currDiff = root->val - prevVal;
                    if(currDiff < minDiff)
                    {
                        minDiff = currDiff;
                    }
                }
                prevVal = root->val;
                calculateMinDiff(root->right);
            }
        }
 
    public:
        int getMinimumDifference(TreeNode* root)
        {
            calculateMinDiff(root);
            return minDiff;
        }
};