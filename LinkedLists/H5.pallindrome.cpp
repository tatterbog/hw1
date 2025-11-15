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
        std::cout << head->data << ' ';
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

ListNode* reverseList(ListNode* head) {
    if(head == nullptr){
        return head;
    }

    ListNode* prev = head,*curr = head->next,*ptr = head->next;
    prev->next = nullptr;
    while(ptr!=nullptr){
        ptr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = ptr;
    }

    head = prev;
    return head;
}

ListNode* findMiddle(ListNode* head){
    ListNode* p1 = head;
    ListNode* p2 = head;
    
    while(p2 && p2->next){
        p1 = p1->next;
        p2 = p2->next->next;
    }

    return p1;
}

bool isPalindrome(ListNode* head){
    if(head == nullptr || head->next == nullptr){
        return true;
    } 

    ListNode* mid = findMiddle(head);
    ListNode* rmid = reverseList(mid);

    ListNode* p1 = head;
    ListNode* p2 = rmid;

    while(p2){
        if(p1->data != p2->data){
            rmid = reverseList(mid);
            return false;
        }
        p1 = p1->next;
        p2 = p2->next;

    }

    rmid = reverseList(mid);
    return true;

}


int main() {
    ListNode* head = createList(1, 2, 3, 4, 5);
    ListNode* head2 = createList(1, 2, 3, 4, 3, 2, 1);

    std::cout << std::boolalpha << isPalindrome(head) << '\n'; 
    std::cout << std::boolalpha << isPalindrome(head2) << '\n'; 

    deleteList(head);
    deleteList(head2);
}