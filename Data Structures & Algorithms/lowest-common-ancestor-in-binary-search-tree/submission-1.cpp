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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {


        TreeNode* current = root;

        while(current!=nullptr)
        {
        if(p->val < current-> val && q->val < current-> val)
        {
            // search in left side with similar checks
            current = current->left;

        }
        else if(p->val > current->val && q->val > current->val)
        {
            // search right side
            current = current-> right;
        }
        else 
        {   
            return current;
        }
        }
        
    }
};
