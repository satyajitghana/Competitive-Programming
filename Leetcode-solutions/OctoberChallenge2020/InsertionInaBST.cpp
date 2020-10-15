class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
       //Corner Case if root's vaue is null
       if(!root)return new
       {
           TreeNode(val);
       }
        //If root's value is greater than the value to be inserted then it should be inserted on the right side as the value greater than the root are always placed at the right side (property of a BST)
        if(val>root->val)
        {
            root->right = insertIntoBST(root->right,val);
        }
        //If the value is smaller than insert it on the left side and at last return root's value
        else 
        {
            root->left = insertIntoBST(root->left,val);
        }
        return root;
    }
};
