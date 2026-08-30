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

        //so since we need a level order traversal, a queue would be a good data structure as it lets us process layer by layer. like a bfs

        if(root == nullptr)
        {
            return {};
        }
        
        std::queue<TreeNode*> bfs;

        std::vector<std::vector<int>> result;

        TreeNode* current = root;

        bfs.push(current);

        while(!bfs.empty())
        {
            int size = bfs.size();
            std::vector<int> layer;

            for(int i = 0; i < size; i++)
            {
                current = bfs.front();
                layer.push_back(current->val);
                bfs.pop();

                if(current->left != nullptr)
                {
                    bfs.push(current->left);
                }
                if(current->right != nullptr)
                {
                    bfs.push(current->right);
                }
            }

            result.push_back(layer);
        }

        return result;






        
    }
};
