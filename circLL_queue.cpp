#include<iostream>
#include<cstdlib>

using namespace std;

class node{
    public:
    int val;
    node * next;
}*rear=NULL;

void insert(int data){
    node * temp=new node;
    if(temp==NULL){
        cout<<"no memory tom allocate"<<endl;
        return;
    }
    temp->val=data;
    temp->next=NULL;

    if(rear==NULL){
        rear=temp;
        temp->next=rear;
    }       
    else{
        temp->next=rear->next;
        rear->next=temp;
        rear=temp;
    }      
}

int del(){
    int data;
    if(rear==NULL){
        cout<<" underflow"<<endl;
        exit(1);
    }
    if(rear->next==rear){
        data=rear->val;
        rear=NULL;
        return data;
    }
    node * temp=rear->next;

    data=temp->val;
    rear->next=temp->next;

    return data;
}

int peek(){
    if(rear== NULL ){
        cout<<" underflow"<<endl;
        exit(1);
    }
    if(rear->next==rear){   
        return rear->val;
    }
    return rear->next->val;
}

void display(){
    if(rear== NULL ){
        cout<<" underflow"<<endl;
        exit(1);
    }
    node * temp=rear->next;

    do{
        cout<<temp->val<<" ";
        temp=temp->next;
    }while(temp!=rear->next);
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