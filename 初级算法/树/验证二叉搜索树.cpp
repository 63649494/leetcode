/* 给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：

节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
	 bool isSmaller(int x,struct TreeNode *node)
	 {
		 if (node == NULL)
			 return true;
		 if (node->val >= x)
			 return false;
		 if (isSmaller(x, node->left) && isSmaller(x, node->right))
			 return true;
                 return false;
	 }
	 
	 bool isBigger(int x,struct TreeNode *node)
	 {
		 if (node == NULL)
			 return true;
		 if (node->val <= x)
			 return false;
		 if (isBigger(x, node->left) && isBigger(x, node->right))
			 return true;
                 return false;
	 }
    

    bool isValidBST(struct TreeNode* root) {
    if(!root)
        return true;
    if(root->left)
        printf("%d\n",root->left->val);
    if(root)
        printf("%d\n",root->val);
    if(root->right)
        printf("%d\n",root->right->val);
    if(!root->left&&!root->right)
            return true;
    if(root->left&&!root->right)
        if(root->left->val >= root->val)
            return false;
    if(!root->left&&root->right)
        if(root->val >= root->right->val)
            return false;
    if(root->left&&root->right)
        if(root->left->val >= root->val || root->val >= root->right->val)
            return false;
    if (!(isBigger(root->val, root->right) && isSmaller(root->val, root->left)))
            return false;
    if(root->left&&isValidBST(root->left)==false)
        return false;
    if(root->right&&isValidBST(root->right)==false)
        return false;
    return true;
}
 
 
 /* 本函数不完全的原因是没审好题，子树的所有节点都应该大于或小于根节点，之后加了个检测是否小大于的函数才好
bool isValidBST(struct TreeNode* root) {
    if(root->left)
        printf("%d\n",root->left->val);
    if(root)
        printf("%d\n",root->val);
    if(root->right)
        printf("%d\n",root->right->val);
    if(!root)
        return true;
    if(!root->left&&!root->right)
            return true;
    if(root->left&&!root->right)
        if(root->left->val >= root->val)
            return false;
    if(!root->left&&root->right)
        if(root->val >= root->right->val)
            return false;
    if(root->left&&root->right)
        if(root->left->val >= root->val || root->val >= root->right->val)
            return false;
    if(root->left&&isValidBST(root->left)==false)
        return false;
    if(root->right&&isValidBST(root->right)==false)
        return false;
    return true;
} */