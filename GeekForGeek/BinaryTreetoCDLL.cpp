#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
class Solution
{
public:
    Node *head; // Pointer to the head of the circular doubly linked list.
    Node *tail; // Pointer to the tail of the circular doubly linked list.

    // Helper function to perform inorder traversal and convert the binary tree to a circular doubly linked list.
    void inorder(Node *root)
    {
        if (!root)
            return;

        // Traverse the left subtree.
        inorder(root->left);

        // Create a new node for the current root's data.
        Node *curr = new Node(0);
        curr->data = root->data;

        // Connect the current node to the previous node in the linked list.
        if (tail)
        {
            tail->right = curr;
            curr->left = tail;
        }
        else
            head = curr; // If tail is null, set the current node as the head.

        tail = curr; // Update the tail to the current node.

        // Traverse the right subtree.
        inorder(root->right);
    }

    // Main function to convert a binary tree to a circular doubly linked list.
    Node *bTreeToCList(Node *root)
    {
        tail = head = NULL; // Initialize head and tail to null before conversion.

        inorder(root); // Perform inorder traversal to build the linked list.

        // Connect the head and tail to make it circular.
        head->left = tail;
        tail->right = head;

        return head; // Return the head of the circular doubly linked list.
    }
};

int main()
{
    turbo;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif

    // cerr<< "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}