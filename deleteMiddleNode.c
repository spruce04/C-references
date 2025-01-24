/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteMiddle(struct ListNode* head) {
    //first, determine the length of the list
    int i = 0;
    struct ListNode* temp = head;
    while(temp != NULL) {
        i += 1;
        temp = temp->next;
    }

    //if the list has 0 or 1 elements, return an empty list
    if(i == 0 || i == 1) {
        return NULL;
    }

    float mid;
    //determine the middle value of the list
    if(i % 2 == 1) {//(odd)
        mid = i/2 + 0.5;
    }
    else {//(even)
        mid = i/2 + 1;
    }

    //iterate until one before the mid value
    temp = head;
    for(int j = 1; j < mid-1; j++) {
        temp = temp->next;
    }
    //delete this value 
    temp->next = temp->next->next;

    return head;
}
