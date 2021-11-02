#include<iostream>
#include<stack>
using namespace std;
//method 2
class queue
{
    stack<int>s1;
    stack<int>s2;
    public:
    void push(int x){
        s1.push(x);
    }
    int pop(){
        if(s1.empty() && s2.empty()){
            cout<<"empty";
            return -1;
        }
        if(!s1.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int topval=s2.top();
        s2.pop();
        return topval;
    }
    bool empty(){
        if(s1.empty() && s2.empty()){
            cout<<"empty";
            return true;
        }
        return false;
    }
};
//method 1
class queue
{
    stack<int>s1;
    public:
    void push(int x){
        s1.push(x);
    }
    int pop(){
        if(s1.empty()){
            cout<<"empty";
            return -1;
        }
        int x=s1.top();
        s1.pop();
        if(s1.empty()){
            return x;
        }
        int val=pop();
        s1.push(x);
        return val;
    }
    bool empty(){
        if(s1.empty()){
            cout<<"empty";
            return true;
        }
        return false;
    }
};
int main()
{
    queue ob;
    ob.push(1);
    ob.push(2);
    ob.push(3);
    ob.pop();
    cout<<ob.empty();
}