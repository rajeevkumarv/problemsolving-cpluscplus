#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include <stack>

using namespace std;

struct Node{
    int val;
    Node* left, *right;
    Node(int v):val(v),left(nullptr),right(nullptr){}
} *head;

void buildTree(vector<int>&& nums){
    std::queue<Node*> q;
    head = new Node(nums[0]);
    q.push(head);
    Node* t = nullptr;
    int i = 1;
    while(i<nums.size()){
        t = q.front();
        q.pop();
        t->left = new Node(nums[i++]);
        q.push(t->left);
        if(i < nums.size()){
            t->right = new Node(nums[i++]);
            q.push(t->right);
        }
    }
 }

void inorder_traversal(Node* node){
    if(node == nullptr){
        return;
    }
    inorder_traversal(node->left);
    std::cout<<node->val<<" ";
    inorder_traversal(node->right);
}

void preorder_traversal(Node* node){
    if(node == nullptr){
        return;
    }
    std::cout<<node->val<<" ";
    preorder_traversal(node->left);
    preorder_traversal(node->right);
}

void inorder_traversal_iterative(){
    std::stack<Node*> S;
    S.push(head);
    Node* t = nullptr;
    while(!S.empty()){
        if(S.top()->left){
            S.push(S.top()->left);
            continue;
        }
        //Process all tops
        while(!S.empty()){
            t = S.top();
            S.pop();
            std::cout<<t->val<<" ";
            if(t->right){
                S.push(t->right);
                break;
            }
        }
    }
}

//Driver Program
int main(){
    buildTree(vector<int>({1,2,3,4}));
    inorder_traversal(head);
    std::cout<<std::endl;
    inorder_traversal_iterative();
}