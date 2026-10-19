#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *left, *right;
    Node(int val) : val(val), left(nullptr), right(nullptr) {}
};

class BinTree
{
public:
    Node *root;
    BinTree() : root(nullptr) {}

    void input(Node *&node)
    {
        int n, l, r;
        cin >> n >> l >> r;
        node = new Node(n);
        if (l != -1)
            input(node->left);
        if (r != -1)
            input(node->right);
    }

    void preorder(Node  *node) const {
        if (node == nullptr) return;
        cout << " " << node->val;
        preorder(node->left);
        preorder(node->right);
    }

    void inorder(Node *node) const {
        if (node == nullptr) return;
        inorder(node->left);
        cout << " " << node->val;
        inorder(node->right);
    }

    void postorder(Node *node) const {
        if (node == nullptr) return;
        postorder(node->left);
        postorder(node->right);
        cout << " " << node->val;
    }
};
// doesn't work as it considers the input is given in preorder format
int main()
{
    size_t t;
    cin >> t;
    BinTree *tree = new BinTree();
    tree->input(tree->root);
    cout << "Preorder\n";
    tree->preorder(tree->root);
    cout << "\nInorder\n";
    tree->inorder(tree->root);
    cout << "\nPostorder\n";
    tree->postorder(tree->root);
    cout << "\n";
    return 0;
}