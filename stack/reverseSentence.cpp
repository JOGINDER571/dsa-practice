#include<iostream>
#include<stack>
using namespace std;
//reverse a string
void reverse(string s){
    stack<string>st;
    for(int i=0;i<s.length();i++){
        string word="";
        while(s[i]!=' ' && i<s.length()){
            word+=s[i];
            i++;
        }
        st.push(word);
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}
//reverse a stack
void insert(stack<int>&st,int ele){
    if(st.empty()){
        st.push(ele);
        return;
    }
    int tople=st.top();
    st.pop();
    insert(st,ele);
    st.push(tople);
}
void reverseStack(stack<int>&st){
    if(st.empty()){
        return;
    }
    int ele=st.top();
    st.pop();
    reverseStack(st);
    insert(st,ele);
}
int main(){
    string s="hello how are you";
    // reverse(s);
    stack<int>st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    reverseStack(st);
    while (!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    
}
