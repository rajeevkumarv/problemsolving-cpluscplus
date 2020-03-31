#include <iostream>
#include <string>
#include <initializer_list>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int data):data(data),next(nullptr){}
};

Node* getLinkedList(std::initializer_list<int> data){
    Node* head = new Node(0);
    Node *t =  head;
    for(int x:data){
        t->next = new Node(x);
        t = t->next;
    }
    t = head;
    head = head->next;
    delete t;
    return head;
}

void printList(Node* node){
    while(node){
        std::cout<<node->data<<", ";
        node=node->next;
    }
    std::cout<<std::endl;
}

std::pair<Node*,Node*> split(Node *node){
    Node* fptr = node;
    Node* sptr = node;
    while(sptr && sptr->next && sptr->next->next){
        fptr=fptr->next;
        sptr=sptr->next->next;
    }
    auto f = node == nullptr ? nullptr :  node;
    if(fptr){
        auto t = fptr;
        fptr = t->next;
        t->next = nullptr;
    }
    return std::make_pair(f,fptr == nullptr ? nullptr : fptr);
}

//Driver
int main(){
     {
         Node* head = getLinkedList({1,2,3,4});
         auto p = split(head);
         printList(p.first);
         printList(p.second);
     }
    {
         Node* head = getLinkedList({1,2,3,4,5});
         auto p = split(head);
         printList(p.first);
         printList(p.second);
     }
    {
         Node* head = getLinkedList({1});
         auto p = split(head);
         printList(p.first);
         printList(p.second);
     }
    {
         Node* head = getLinkedList({});
         auto p = split(head);
         printList(p.first);
         printList(p.second);
     }
}

