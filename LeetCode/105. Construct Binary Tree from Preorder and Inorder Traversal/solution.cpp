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
#include <unordered_map>

class Solution
{
    private:
        std::unordered_map<int, int> inMap;

        TreeNode *constructTree(std::vector<int> &preorder, int &preIdx, int startIdx, int endIdx)
        {
            if(startIdx > endIdx)
            {
                return NULL;
            }
            TreeNode *currNode = new TreeNode(preorder[preIdx]); 
            int inIdx = inMap[preorder[preIdx]];
            preIdx++;
            currNode->left = constructTree(preorder, preIdx, startIdx, inIdx-1);
            currNode->right = constructTree(preorder, preIdx, inIdx+1, endIdx);
            return currNode;
        }   

    public:
        TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder)
        {
            int preIdx = 0;
            for(int i = 0; i < inorder.size(); i++)
            {
                inMap[inorder[i]] = i; 
            }
            return constructTree(preorder, preIdx, 0, inorder.size()-1);
        }
};