/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* temp1 = list1;
    struct ListNode* temp2 = list2;

    //if both lists are empty, return null
    if(temp1 == NULL && temp2 == NULL) {
        return NULL;
    }
    //if the first list is empty return the second list
    else if(temp1 == NULL) {
        return temp2;
    }
    //if the second list is empty return the first list
    else if(temp2 == NULL) {
        return temp1;
    }

    //set up the list that will be returned
    struct ListNode* toReturn;
    struct ListNode* marker;
    if(temp1->val <= temp2->val) {
        toReturn = temp1;
        marker = toReturn;
        temp1 = temp1->next;
    } else {
        toReturn = temp2;
        marker = toReturn;
        temp2 = temp2->next;
    }

    //loop through the lists and compare them each time
    while(temp1 != NULL && temp2 != NULL) {
        if(temp1->val <= temp2->val) {
            marker->next = temp1;
            marker = marker->next;
            temp1 = temp1->next;
      } else {
            marker->next = temp2;
            temp2 = temp2->next;
            marker = marker->next;
        }
    }

    //if at the end a list isn't empty, put it on the end
    if (temp1 != NULL) {
        marker->next = temp1;
    } else if (temp2 != NULL) {
        marker->next = temp2;
    }

    return toReturn;
}
