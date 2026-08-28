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

        //right side edge basically, i want the nodes that would be visible from the right side of the tree.
        //i am planning to do a level order traversal, the last to enter the queue would be the right most edge of that level


        if(root == nullptr)
        {
            return {};
        }

        std::vector<int> output;

        std::queue<TreeNode*> bfs;

        TreeNode* current = nullptr;


        bfs.push(root);

        while(!bfs.empty())
        {   int size = bfs.size();

            for(int i = 0; i < size; i++)
            {
                current = bfs.front();
                bfs.pop();
                if(current->left != nullptr)
                {
                    bfs.push(current->left);
                }

                if(current->right)
                {
                    bfs.push(current->right);
                }

                if(i == size-1)
                {
                    output.push_back(current->val);
                }
                
            }
        }

        return output;


    }
};
