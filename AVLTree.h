

#ifndef AVL_TREE_AVLTREE_H
#define AVL_TREE_AVLTREE_H


#include<iostream>
using namespace std;

class AVL
{
private:
    struct TreeNode
    {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };

    TreeNode* root = nullptr;
    AVL::TreeNode* helperInsert(TreeNode* helpRoot, int key);
    void helperInorder(TreeNode* helpRoot);
    void helperPreorder(TreeNode* helpRoot);
    void helperPostorder(TreeNode* helpRoot);
    int helperMaxDepth(TreeNode* helpRoot);
    bool helperUniqueElement(TreeNode* helpRoot, int key);

public:
    void inorder();
    void preorder();
    void postorder();
    void insert(int key);
    int maxDepth();
    bool uniqueElement(int key);
};


void AVL::helperInorder(AVL::TreeNode* helpRoot)
{
    if(helpRoot == nullptr)
        cout << "";
    else
    {
        helperInorder(helpRoot->left);
        cout << helpRoot->val << ", ";
        helperInorder(helpRoot->right);
    }
}

void AVL::helperPreorder(AVL::TreeNode* helpRoot)
{
    if(helpRoot == nullptr)
        cout << "";
    else
    {
        cout << helpRoot->val << ", ";
        helperPreorder(helpRoot->left);
        helperPreorder(helpRoot->right);
    }
}

void AVL::helperPostorder(AVL::TreeNode* helpRoot)
{
    if(helpRoot == nullptr)
        cout << "";
    else
    {
        helperPostorder(helpRoot->left);
        helperPostorder(helpRoot->right);
        cout << helpRoot->val << ", ";
    }
}


AVL::TreeNode* AVL::helperInsert(TreeNode* helpRoot, int key)
{

    if (helpRoot == nullptr)
        return new TreeNode(key);
    else if (key < helpRoot->val)
        helpRoot->left = helperInsert(helpRoot->left, key);
    else
        helpRoot->right = helperInsert(helpRoot->right, key);

    return helpRoot;
}

int AVL::helperMaxDepth(TreeNode* helpRoot)
{
    if (root == nullptr)
        return 0;
    else {
        /* compute the depth of each subtree */
        int leftDepth = helperMaxDepth(helpRoot->left);
        int rightDepth = helperMaxDepth(helpRoot->right);

        /* use the larger one */
        if (leftDepth > rightDepth)
            return (leftDepth + 1);
        else {
            return (rightDepth + 1);
        }
    }
}

bool AVL::helperUniqueElement(TreeNode* helpRoot, int key)
{
    if (helpRoot == nullptr)
    {
        return false;
    }
    if (helpRoot->val == key)
    {
        return true;
    }
    if (helpRoot->val < key)
    {
        return helperUniqueElement(helpRoot->right, key);
    }
    else
    {
        return helperUniqueElement(helpRoot->left, key);
    }
}


void AVL::inorder()
{
    helperInorder(this->root);
}

void AVL::preorder()
{
    helperPreorder(this->root);
}

void AVL::postorder()
{
    helperPostorder(this->root);
}

void AVL::insert(int key)
{
    this->root = helperInsert(this->root, key);

}


int AVL::maxDepth()
{
    return helperMaxDepth(this->root);
}

bool AVL::uniqueElement(int key)
{
    return helperUniqueElement(this->root, key);
}


#endif //AVL_TREE_AVLTb REE_H
