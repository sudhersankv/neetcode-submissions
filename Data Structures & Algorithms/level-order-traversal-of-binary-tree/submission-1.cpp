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
    vector<vector<int>> levelOrder(TreeNode* root) {

        //queue for bfs
        //vector<int> for each level
        //vector<vector<int>> for final result
        //as we traverse we'll need a pointer to track and process current node





        TreeNode* current = nullptr;
        std::queue<TreeNode*> bfs;
        std::vector<vector<int>> result;


        if(root == nullptr)
        {
            return result;
        }

        bfs.push(root);

        while(!bfs.empty())
        {   
            int size = bfs.size();
            
            std::vector<int> level;
            for(int i = 0; i < size; i++)
            {   current = bfs.front();
                bfs.pop();
                if(current -> left != nullptr)
                {
                    bfs.push(current->left);
                }
                if(current->right != nullptr)
                {
                    bfs.push(current->right);
                }

                level.push_back(current->val);

            }
            result.push_back(level);
        }

        return result;
        
    }
};
