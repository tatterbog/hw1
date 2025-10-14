#include <iostream>

struct ListNode {
    int data;
    ListNode* next;
    
    explicit ListNode(int val = 0) : data(val), next(nullptr) {}
};


ListNode* createList(){
    return nullptr;
}


template<typename T, typename... Rest>
ListNode* createList(const T& first, const Rest&... rest){
    ListNode* head = new ListNode(first);
    head->next = createList(rest...);
    return head;
}



void printList(ListNode* head) {
    while(head != nullptr) {
        std::cout << head->data <<' ';
        head = head->next;
    }
}

void deleteList(ListNode* head) {
    while(head != nullptr) {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
    }
}


ListNode* deleteDuplicates(ListNode* head) {
    ListNode* ptr = nullptr, *curr = head;
    while(curr){
        if(curr->next != nullptr && curr->next->data == curr->data){
            ptr = curr->next;
            curr->next = curr->next->next;
            delete ptr;
        }
        else{
            curr = curr->next;
        }
    }
    return head;
}

int main() {
    ListNode* head = createList(1, 1, 2, 2, 3, 3, 3, 4, 4, 5, 5, 6);
    
    ListNode* head2 = deleteDuplicates(head);
    printList(head2);

    deleteList(head2);
    
}