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
    bool isSameTree(TreeNode* p, TreeNode* q) {

        //same height, same leafs per node, same value in each leaf\
        
        if(p == nullptr && q == nullptr)
        {
            return true;
        }
        else if(p == nullptr || q == nullptr || p->val != q->val)
        {
            return false;
        }

        bool leftcheck = isSameTree(p->left, q->left);
        bool rightcheck = isSameTree(p->right, q->right);

        return leftcheck && rightcheck;
        
    }
};
