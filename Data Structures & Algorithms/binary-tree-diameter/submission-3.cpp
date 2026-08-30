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


        //longest path of connected edges

        int dfs(TreeNode* root, int& diameter)
        {
            if(root == nullptr)
            {
                return 0;
            }

            int leftDepth = dfs(root->left, diameter);
            int rightDepth = dfs(root->right, diameter);

            diameter = std::max(diameter, leftDepth + rightDepth);

            return 1+std::max(leftDepth, rightDepth);
        }



    int diameterOfBinaryTree(TreeNode* root) {

        //diameter integer to return
        if(root == nullptr)
        {
            return 0;
        }
        
        int diameter = 0;

        dfs(root, diameter);
        

        return diameter;





        
    }
};
