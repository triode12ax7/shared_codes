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
    int len = 0;
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
        len++;
        if (root == nullptr) {
            root = new Node(_value);
            return;
        }
        return push_helper(_value, root);
    }

    int lenght() {
        return len;
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
    cout << bt.lenght();
}
