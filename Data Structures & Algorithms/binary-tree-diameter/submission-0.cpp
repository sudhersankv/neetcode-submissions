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


    int findDepth(TreeNode *root, int &diameter)
    {

        //get the depth, and compute max diameter of the tree and return it, we use recursion here.
        if(root == nullptr)
        {
            return 0;
        }

        int leftDepth = findDepth(root->left, diameter);
        int rightDepth = findDepth(root->right, diameter);

        diameter = std::max(diameter, leftDepth + rightDepth);

        return 1+std::max(leftDepth, rightDepth);
    }

    int diameterOfBinaryTree(TreeNode* root) {

        int diameter = 0;

        findDepth(root, diameter);

        return diameter;

        //so we'd ideally want to find the max distance between any 2 nodes, we can say, distance = number of edges connecting them.

        //idea is, go to each end node leaf and then from there, increment count on back track, all routes, then find the max.




        
    }
};
