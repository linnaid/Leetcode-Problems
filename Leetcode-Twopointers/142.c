/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode* newNode = head;
    struct ListNode* newNodeFront = head;
    struct ListNode* newNode_p = head;
    while(newNode != NULL)
    {
        if(newNode->next == NULL)
        return NULL;
        newNode = newNode->next->next;
        newNodeFront = newNodeFront->next;
        if(newNode == newNodeFront)
        {
            if(newNode == newNode_p)
            return newNode;
            else
            while(newNode != newNode_p)
            {
                newNode_p = newNode_p->next;
                newNode = newNode->next;
            }
            return newNode;
        }
    }    
    return NULL;
}