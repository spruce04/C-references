/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    //start by finding the first node with a valid value
    while(head != NULL) {
        if(head->val != val) {
            break;
        }
        else {
            head = head->next;
        }
    }
    //if we are done (all nodes were invalid), exit the program
    if(head == NULL) {
        return head;
    }

    //Now, keep going through the list but each time we find an invalid node unlink it from the list
    struct ListNode* next = head->next;
    struct ListNode* temp = head;
    while(temp != NULL && next != NULL) {
        //if the next value is invalid, unlink it
        if(next->val == val) {
            temp->next = next->next;
            //also update next
            next = temp->next;
            
        } 
        else { //move to the next node (if we haven't already moved in the if statement)
            temp = temp->next;
            next = next->next;
        }
    }
    return head;
}
