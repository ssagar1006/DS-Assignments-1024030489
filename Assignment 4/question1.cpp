#include<iostream>
#include<stack>
#include<queue>
using namespace std;
class Queue{
    int *arr;
    int size;
    int front;
    int rear;
    Queue(){
        size=100001;
        arr = new int[size];
        front=0;
        rear=0;
    }
    void enqueue(int ele){
        if(rear==size){
            cout<<"The queue is full"<<endl;
        }
        else{
            arr[rear]=ele;
            rear++;
        }
    }
    int dequeue(){
        if(front==rear){
            cout<<"Queue is empty"<<endl;
        }
        else{
            arr[front]=-1;
            front++;
        }
    }
    int isempty(){
        if(front==rear){
            cout<<"Queue is empty"<<endl;
        }
    }
    int isfull(){
        if(rear==size){
            cout<<"Queue is full"<<endl;
        }
    }
    int peek(){
        if(front==rear){
            return -1;
        }
       else{
        return arr[front];
       } 
    } 
};

int main(){

return 0;
}