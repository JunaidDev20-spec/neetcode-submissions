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

   int maxi = 0 ;
   int maxDepth(TreeNode* root){
    if(root == NULL){
        return  0 ;

    }

    int leftH = maxDepth(root->left) ;
    int rightH = maxDepth(root->right) ;

    int currentDiameter = leftH + rightH ;
    maxi = max(maxi , currentDiameter) ;

    return 1 + max(leftH , rightH) ;
   }
    int diameterOfBinaryTree(TreeNode* root) {
        maxi = 0; 
        maxDepth(root) ;
        return maxi ;
    }
};
