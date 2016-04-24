/*================================================================
*   Copyright (C) 2016 All rights reserved.
*   
*   filename     :main.cpp
*   author       :qinlibin
*   create date  :2016/04/09
*   mail         :qin_libin@foxmail.com
*
================================================================*/

#include<iostream>
using namespace std;

struct Node
{
    string addr;
    int val;
    string Next;
    Node * next;
    Node(string add,int v,string N,Node *n = NULL)
    {
        addr = add;
        val = v;
        Next = N;
        next = n;
    }
};

Node * reorder_list(Node *head,string start,int N)
{
    Node *new_list = NULL,*new_list_tail = NULL;
    while(N)
    {
        Node *p = head;
        while(p->addr != start)
        {
            p = p->next;
        }
        Node *tmp = new Node(p->addr,p->val,p->Next);
        if(new_list == NULL)
        {
            new_list = tmp;
            new_list_tail = tmp;
        }
        else
        {
            new_list_tail -> next = tmp;
            new_list_tail = tmp;
        }
        start = tmp -> Next;
        N--;
    }
    Node *p = head;
    while(p)
    {
        Node *q = p;
        p = p-> next;
        delete q;
    }

    return new_list;

}

int main()
{
    Node *head = NULL, *tail = NULL,*new_head=NULL, *new_tail = NULL;
    Node *k_small = NULL,*k_small_tail = NULL,*p;
    string saddr,Next,addr;
    int val,N,k,cnt;
    cin>>saddr>>N>>k;
    for(int i = 0; i < N;i++)
    {
        cin>>addr>>val>>Next;
        Node* tmp = new Node(addr,val,Next);
        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tmp;
        }
    }
   head =  reorder_list(head,saddr,N);

    Node *fast = head,*slow = head;
    while(fast)
    {
        k_small = NULL;
        k_small_tail = NULL;
        for(cnt = 0; cnt < k; cnt++)
        {
            if(fast)
            {
                fast = fast -> next;
            }
            else
            {
                break;
            }
        }
        if(cnt < k)
        {
            while(slow != fast)
            {
                Node *tmp = new Node(slow->addr,slow->val,slow->Next);
                if(new_head == NULL)
                {
                    new_head = tmp;
                    new_tail = tmp;
                }
                else
                {
                    new_tail->next = tmp;
                    new_tail->Next = tmp->addr;
                    new_tail = tmp;
                }
                slow = slow->next;
            }
        }
        else
        {
           while(slow!=fast)
           {
               if(k_small == NULL)
               {
                   k_small = new Node(slow->addr,slow->val,"-1");
                   k_small_tail = k_small;
               }
               else
               {
                   Node *tmp = new Node(slow->addr,slow->val,k_small->addr);
                   tmp->next = k_small;
                   k_small = tmp;
               }
               slow = slow -> next;
    
           }
           if(new_head == NULL)
           {
               new_head = k_small;
               new_tail = k_small_tail;
           }
           else
           {
               new_tail -> next = k_small;
               new_tail -> Next = k_small->addr;
               new_tail = k_small_tail;
           }
        }
    
    }

    p = new_head;
    while(p)
    {
        cout<<p->addr<<" "<<p->val<<" "<<p->Next<<endl;
        p = p->next;
    }

    
}
