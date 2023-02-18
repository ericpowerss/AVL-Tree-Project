
#ifndef AVL_TREE_AVLTREE_H
#define AVL_TREE_AVLTREE_H

#include<iostream>
#include<vector>
using namespace std;

class AVL
{
public:

    // TreeNode struct that stores ID in val and student name in name
    struct TreeNode
    {
        string val;
        TreeNode *left;
        TreeNode *right;
        string name;
        int height;
        TreeNode(string x, string y)
        {
            val = x;
            name = y;
            left = nullptr;
            right = nullptr;
            height = 0;
        }
    };

    TreeNode* root = nullptr;
    TreeNode* helperInsert(TreeNode* helpRoot, string key, string name, bool& insertFlag);
    void helperInorder(TreeNode* helpRoot, bool& flag1);
    void helperPreorder(TreeNode* helpRoot, bool& flag2);
    void helperPostorder(TreeNode* helpRoot, bool& flag3);
    int helperMaxDepth(TreeNode* helpRoot);
    void helperSearchID (TreeNode* helpRoot, string key);
    void helperSearchName (TreeNode* helpRoot, string name, vector<string>& matchNodes);
    TreeNode* removeNodeHelper(TreeNode* node, string key, bool& flag);
    void returnVectorHelper(vector<TreeNode*>& nodeVector, TreeNode* node);
    void inorder(bool& flag1);
    void preorder(bool& flag2);
    void postorder(bool& flag3);
    void insert(string key, string name, bool& insertFlag);
    int maxDepth();
    int getHeight(TreeNode* node);
    void searchID(string key);
    vector<string> searchName(vector<string>& matchNodes, string name);
    int getBalanceFactor(TreeNode* root);
    void updateHeight(TreeNode *node);
    TreeNode* rotateRight(TreeNode* node);
    TreeNode* rotateLeft(TreeNode* node);
    void removeNode(string key, bool& flag);
    TreeNode* inOrderSuccessor(TreeNode* node);
    vector<TreeNode*> returnVector();
};

// Traverses Left, Node, Right
void AVL::helperInorder(AVL::TreeNode* helpRoot, bool& flag1)
{

    if(helpRoot == nullptr)
    {
        cout << "";
        return;
    }

    helperInorder(helpRoot->left, flag1);

    if (flag1)
    {
        cout << helpRoot->name;
        flag1 = false;
    }

    else
    {
        cout << ", " + helpRoot->name;
    }

    helperInorder(helpRoot->right, flag1);

}

// Traverses Node, Left, Right
void AVL::helperPreorder(AVL::TreeNode* helpRoot, bool& flag2)
{

    if(helpRoot == nullptr)
    {
        cout << "";
        return;
    }

    if (flag2)
    {
        cout << helpRoot->name;
        flag2 = false;
    }

    else
    {
        cout << ", " + helpRoot->name;
    }

    helperPreorder(helpRoot->left, flag2);
    helperPreorder(helpRoot->right, flag2);

}

// Traverses Left, Right, Node
void AVL::helperPostorder(AVL::TreeNode* helpRoot, bool& flag3)
{

    if(helpRoot == nullptr)
    {
        cout << "";
        return;
    }

    helperPostorder(helpRoot->left, flag3);
    helperPostorder(helpRoot->right, flag3);

    if (flag3)
    {
        cout << helpRoot->name;
        flag3 = false;
    }

    else
    {
        cout << ", " + helpRoot->name;
    }

}

