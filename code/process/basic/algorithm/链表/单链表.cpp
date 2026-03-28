#include<iostream>
using namespace std;

//单链表结点定义
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(nullptr){}
};

//根据某个值删除链表中所有这个值的节点
ListNode* removeElements(ListNode* head,int val){
    //删除头节点
    while(head != NULL && head->val == val){
        ListNode* temp=head;
        head=head->next;
        delete temp;
    }
    //删除非头节点
    ListNode* cur=head;
    while(cur!=NULL && cur->next!=NULL){
        if(cur->next->val == val){
            ListNode* temp=cur->next;
            cur->next=cur->next->next;
            delete temp;
        }else{
            cur=cur->next;
        }
    }

    return head;
}

int main(){
    ListNode* head=new ListNode(5);

}