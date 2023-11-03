#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    // Should return head of the modified linked list
    Node *sortedInsert(Node *head, int data)
    {
        // Create a new node with the given data.
        Node *node = new Node(data);

        // If the new node should be inserted at the beginning,
        // update its next pointer and return it as the new head.
        if (!head || data < head->data)
        {
            node->next = head;
            return node;
        }

        Node *prev = head;
        Node *curr = head->next;

        // Find the appropriate position for the new node.
        while (curr && data >= curr->data)
        {
            prev = curr;
            curr = curr->next;
        }

        // Insert the new node between prev and curr.
        prev->next = node;
        node->next = curr;

        // Return the original head node.
        return head;
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