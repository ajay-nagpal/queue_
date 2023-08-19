#include<iostream>
#include<cstdlib>

using namespace std;

class node{
    public:
    int val;
    node * next;
}*front=NULL,*rear=NULL;

void insert(int data){
    node * temp=new node;
    if(temp==NULL){
        cout<<"no memory tom allocate"<<endl;
        return;
    }
    temp->val=data;
    temp->next=NULL;
    if(front==NULL)
        front=temp;
    else
        rear->next=temp;
    rear=temp;
}

int del(){
    int data;
    if(front==NULL){
        cout<<" underflow"<<endl;
        exit(1);
    }
    data=front->val;
    front=front->next;
    return data;
}

int peek(){
    if(front== NULL ){
        cout<<" underflow"<<endl;
        exit(1);
    }
    return front->val;
}

void display(){
    if(front==NULL){
        cout<<" underflow"<<endl;
        return;
    }
    node * temp=front;

    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
}

int main(){
    int choice,data,item;

    while(1){
        cout<<endl;
        cout<<"given choices "<<endl;
        cout<<"01 for insert"<<endl;
        cout<<"02 for delete"<<endl;
        cout<<"03 for display front element"<<endl;
        cout<<"04 for display complete queue elements"<<endl;
        cout<<"05 for ending task"<<endl;

        cout<<"enter your choice"<<endl;
        cin>>choice;

        switch(choice){
            case 1:
            cout<<"enter data to insert"<<endl;
            cin>>data;
            insert(data);
            break;

            case 2:
            item=del();
            cout<<"deleted item is "<<item<<endl;
            break;

            case 3:
            cout<<peek()<<endl;
            break;

            case 4:
            display();
            break;

            case 5:
            cout<<"you have choosen to exit "<<endl;
            exit(1);
            break;

            default:
            cout<<"wrong choice entered"<<endl;

        }
    }
}