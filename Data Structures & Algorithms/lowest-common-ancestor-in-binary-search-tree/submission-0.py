# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        
        x = root

        while x:
            if p.val < x.val and q.val < x.val:
                x = x.left
            elif p.val > x.val and q.val > x.val:
                x = x.right
            else:
                return x