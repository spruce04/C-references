/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    //iterate through the list to determine its length
    int i = 0;
    struct ListNode* temp = head;
    while(temp != NULL) {
        i += 1;
        temp = temp->next;
    }

    float mid;
    //determine the middle value of the list
    if(i % 2 == 1) {//(odd)
        mid = i/2 + 0.5;
    }
    else {//(even)
        mid = i/2 + 1;
    }

    //iterate until the mid value
    for(int j = 1; j < mid; j++) {
        head = head->next;
    }
    //return the mid value
    return head;
}
