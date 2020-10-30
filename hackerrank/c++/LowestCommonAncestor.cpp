/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
  
    Node *lca(Node *root, int v1,int v2) 
    {
	    
      // Corner case if root is NULL
        if(root==NULL)
        {
            return 0;
        }
        
        //If the value of root is equal to the nodes for which we need to find ancestors for then the possible LCA will be the root itself as there is nothing above the           root.
        if(root->data==v1||root->data==v2)
        {
            return root;
        }
        
        //Recur for both left side and right side for the tree.
        Node *lca1=lca(root->left,v1,v2);
        Node *lca2=lca(root->right,v1,v2);
        
        //If voth the values after recursion are not NULL then their LCA will always be the root
        if(lca1!=NULL && lca2!=NULL)
        {
            return root;
        }
      
        //If the left side of the tree is not NULL that means the ancestor will be present on the left side of the tree itself so the return value will also be the left part of the tree
        if(lca1!=NULL)
        {
            return lca1;
        }
        
        //If the right side of the tree is not NULL that means the ancestor will be present on the right side of the tree itself so the return value will also be the right part of the tree
        else
        {
            return lca2;
        }
    }
