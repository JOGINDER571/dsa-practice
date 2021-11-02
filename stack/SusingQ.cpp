#include<iostream>
#include<queue>
using namespace std;
//method 1
class stack
{
    int n;
    queue<int>q1;
    queue<int>q2;
    public:
    stack(){
        n=0;
    }
    void push(int x){//o(n)
        q2.push(x);
        n++;
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        queue<int>temp;
        temp=q1;
        q1=q2;
        q2=temp;

    }
    void pop(){
        q1.pop();
        n--;
    }
    int top(){
        return q1.front();
    }
    int size(){
        return n;
    }
};
//method 2
class Stack
{
    int n;
    queue<int>q1;
    queue<int>q2;
    public:
    Stack(){
        n=0;
    }
    void push(int x){
        q1.push(x);
        n++;
    }
    void pop(){//o(n)
        
        if(q1.empty()){
            cout<<"empty";
            return;
        }
        
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        n--;
        queue<int>temp;
        temp=q1;
        q1=q2;
        q2=temp;

    
    }
    int top(){
        
        if(q1.empty()){
            cout<<"empty";
            return -1;
        }
        
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        int ans=q1.front();
        q2.push(ans);
        

        queue<int>temp;
        temp=q1;
        q1=q2;
        q2=temp;
        
       
        return ans;
    }
    int size(){
        return n;
    }
};
int main(){
    Stack ob;
    ob.push(1);
    ob.push(2);
    ob.push(3);
    cout<<ob.top();
    ob.pop();
    cout<<ob.top();
    ob.pop();
    cout<<ob.top();
    ob.pop();
    ob.pop();
    cout<<ob.size();
}