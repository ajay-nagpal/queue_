#include<iostream>
#include<cstdlib>

using namespace std;

class node{
    public:

    int priority;
    int data;
    node * next;
}*front=NULL;

void insert(int data,int priority){
    node * temp=new node;
    if(temp==NULL){
        cout<<"no space allocated"<<endl;
        return;
    }
    temp->data=data;
    temp->priority=priority;

    if(front==NULL||front->priority>temp->priority){
        temp->next=front;
        front=temp;
        return;
    }

    node *p=front;
    while(p->next!=NULL && p->next->priority<=temp->priority){
        p=p->next;
    }
    temp->next=p->next;
    p->next=temp;  
}

int del(){
    if(front==NULL){
        cout<<"empty queue"<<endl;
        exit(1);
    }
    int item=front->data;
    front=front->next;
    return item;
}

void display(){
    if(front==NULL){
        cout<<"no element to display"<<endl;
        return;
    }
    node *p=front;
    while(p!=NULL){
        cout<<p->data<<" "<<p->priority<<endl;
        p=p->next;
    }
}

int main(){
    while(1){

    int data,choice,item,priority;

    cout<<endl;
    cout<<"given choices"<<endl;
    cout<<endl;
    cout<<"1 for insert"<<endl;
    cout<<"2 for del"<<endl;
    cout<<"3 for display queue"<<endl;
    cout<<"4 for exit"<<endl;

    cout<<endl;
    cout<<"enter choice"<<endl;
    cin>>choice;

    switch(choice){
            case 1:
            cout<<"enter data to insert"<<endl;
            cin>>data;
            cout<<"enter priority"<<endl;
            cin>>priority;
            insert(data,priority);
            break;

            case 2:
            item=del();
            cout<<"del item is "<<item<<endl;
            break;

            case 3:
            display();
            break;

            case 4:
            cout<<"you have choosen to exit "<<endl;
            exit(1);

            default:
            cout<<"wrong choice entered"<<endl;

        }
    }
}