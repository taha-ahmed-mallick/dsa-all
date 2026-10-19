#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int id;
    int left = -1;
    int right = -1;
    int parent = -1;
};

void preorder(int u, const vector<Node>& tree) {
    if (u == -1) return;
    cout << " " << u;
    preorder(tree[u].left, tree);
    preorder(tree[u].right, tree);
}

void inorder(int u, const vector<Node>& tree) {
    if (u == -1) return;
    inorder(tree[u].left, tree);
    cout << " " << u;
    inorder(tree[u].right, tree);
}

void postorder(int u, const vector<Node>& tree) {
    if (u == -1) return;
    postorder(tree[u].left, tree);
    postorder(tree[u].right, tree);
    cout << " " << u;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<Node> tree(n);
    for (int i = 0; i < n; ++i) {
        tree[i].id = i;
    }

    for (int i = 0; i < n; ++i) {
        int id, l, r;
        cin >> id >> l >> r;
        tree[id].left = l;
        tree[id].right = r;
        if (l != -1) tree[l].parent = id;
        if (r != -1) tree[r].parent = id;
    }

    // The root is the node with parent == -1
    // it isn't guarunteed to be 0 index node
    int root = 0;
    for (int i = 0; i < n; ++i) {
        if (tree[i].parent == -1) {
            root = i;
            break;
        }
    }

    cout << endl << root << endl;

    cout << "Preorder\n";
    preorder(root, tree);
    cout << "\nInorder\n";
    inorder(root, tree);
    cout << "\nPostorder\n";
    postorder(root, tree);
    cout << "\n";

    return 0;
}