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
#include <algorithm>

class Solution
{
    private:
        std::unordered_map<int, int> inMap;
        int postIdx = 0;

        TreeNode *constructTree(std::vector<int> &postorder, int startIdx, int endIdx)
        {
            if(startIdx > endIdx)
            {
                return NULL;
            }
            TreeNode *currNode = new TreeNode(postorder[postIdx]); 
            int inIdx = inMap[postorder[postIdx]];
            postIdx++;
            currNode->right = constructTree(postorder, inIdx+1, endIdx);
            currNode->left = constructTree(postorder, startIdx, inIdx-1);
            return currNode;
        }   

    public:
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
        {
            std::reverse(postorder.begin(), postorder.end());
            for(int i = 0; i < inorder.size(); i++)
            {
                inMap[inorder[i]] = i; 
            }
            return constructTree(postorder, 0, inorder.size()-1);
        }
};