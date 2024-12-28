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
        void storeNodes(TreeNode *root, std::vector<TreeNode*> &nodes)
        {
            if(root != NULL)
            {
                nodes.push_back(root);
                storeNodes(root->left, nodes);
                storeNodes(root->right, nodes);
            }
        }

    public:
        void flatten(TreeNode* root)
        {
            if(root != NULL)
            {
                std::vector<TreeNode*> nodes;
                storeNodes(root, nodes);
                for(int i = 0; i < nodes.size()-1; i++)
                {
                    nodes[i]->left = NULL;
                    nodes[i]->right = nodes[i+1];
                }
            }
        }
};