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
    private:
        void findKthSmallest(TreeNode *root, int &k, int &kthVal)
        {
            if(root != NULL)
            {
                findKthSmallest(root->left, k, kthVal);
                if(kthVal != -1)
                {
                    return;
                }
                if(--k == 0)
                {
                    kthVal = root->val;
                    return;
                }
                findKthSmallest(root->right, k, kthVal);
            }        
        }

    public:
        int kthSmallest(TreeNode* root, int k)
        {
            int kthVal = -1;
            findKthSmallest(root, k, kthVal);
            return kthVal;
        }
};