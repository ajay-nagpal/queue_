#include<iostream>
#include<cstdlib>

using namespace std;

#define MAX 10
int carr[MAX];
int front=-1;
int rear=-1;

int isempty(){
    if(front==-1){
        return 1;
    }
    return 0;
}

int isfull(){
    if(front==rear+1 || (front==0 && rear==MAX-1))
        return 1;
    return 0;

}

void insert(int data){
    if(isfull()){
        cout<<"overflow"<<endl;
        return ;
    }
    if(front==-1){
        front=0;
    }
    if(rear==rear+1){
        rear=0;
    }
    carr[++rear]=data;
}

int del(){
    int item;
    if(isempty()){
        cout<<"underflow"<<endl;
        exit(1);
    }
    item=carr[front];

    if(front==rear){
        front=rear=-1;
    }
    else if(front==rear+1){
        front=0;
    }
    else
        front++;
    
    return item;
}

int peek(){

    if(isempty()){
        cout<<"underflow"<<endl;
        exit(1);
    }
    return carr[front];   
}

void display(){
    if(isempty()){
        cout<<"underflow"<<endl;
        return;
    }
     int i=front;
     if(front<=rear){
        while(i<=rear){
            cout<<carr[i++]<<" ";
        }
     }
     else{
        while(i<=MAX-1){
            cout<<carr[i++]<<" ";
        }
        i=0;
        while(i<=rear){
            cout<<carr[i++]<<" ";
        }
     }
}
int main(){
    while(1){

    int data,choice,item;

    cout<<endl;
    cout<<"given choices"<<endl;
    cout<<endl;
    cout<<"1 for insert"<<endl;
    cout<<"2 for del"<<endl;
    cout<<"3 for front element"<<endl;
    cout<<"4 for display queue"<<endl;
    cout<<"5 for exit"<<endl;

    cout<<endl;
    cout<<"enter choice"<<endl;
    cin>>choice;

    switch(choice){
            case 1:
            cout<<"enter data to insert"<<endl;
            cin>>data;
            insert(data);
            break;

            case 2:
            item=del();
            cout<<"del item is "<<item<<endl;
            break;

            case 3:
            cout<<"front element is "<<peek()<<endl;
            break;

            case 4:
            display();
            break;

            case 5:
            cout<<"you have choosen to exit "<<endl;
            exit(1);

            default:
            cout<<"wrong choice entered"<<endl;

        }
    }
}