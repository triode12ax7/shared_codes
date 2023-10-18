#include <iostream>

using namespace std;

struct Node {

    int value;
    int level;
    Node* left;
    Node* right;

    Node(int _value, int _level = 0) {
        value = _value;
        level = _level;
        left = nullptr;
        right = nullptr;
        
    }

};


struct BinaryTree {

    Node* root;

    BinaryTree() {
        root = nullptr;
    }

    void push_helper(int _value, Node* curr) {
        if (_value < curr->value) {
            if (curr->left == nullptr) {
                curr->left = new Node(_value);
                return;
            }
            return push_helper(_value, curr->left);
        }

        else if (_value > curr->value) { 
            if (curr->right == nullptr) {
                curr->right = new Node(_value);
                return;
            }
            return push_helper(_value, curr->right);
        }

        
    }

    void push(int _value) {
        if (root == nullptr) {
            root = new Node(_value);
            return;
        }
        return push_helper(_value, root);
    }

    int height_helper(Node* curr){
        if (curr == nullptr) { return 0; }
        if ((curr->left && curr->left->right == curr) &&
            (curr->right && curr->right->left == curr)) {
            return 1;
        }
        return 1 + max(height_helper(curr->left), height_helper(curr->right));
    }

    int height() {
      return height_helper(root);
    }
};

int main() {
    BinaryTree bt;
    int elem;
    cin >> elem;
    while (elem != 0) {
        bt.push(elem);
        cin >> elem;
    }
    cout << bt.height();
}
