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
   int depth(TreeNode* root){
    if(root == NULL){
        return 0 ;

    }

    int leftm = depth(root->left) ;
    int rightm = depth(root->right) ;

    return 1 + max(leftm , rightm) ;
   }
    bool isBalanced(TreeNode* root) {
        if(root == NULL){
            return true ;
        }
        
        
        int lefth = depth(root->left) ;
        int righth = depth(root->right) ;

        if(abs(lefth - righth) > 1) {
            return false ;
        }

        return isBalanced(root->left) && isBalanced(root->right) ;

       
    }
};
