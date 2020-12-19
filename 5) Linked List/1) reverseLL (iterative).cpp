/* NODE 
struct Node {
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
*/

//TC : O(N)
//AS : O(1)

struct Node *reverseList(struct Node *head)
{
    if (head == NULL)
        return NULL;
    struct Node *curr = head;
    struct Node *prev = NULL;
    struct Node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}