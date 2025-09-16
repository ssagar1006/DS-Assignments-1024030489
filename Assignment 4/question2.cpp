#include<iostream>
#include<queue>
using namespace std;
class Circular{
    public:
    int *arr;
    int currSize=0,cap;
    int f,r;
    public:
    Circular(int size){
        cap =size;
        arr=new int[cap];
        f=0;
        r=-1;
    }
    void enqueue(int data){
        if(currSize==cap){
            cout<<"Queue is full"<<endl;
            return;
        }
        else{
            r=(r+1)%cap;
            arr[r]=data;
            currSize++;
        }
    }
    void dequeue(){
        if(currSize==0){
            cout<<"Queue is empty"<<endl;
            return;
        }
        else{
            f=(f+1)%cap;
            currSize--;
        }
    }
    int peek(){
        if(currSize==0){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        else{
        return arr[f];
        }
        return;
    }
    bool isEmpty(){
        if(currSize==0){
             return false;
        }
    }

};
int main(){
    Circular c(5);\
    c.enqueue(10);
     c.enqueue(20);
      c.enqueue(30);
      cout<<"The front element is :"<<c.peek();
      c.dequeue();
      cout<<"Is queue empty:?"<<c.isEmpty();
    return 0;
}
