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
    vector<int> rightSideView(TreeNode* root) {

        std::vector<int> result;

        TreeNode* current = nullptr;
        std::queue<TreeNode*> bfs;

        if(root == nullptr)
        {
            return result;
        }

        bfs.push(root);
        // result.push_back(root->val);


        // binary level traversal

        while(!bfs.empty())
        {
            int size = bfs.size();

            for(int i = 0; i<size; i++)
            {   current = bfs.front();
                bfs.pop();
                
                if(current->left != nullptr)
                {
                    bfs.push(current->left);
                }

                if(current->right != nullptr)
                {
                    bfs.push(current->right);

                }
                if(i== size - 1)
                {
                    result.push_back(current->val);
                }

            }
        }
        return result;
        
        
    }
};