AVL::TreeNode* AVL::helperInsert(TreeNode* helpRoot, string key, string name, bool& insertFlag)
{

    // If no node with key value exists, create new node
    if (helpRoot == nullptr)
    {
        return new TreeNode(key, name);
    }

    // If key passed in is less than current nodes value, travel left
    if (stol(key) < stol(helpRoot->val))
    {
        helpRoot->left = helperInsert(helpRoot->left, key, name, insertFlag);
    }

    // If key passed in is greater than current nodes value, travel right
    else if (stol(key) > stol(helpRoot->val))
    {
        helpRoot->right = helperInsert(helpRoot->right, key, name, insertFlag);
    }

    // Node with key value passed in already exists
    else
    {
        insertFlag = true;
        return helpRoot;
    }

    // Start balancing process
    updateHeight(helpRoot);
    int bf = getBalanceFactor(helpRoot);

    if (bf <= -2)
    {
        if (getBalanceFactor(helpRoot->right) >= 1)
        {
            //right-left
            helpRoot->right = rotateRight(helpRoot->right);
            return rotateLeft(helpRoot);

        }

        else
        {
            //right-right
            return rotateLeft(helpRoot);
        }

    }

    if (bf >= 2)
    {
        if (getBalanceFactor(helpRoot->left) <= -1)
        {
            //left-right
            helpRoot->left = rotateLeft(helpRoot->left);
            return rotateRight(helpRoot);

        }

        else
        {
            //left-left
            return rotateRight(helpRoot);
        }

    }

    return helpRoot;

}

// Used for finding max amount of levels within the tree
int AVL::helperMaxDepth(TreeNode* helpRoot)
{

    if (helpRoot == nullptr)
    {
        return 0;
    }

    else
    {
        // Computes the depth of each subtree
        int leftDepth = helperMaxDepth(helpRoot->left);
        int rightDepth = helperMaxDepth(helpRoot->right);

        // Takes the larger depth
        if (leftDepth > rightDepth)
        {
            return (leftDepth + 1);
        }
        else
        {
            return (rightDepth + 1);
        }

    }

}

// Preorder traversal for searching for a given ID
void AVL::helperSearchID(TreeNode* helpRoot, string key)
{

    if (helpRoot == nullptr)
    {
        cout << "unsuccessful" << endl;
        return;
    }
    if (helpRoot->val == key)
    {
        cout << helpRoot->name << endl;
        return;
    }
    if (stol(helpRoot->val) < stol(key))
    {
        return helperSearchID(helpRoot->right, key);
    }
    else
    {
        return helperSearchID (helpRoot->left, key);
    }

}

// Helper function that does a Preorder traversal and pushes back node ID into vector if name matches
void AVL::helperSearchName(TreeNode* helpRoot, string name, vector<string>& matchNodes)
{

    if (helpRoot == nullptr)
    {
        return;
    }

    if (helpRoot->name == name)
    {
        matchNodes.push_back(helpRoot->val);

    }

    helperSearchName(helpRoot->left, name, matchNodes);
    helperSearchName(helpRoot->right, name, matchNodes);

}

// 3 functions for traversals that pass to their respective helper functions
void AVL::inorder(bool& flag1)
{
    helperInorder(this->root, flag1);
}

void AVL::preorder(bool& flag2)
{
    helperPreorder(this->root, flag2);
}

void AVL::postorder(bool& flag3)
{
    helperPostorder(this->root, flag3);
}

// Passes to helper insert
void AVL::insert(string key, string name, bool& insertFlag)
{
    this->root = helperInsert(this->root, key, name, insertFlag);
}

// 2 functions for searching that passes to their respective helper functions
void AVL::searchID(string key)
{
    helperSearchID(this->root, key);
}

vector<string> AVL::searchName(vector<string>& matchNodes, string name)
{
    matchNodes.clear();
    helperSearchName(this->root, name, matchNodes);
    return matchNodes;
}

// Passes to helper maxDepth
int AVL::maxDepth()
{
    return helperMaxDepth(this->root);
}

// Returns balance factor of node, useful for balancing
int AVL::getBalanceFactor(AVL::TreeNode* root)
{

    if (root == nullptr)
    {
        return 0;
    }

    // left subtree - right subtree
    return getHeight(root->left) - getHeight(root->right);

}

// Updates height of node
void AVL::updateHeight(TreeNode* node) {

    if (root == nullptr)
    {
        return;
    }

    else
    {
        // computes the depth of each subtree
        int leftDepth = helperMaxDepth(root->left);
        int rightDepth = helperMaxDepth(root->right);

        // takes the larger depth
        if (leftDepth > rightDepth)
        {
            node->height = (leftDepth + 1);
        }
        else
        {
            node->height = (rightDepth + 1);
        }

    }

}

