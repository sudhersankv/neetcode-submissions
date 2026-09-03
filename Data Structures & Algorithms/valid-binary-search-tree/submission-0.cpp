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

class Solution {
public:


    bool dfs(TreeNode* current, int& prev)
    {
        if(current == nullptr)
        {
            return true;
        }

        if(!dfs(current->left,prev))
        {
            return false;
        }

        if(current->val <= prev)
        {
            return false;
        }

        prev = current->val;

        return dfs(current->right, prev);
    }
    bool isValidBST(TreeNode* root) {

        int prev = INT_MIN;

        return dfs(root, prev);
        
    }
};
