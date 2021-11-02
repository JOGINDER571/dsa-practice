#include<iostream>
#include<stack>
using namespace std;
int prefixNotation(string s){
    stack<int>st;
    for(int i=s.length()-1;i>=0;i--){
        if(s[i]>='0' && s[i]<='9'){
            st.push(s[i]-'0');
        }else{
            int o1=st.top();
            st.pop();
            int o2=st.top();
            st.pop();

            switch (s[i])
            {
            case '+':
                st.push(o1+o2);
                break;
            case '-':
                st.push(o1-o2);
                break;
            case '*':
                st.push(o1*o2);
                break;
            case '/':
                st.push(o1/o2);
                break;
            
            default:
                break;
            }
        }
        
    }
    return st.top();
}
int main()
{
    cout<<prefixNotation("-+7*45+20");
}
