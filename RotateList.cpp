#include <iostream>
#include <string>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* rotateRight(ListNode* head, int k)
{
    if(head==NULL || k<=0) {
        return head;
    }

    //find the length of list
    int length=1;
    ListNode* p = head;
    while(p->next!=NULL){
        length++;
        p=p->next;
    }

    //connect the tail to the head
    p->next=head;
    //find the left place (take care the case - k>len)
    k =len-k%len;

    //find the place
    for(int i=0; i<k; i++){
        p=p->next;
    }

    head=p->next;
    p->next=NULL;
    return head;
}


