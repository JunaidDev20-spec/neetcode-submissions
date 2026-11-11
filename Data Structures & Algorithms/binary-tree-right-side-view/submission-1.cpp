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

    void solve(TreeNode* root , int level , vector<vector<int>>& levels){
        if(root == nullptr){
            return  ;

        }

      if(levels.size() == level){
        levels.push_back({}) ;

      }

      levels[level].push_back(root->val) ;

      solve(root->left , level + 1 , levels) ;
      solve(root->right , level + 1 , levels) ;


      
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>>levels ;
        vector<int> ans ;

         if(root == NULL){
            return {};
         }


         solve(root , 0  , levels) ;

         for(int  i = 0 ; i <levels.size() ; i++){
            ans.push_back(levels[i].back()) ;
         }

         return ans ;


         
    }
};
