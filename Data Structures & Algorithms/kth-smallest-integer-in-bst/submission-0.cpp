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


    void dfs(TreeNode* r, int& count, int k, int& result)
    {
        if(r == nullptr)
        {
            return;
        }

        dfs(r->left, count, k, result);
        count++;
        if(count == k)
        {   
            result = r->val;
            return;
        }
        dfs(r->right, count, k, result);

    }


class Solution {
public:

    int count = 0;

    int kthSmallest(TreeNode* root, int k) {

        int count = 0;

        int result = 0;

        dfs(root, count, k, result);

        return result;




        
    }
};
