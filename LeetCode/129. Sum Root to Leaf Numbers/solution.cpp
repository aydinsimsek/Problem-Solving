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
#include <cmath>

class Solution
{
    private:
        void calculateSum(TreeNode *root, std::vector<int> &nums, int &sum)
        {
            nums.push_back(root->val);
            if(root->left == NULL && root->right == NULL)
            {
                for(int i = 0; i < nums.size(); i++)
                {
                    sum += nums[i] * pow(10, nums.size()-1-i);
                }
            }
            else
            {
                if(root->left != NULL)
                {
                    calculateSum(root->left, nums, sum);
                }
                if(root->right != NULL)
                {
                    calculateSum(root->right, nums, sum);
                }
            } 
            nums.pop_back();
        }

    public:
        int sumNumbers(TreeNode* root)
        {
            int sum = 0;
            std::vector<int> nums;
            calculateSum(root, nums, sum);
            return sum;
        }
};