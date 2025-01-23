/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    //first we will iterate through the linked list, calculate its length and store its values in an array
    int len = 0;
    int* values = malloc(5000 * sizeof(int));
    //we need to save the head of the list
    struct ListNode* temp = head;

    //traverse the list
    while(temp != NULL) {
        values[len] = temp->val;
        len++;
        temp = temp->next;
    }
    //reset to the start of the list
    temp = head;

    //go back through the values starting from the end and overwrite the linked list we were given
    for (int i = len - 1; i >= 0; i--) {
        temp->val = values[i];
        temp = temp->next;
    }

    return head;
}
