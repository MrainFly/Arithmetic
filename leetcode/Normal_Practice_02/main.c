/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct ListNode {
	int val;
	struct ListNode *next;
} __attribute__ ((aligned (8)));

// 需要考虑的事情很多，尤其是进位的问题，不能光想到两边相加的进位，还需要考虑到只有一方有数时的进位，而且如果最后有进位也需要加到高位上

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
	struct ListNode* s_l1 = l1;
	struct ListNode* s_l2 = l2;
	int carry = 0;

	struct ListNode* resultList = NULL;
	struct ListNode* s_resultList = NULL;	

	while(s_l1 != NULL && s_l2 != NULL){
        if(!resultList){
            s_resultList = resultList = malloc(sizeof(struct ListNode));
        } else{
            s_resultList->next = malloc(sizeof(struct ListNode));
            s_resultList = s_resultList->next;
        }

		s_resultList->val = s_l1->val + s_l2->val + carry;
		if (s_resultList->val >= 10){
			carry = 1;
			s_resultList->val -= 10;
		} else{
			carry = 0;
		}

        s_resultList->next = NULL;
		s_l1 = s_l1->next;
		s_l2 = s_l2->next;
	}
	
	while (s_l1 != NULL){
        s_resultList->next = malloc(sizeof(struct ListNode));
		s_resultList = s_resultList->next;

        s_resultList->val = s_l1->val + carry;
        if (s_resultList->val >= 10){
			carry = 1;
			s_resultList->val -= 10;
		} else{
			carry = 0;
		}
		s_l1 = s_l1->next;
		if (s_l1 == NULL){
			s_resultList->next = NULL;
			break;
		}
	}
	
	while (s_l2 != NULL){
        s_resultList->next = malloc(sizeof(struct ListNode));
		s_resultList = s_resultList->next;
        
        s_resultList->val = s_l2->val + carry;
        if (s_resultList->val >= 10){
			carry = 1;
			s_resultList->val -= 10;
		} else{
			carry = 0;
		}
		s_l2 = s_l2->next;
		if (s_l2 == NULL){
			s_resultList->next = NULL;
			break;
		}
	}

    if (carry == 1){
        s_resultList->next = malloc(sizeof(struct ListNode));
		s_resultList = s_resultList->next;
        s_resultList->val = carry;
        s_resultList->next = NULL;
    }
	
	return resultList;
}
/*
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *head = NULL, *tail = NULL;
    int carry = 0;
    while (l1 || l2) {
        int n1 = l1 ? l1->val : 0;
        int n2 = l2 ? l2->val : 0;
        int sum = n1 + n2 + carry;
        if (!head) {
            head = tail = malloc(sizeof(struct ListNode));
            tail->val = sum % 10;
            tail->next = NULL;
        } else {
            tail->next = malloc(sizeof(struct ListNode));
            tail->next->val = sum % 10;
            tail = tail->next;
            tail->next = NULL;
        }
        carry = sum / 10;
        if (l1) {
            l1 = l1->next;
        }
        if (l2) {
            l2 = l2->next;
        }
    }
    if (carry > 0) {
        tail->next = malloc(sizeof(struct ListNode));
        tail->next->val = carry;
        tail->next->next = NULL;
    }
    return head;
}
*/
struct ListNode l1_2 = {3, NULL};
struct ListNode l1_1 = {4, &l1_2};
struct ListNode l1_0 = {2, &l1_1};

struct ListNode l2_2 = {4, NULL};
struct ListNode l2_1 = {6, &l2_2};
struct ListNode l2_0 = {5, &l2_1};

struct ListNode* l = NULL;

int
main (int argc, char *argv[])
{
	l = addTwoNumbers(&l1_0, &l2_0);
	printf("0: %d\r\n", l->val);
	l = l->next;
	printf("1: %d\r\n", l->val);
	l = l->next;
	printf("2: %d\r\n", l->val);

	return 0;
}

