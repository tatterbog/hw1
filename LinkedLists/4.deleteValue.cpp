#include <iostream>

struct ListNode {
    int data;
    ListNode* next;
    
    explicit ListNode(int val = 0) : data(val), next(nullptr) {}
};


void printList(ListNode* head) {
    while(head != nullptr) {
        std::cout << head->data <<' ';
        head = head->next;
    }
    std::cout << '\n';
}

void deleteList(ListNode* head) {
    while(head != nullptr) {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
    }
}

ListNode* deleteValue(ListNode* head, int value) {
    if (head == nullptr) {
        return nullptr;
    } 

    ListNode* node = new ListNode(0);
    node->next = head;
    head = node;

    ListNode* prev = head;
    ListNode* curr = head->next;
    
    while(curr != nullptr){
        if(curr->data == value){
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }
        else{
            curr = curr->next;
            prev = prev->next;
        }
    }

    head = node->next;
    delete node;
    return head;
}


int main() {

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    

    printList(head);
    ListNode* head2 = deleteValue(head, 3);
    printList(head2);

    deleteList(head2);
}