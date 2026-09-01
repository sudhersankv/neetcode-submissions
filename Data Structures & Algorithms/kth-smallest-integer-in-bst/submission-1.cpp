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

    void inorder(TreeNode *current, int k, int& count, int& result)
    {
        if(current == nullptr)
        {
            return;
        }
        
        inorder(current->left, k, count, result);
        count++;
        if(count == k)
        {
            result = current->val;
        }
        inorder(current->right, k, count, result);
    }

    
    int kthSmallest(TreeNode* root, int k) {

        // idea is that, when we do an inorder traversal in a BST, we can always find the Kth element while doing inorder traversal to be the Kth smallest integer

        int count = 0;

        TreeNode* current = root;

        int result = 0;

        inorder(current, k, count, result);

        return result;



        //using a helper to traverse and do tyhe inorder for us


        
    }
};
