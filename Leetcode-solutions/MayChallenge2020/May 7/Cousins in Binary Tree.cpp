//It was a tough one!

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
    int xparent;
    int yparent;
    bool isCousins(TreeNode* root, int x, int y) {
       
        //int xparent;
        //int yparent;
        int D1=findDepth(root,x);
        cout<<D1<<endl;
        int D2=findDepth(root,y);
        cout<<D2<<endl;
        if(D1==D2)
        {
           // struct TreeNode* prev=NULL
            findxParent(root,x,-1);
           // cout<<P1<<endl;
            findyParent(root,y,-1);
            //cout<<P2<<endl;
            if(xparent==yparent)
                return false;
            return true;
        }
        return false;
    }
    int findDepth(struct TreeNode* root,int x)
    {
        return depth(root,x,1);
    }
    int depth(struct TreeNode* root,int x,int level)
    {
        if(root==NULL)
            return 0;
        if (root->val==x)
            return level;
        int downLevel= depth(root->left,x,level+1);
            if(downLevel!=0)
                return downLevel;
        downLevel= depth(root->right,x,level+1);
            return downLevel;
    }
    void findxParent(struct TreeNode* root,int x,int parent)
    {
        if(root==NULL)
            return ;
        if(root->val==x)
            xparent=parent;
        findxParent(root->left,x,root->val);
        findxParent(root->right,x,root->val);
      //  return 0;
/*        
        q<TreeNode*> que;
        struct TreeNode* curr;
        que.push(root);
        //que.push(NULL);
        curr=que.front();
        while(curr->val!=x)
        {
            curr=que.front();
            que.pop();
            if(curr->left!=NULL)
                que.push(curr->left);
            if(curr->right!=NULL)
                que->push(curr->right); */
        return;
        }
    void findyParent(struct TreeNode* root,int y,int parent)
    {
        if(root==NULL)
            return;
        if(root->val==y)
            yparent=parent;
        findyParent(root->left,y,root->val);
        findyParent(root->right,y,root->val);
        return;
    }
    
};