// Returns height of node
int AVL::getHeight(AVL::TreeNode *node)
{

    if (node == nullptr)
    {
        return 0;
    }

    else
    {
        return node->height;
    }

}

// Logic for rotating right for balancing
AVL::TreeNode* AVL::rotateRight(TreeNode* node)
{
    TreeNode* child = node->left;
    TreeNode* temp = child->right;
    child->right = node;
    node->left = temp;
    updateHeight(node);
    updateHeight(child);
    return child;
}

// Logic for rotating left for balancing
AVL::TreeNode* AVL::rotateLeft(TreeNode* node)
{
    TreeNode* child = node->right;
    TreeNode* temp = child->left;
    child->left = node;
    node->right = temp;
    updateHeight(node);
    updateHeight(child);
    return child;
}

// Passes to remove helper
void AVL::removeNode(string key, bool& flag)
{
    this->root = removeNodeHelper(this->root, key, flag);
}

// Finds Inorder successor, useful in deletion with two children
AVL::TreeNode *AVL::inOrderSuccessor(AVL::TreeNode *node)
{

    TreeNode* curr = node;
    while (curr->left != nullptr)
    {
        curr = curr->left;
    }

    return curr;

}

AVL::TreeNode* AVL::removeNodeHelper(AVL::TreeNode* node, string key, bool& flag) {

    if (node == nullptr)
    {
        return nullptr;
    }

    // If key passed in is less than current nodes value, travel left
    else if (stol(key) < stol(node->val))
    {
        node->left = removeNodeHelper(node->left, key, flag);
    }
    // If key passed in is greater than current nodes value, travel right
    else if (stol(key) > stol(node->val))
    {
        node->right = removeNodeHelper(node->right, key, flag);
    }

    // Node exists
    else
    {

        flag = true;

        // Case for no children
        if (node->left == nullptr && node->right == nullptr)
        {
            delete node;
            return nullptr;
        }

        // Case for 1 right child
        if (node->left == nullptr && node->right != nullptr)
        {
            TreeNode* temp = node->right;
            delete node;
            return temp;
        }

        // Case for 1 left child
        else if (node->right == nullptr && node->left != nullptr)
        {
            TreeNode* temp = node->left;
            delete node;
            return temp;
        }

        // Case for 2 children
        else
        {
            TreeNode* temp = inOrderSuccessor(node->right);
            node->val = temp->val;
            node->right = removeNodeHelper(node->right, temp->val, flag);
        }

    }

    // Start balancing process
    updateHeight(node);
    int bf = getBalanceFactor(node);

    if (bf <= -2)
    {
        if (getBalanceFactor(node->right) >= 1)
        {
            //right-left
            node->right = rotateRight(node->right);
            return rotateLeft(node);

        }

        else
        {
            //right-right
            return rotateLeft(node);
        }

    }

    if (bf >= 2)
    {
        if (getBalanceFactor(node->left) <= -1)
        {
            //left-right
            node->left = rotateLeft(node->left);
            return rotateRight(node);

        }

        else
        {
            //left-left
            return rotateRight(node);
        }

    }

    return node;

}

// passes to returnVector helper
vector<AVL::TreeNode*> AVL::returnVector()
{
    vector<TreeNode*> nodeVector{};
    returnVectorHelper(nodeVector, this->root);
    return nodeVector;
}

void AVL::returnVectorHelper(vector<TreeNode*>& nodeVector, TreeNode* node)
{

    if (node == nullptr)
    {
        return;
    }

    //Doing an Inorder traversal, pushes back each node in tree into a vector
    returnVectorHelper(nodeVector, node->left);
    nodeVector.push_back(node);
    returnVectorHelper(nodeVector, node->right);

}

#endif //AVL_TREE_AVLTb REE_H
