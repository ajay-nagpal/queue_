#include<iostream>
#include<cstdlib>

using namespace std;

#define MAX 10
int dq_arr[MAX];
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

void insertR(int data){
    if(isfull()){
        cout<<"overflow"<<endl;
        return ;
    }
    if(front==-1){
        front=rear=0;
    }
    else if(rear==MAX-1){
        rear=0;
    }
    else
        rear++;

    dq_arr[rear]=data;
}

void insertF(int data){
    if(isfull()){
        cout<<"overflow"<<endl;
        return ;
    }
    if(front==-1){
        front=rear=0;
    }
    else if(front==0){
        front=MAX-1;
    }
    else{
        front-=1;
    }

    dq_arr[front]=data;
}

int delF(){
    int item;
    if(isempty()){
        cout<<"underflow"<<endl;
        exit(1);
    }
    item=dq_arr[front];

    if(front==rear){
        front=rear=-1;
    }
    else if(front==MAX-1){
        front=0;
    }
    else
        front++;
    
    return item;
}

int delR(){
    int item;
    if(isempty()){
        cout<<"underflow"<<endl;
        exit(1);
    }
    item=dq_arr[rear];

    if(front==rear){
        front=rear=-1;
    }
    else if(rear==0){
        rear=MAX-1;
    }
    else
        rear--;
    
    return item;
}

void display(){
    if(isempty()){
        cout<<"underflow"<<endl;
        return;
    }
     int i=front;
     if(front<=rear){
        while(i<=rear){
            cout<<dq_arr[i++]<<" ";
        }
     }
     else{
        while(i<=MAX-1){
            cout<<dq_arr[i++]<<" ";
        }
        i=0;
        while(i<=rear){
            cout<<dq_arr[i++]<<" ";
        }
     }
}
int main(){
    while(1){

    int data,choice,item;

    cout<<endl;
    cout<<"given choices"<<endl;
    cout<<endl;
    cout<<"1 for insert from front"<<endl;
    cout<<"2 for insert from rear"<<endl;

    cout<<"3 for del from front"<<endl;
    cout<<"4 for del from rear"<<endl;

    cout<<"5 for display queue"<<endl;
    cout<<"6 for exit"<<endl;

    cout<<endl;
    cout<<"enter choice"<<endl;
    cin>>choice;

    switch(choice){
            case 1:
            cout<<"enter data to  from front"<<endl;
            cin>>data;
            insertF(data);
            break;

            case 2:
            cout<<"enter data to insert from rear"<<endl;
            cin>>data;
            insertR(data);
            break;

            case 3:
            item=delF();
            cout<<"del item  from front is "<<item<<endl;
            break;

            case 4:
            item=delR();
            cout<<"del item fron rear is "<<item<<endl;
            break;

            case 5:
            display();
            break;

            case 6:
            cout<<"you have choosen to exit "<<endl;
            exit(1);

            default:
            cout<<"wrong choice entered"<<endl;

        }
    }
}