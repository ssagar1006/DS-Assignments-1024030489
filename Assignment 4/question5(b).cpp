#include<iostream>
#include<queue>
using namespace std;
class Queue{
    public:
    queue<int>q1;

    void push(int x){
    q1.push(x);
    for(int i=0;i<q1.size();i++){
       q1.push(q1.front());
       q1.pop() ;
    }
    
}
    void pop(){
        q1.pop();
    }

    int top(){
         int ans=q1.front();
         return ans;
        }
};

int main(){
    Queue q1;
    q1.push(10);
    q1.push(20);
    q1.push(30);
    return 0;
}