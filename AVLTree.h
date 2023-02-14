

#ifndef AVL_TREE_AVLTREE_H
#define AVL_TREE_AVLTREE_H


#include<iostream>
#include<vector>
using namespace std;

class AVL
{
private:
    struct TreeNode
    {
        string val;
        int balanceFactor;
        TreeNode *left;
        TreeNode *right;
        string name;
        TreeNode(string x, string y)
        {
            val = x;
            name = y;
            left = nullptr;
            right = nullptr;
            balanceFactor = 0;
        }
    };

    TreeNode* root = nullptr;
    AVL::TreeNode* helperInsert(TreeNode* helpRoot, string key, string name);
    void helperInorder(TreeNode* helpRoot);
    void helperPreorder(TreeNode* helpRoot);
    void helperPostorder(TreeNode* helpRoot);
    int helperMaxDepth(TreeNode* helpRoot);
    //bool helperUniqueElement(TreeNode* helpRoot, string key);
    void helperSearchID (TreeNode* helpRoot, string key);
    void helperSearchName (TreeNode* helpRoot, string name, vector<string>& matchNodes);

public:
    void inorder();
    void preorder();
    void postorder();
    void insert(string key, string name);
    int maxDepth();
    //bool uniqueElement(string key);
    void searchID(string key);
    vector<string> searchName(vector<string>& matchNodes, string name);
};


void AVL::helperInorder(AVL::TreeNode* helpRoot)
{

    static bool oneNodeCheck = true;

    if(helpRoot == nullptr)
    {
        return;
    }

    helperInorder(helpRoot->left);

    if (oneNodeCheck)
    {
        cout << helpRoot->val;
        oneNodeCheck = false;
    }

    else
    {
        cout << ", " + helpRoot->val;
    }

    helperInorder(helpRoot->right);

}

void AVL::helperPreorder(AVL::TreeNode* helpRoot)
{

    static bool oneNodeCheck = true;

    if(helpRoot == nullptr)
    {
        return;
    }

    if (oneNodeCheck)
    {
        cout << helpRoot->val;
        oneNodeCheck = false;
    }

    else
    {
        cout << ", " + helpRoot->val;
    }

    helperPreorder(helpRoot->left);
    helperPreorder(helpRoot->right);

}

void AVL::helperPostorder(AVL::TreeNode* helpRoot)
{

    static bool oneNodeCheck = true;

    if(helpRoot == nullptr)
    {
        return;
    }

    helperPostorder(helpRoot->left);
    helperPostorder(helpRoot->right);

    if (oneNodeCheck)
    {
        cout << helpRoot->val;
        oneNodeCheck = false;
    }

    else
    {
        cout << ", " + helpRoot->val;
    }

}


AVL::TreeNode* AVL::helperInsert(TreeNode* helpRoot, string key, string name)
{

    if (helpRoot == nullptr)
    {
        return new TreeNode(key, name);
    }

    if (stol(key) < stol(helpRoot->val))
    {
        helpRoot->left = helperInsert(helpRoot->left, key, name);
    }

    else if (stol(key) > stol(helpRoot->val))
    {
        helpRoot->right = helperInsert(helpRoot->right, key, name);
    }

    else
    {
        return helpRoot;
    }

    return helpRoot;

}

int AVL::helperMaxDepth(TreeNode* helpRoot)
{

    if (helpRoot == nullptr)
    {
        return 0;
    }

    else
    {
        // computes the depth of each subtree
        int leftDepth = helperMaxDepth(helpRoot->left);
        int rightDepth = helperMaxDepth(helpRoot->right);

        // takes the larger depth
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

//bool AVL::helperUniqueElement(TreeNode* helpRoot, string key)
//{
//
//    if (helpRoot == nullptr)
//    {
//        return false;
//    }
//    if (helpRoot->val == key)
//    {
//        return true;
//    }
//    if (helpRoot->val < key)
//    {
//        return helperUniqueElement(helpRoot->right, key);
//    }
//    else
//    {
//        return helperUniqueElement(helpRoot->left, key);
//    }
//
//}

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

void AVL::insert(string key, string name)
{
    this->root = helperInsert(this->root, key, name);
}

void AVL::searchID(string key)
{
    helperSearchID(this->root, key);
}


vector<string> AVL::searchName(vector<string>& matchNodes, string name) {
    matchNodes.clear();
    helperSearchName(this->root, name, matchNodes);
    return matchNodes;
}


int AVL::maxDepth()
{
    return helperMaxDepth(this->root);
}

//bool AVL::uniqueElement(string key)
//{
//    return helperUniqueElement(this->root, key);
//}


#endif //AVL_TREE_AVLTb REE_H
