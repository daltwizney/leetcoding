#include <algorithm>
#include <stdio.h>
#include <stack>

class Node { 
    public: 
        int value;
        Node* left;
        Node* right;

        Node(int value) {
            this->value = value;
            left = nullptr;
            right = nullptr;
        }
};

class BinarySearchTree {
    public:
        Node* root;

    public:
        BinarySearchTree() { root = nullptr; }


        // ---------------------------------------------------
        //  Below is a helper function used by the destructor
        //  Deletes all nodes in BST
        //  Similar to DFS PostOrder in Tree Traversal section
        // ---------------------------------------------------
        void destroy(Node* currentNode) {
            if (currentNode == nullptr) return;
            if (currentNode->left) destroy(currentNode->left);
            if (currentNode->right) destroy(currentNode->right);
            delete currentNode;
        }

        ~BinarySearchTree() { destroy(root); }

        Node* getRoot() {
            return root;
        } 

        //   +=====================================================+
        //   |                 WRITE YOUR CODE HERE                |
        //   | Description:                                        |
        //   | - This method inserts a new value into the tree.    |
        //   | - A new node is created for the value.              |
        //   | - Starts at root and finds the correct location.    |
        //   | - Return type: bool                                 |
        //   |                                                     |
        //   | Tips:                                               |
        //   | - If the tree is empty (root == nullptr), set root  |
        //   |   to the new node and return true.                  |
        //   | - Use a while loop to find the correct location.    |
        //   | - If the value already exists, return false.        |
        //   | - Insert the new node at the correct position.      |
        //   | - Check output from Test.cpp in "User logs".        |
        //   +=====================================================+
        bool insert(int value) {
            
            if (!root)
            {
                root = new Node(value);
                return true;
            }

            std::stack<Node*> buffer;

            buffer.push(root);

            while (buffer.size() > 0)
            {
                Node* node = buffer.top();
                buffer.pop();

                if (node->value == value)
                {
                    return false; // no duplicates allowed
                }

                if (value > node->value)
                {
                    if (!node->right)
                    {
                        node->right = new Node(value);
                        return true;
                    }

                    buffer.push(node->right);
                }
                else if (value < node->value)
                {
                    if (!node->left)
                    {
                        node->left = new Node(value);
                        return true;
                    }

                    buffer.push(node->left);
                }
            }
        }
};


int main() {
  printf("hello wasm!\n");
  return 0;
}