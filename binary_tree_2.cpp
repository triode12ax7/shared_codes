struct Node {

    int value;
    Node* left;
    Node* right;

    Node(int _value) {
        value = _value;
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


};
