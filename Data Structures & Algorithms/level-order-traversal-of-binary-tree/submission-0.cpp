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





    std::vector<vector<int>> result; //return

            if(root == nullptr)
        {
            return result;
        }
    std::queue<TreeNode*> bfs; //bfs




    TreeNode* current = nullptr;
    bfs.push(root);


    while(!bfs.empty())
    {
    int size = bfs.size();  
    std::vector<int> level;
    for(int i = 0; i < size; i++)
    {   current = bfs.front();
        bfs.pop();
        level.push_back(current->val);
        
        if(current->left != nullptr)
        {   
            bfs.push(current->left);           
        }
        if(current->right != nullptr)
        {
            bfs.push(current->right);
        }


        
              
    }

        result.push_back(level);
    }

        return result;
        
        
    }
};
