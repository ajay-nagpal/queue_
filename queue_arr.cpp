#include<iostream>
#include<cstdlib>

#define MAX 10

using namespace std;

int qarr[MAX];
int front=-1;
int rear=-1;

void insert(int data){
    if(rear==MAX-1){
        cout<<" overflow"<<endl;
        return;
    }
    if(front==-1)
        front=0;
    qarr[++rear]=data;
}

int del(){
    int data;
    if(front==-1 || front==rear+1){
        cout<<" underflow"<<endl;
        exit(1);
    }
    data=qarr[front++];
    return data;
}

int peek(){
    if(front==-1 || front==rear+1){
        cout<<" underflow"<<endl;
        exit(1);
    }
    return qarr[front];
}

void display(){
    if(front==-1 || front==rear+1){
        cout<<" underflow"<<endl;
        return;
    }
    while(front!=rear+1){
        cout<<qarr[front++]<<" ";
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