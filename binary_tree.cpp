#include <iostream>

using namespace std;


struct Node {
    Node* prev;
    Node* next;
    int value;
    Node(int _value) {
        prev = nullptr;
        next = nullptr;
        value = _value;
    }
}

struct DoubleLinkedList {

    Node* begin;
    Node* end;

    DoubleLinkedList() {
        begin = nullptr;
        end = nullptr;
    }

    void push_back(int value) {
        Node* new_elem = new Node(value);
        if (begin == nullptr {
            begin = new_elem;
            end = new_elem;
        }

        new_elem->prev = end;
        end->next = new_elem;
        end = end->next;
    }

    void push_front(int value) {
        Node* new_elem = new Node(value);
        if (begin == nullptr {
            begin = new_elem;
            end = new_elem;
        }

        new_elem->next = begin;
        begin->prev = new_elem;
        begin = begin->prev;
    }

    int pop_back() {
        Node* temp = end;
        int res = temp->value;
        end = end->prev;
        if (end == nullptr) {
            begin = nullptr;
        } else {
            end->next = nullptr;
        }
        delete temp;
        return res;
    }


    int pop_back_helper(int index, int current_index, Node* current_node) {
        if (index == current_index) {
            if (current_node == begin) {
                return pop_front()
            }
            if (current_node == end) {
                return pop_back();
            }
            current_node->prev->next = current_node->next;
            current_node->next->prev = current_node->prev;
            int result = current->value;
            delete current_node;
            return res;
        }
        return pop_back_helper(index, current_index + 1, current_node->prev);
    }
    int pop_back(int index) {
        return pop_back_helper(index, 0, end);
    }

    int pop_front() {
        Node* temp = begin;
        int res = temp->value;
        begin = begin->next;
        if (begin == nullptr) {
            end = nullptr;
        } else {
            begin->prev = nullptr;    
        }
        delete temp;
        return res;
    }

    int pop_front_helper(int index, int current_index + 1, current_node) {
        if (index == current_index) {
            if (current_node == begin) {
                return pop_front()
            }
            if (current_node == end) {
                return pop_back();
            }
            current_node->prev->next = current_node->next;
            current_node->next->prev = current_node->prev;
            int result = current->value;
            delete current_node;
            return res;
        }
        return pop_back_helper(index, current_index + 1, current_node->next);
    }
    int pop_front(int index) {
        return pop_front_helper(index, 1, begin);
    }
    void print_helper(Node* current_node) {
        if (current_node == nullptr) { return; }
        cout << current_node->value;
        return print_helper(current_node->next);
    }
    void print() {
        print_helper(begin);
        cout << endl;
        return;
    }
    
}

int main() {

}
