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

} *head;

class Solution
{
public:
    Node *pairWiseSwap(Node *head)
    {
        // Check if there is only one node or no node in the linked list
        if (head == NULL || head->next == NULL)
            return head;

        Node *dummy = new Node(0); // Create a dummy node to simplify swapping logic
        Node *prev = dummy, *curr = head, *frwd = head->next;

        while (frwd)
        {
            // Swap adjacent nodes
            prev->next = frwd;
            curr->next = frwd->next;
            frwd->next = curr;

            // Update pointers
            prev = curr;
            curr = curr->next;

            // Update frwd if curr is not NULL
            if (curr)
                frwd = curr->next;
            else
                frwd = NULL;
        }

        return dummy->next; // Return the new head of the linked list
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