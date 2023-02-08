

#ifndef AVL_TREE_AVLTREE_H
#define AVL_TREE_AVLTREE_H


class TreeNode
{
public:
    long val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(long x){
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

TreeNode* insert(TreeNode* root, int data)
{
    if (root == nullptr)
        return new TreeNode(data);
    if (root->val < data)
        root->right = insert(root->right, data);
    else
        root->left = insert(root->left, data);
    return root;
}

int maxDepth(TreeNode* head)
{
    if (head == nullptr)
        return 0;
    else {
        /* compute the depth of each subtree */
        int leftDepth = maxDepth(head->left);
        int rightDepth = maxDepth(head->right);

        /* use the larger one */
        if (leftDepth > rightDepth)
            return (leftDepth + 1);
        else {
            return (rightDepth + 1);
        }
    }
}


#endif //AVL_TREE_AVLTREE_H
