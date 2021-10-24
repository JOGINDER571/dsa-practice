 #include<iostream>
 #include<string>
 using namespace std;
 //check array is sorted or not
 bool sorted(int a[],int n){
     if(n==1){
         return true;
     }
     
     bool restarray=sorted(a+1,n-1);
     return (a[0]<a[1] && restarray);
 }
 //find the first and last occurence in array
 int first(int arr[],int n,int i,int k){
     if(i==n){
         return -1;
     }
     if(arr[i]==k){
         return i;
     }
     return first(arr,n,i+1,k);

 }
 int last(int a[],int n,int i,int k){
     if(i==(n)){
         return -1;
     }
     int restarray=last(a,n,i+1,k);
     
     if(restarray!= -1){
         return restarray;
     }
     if(a[i]==k){
         return i;
     }
     return -1;
 }
 //reverse string
 //1st method
 void reverseStr(string s,int i,int n){
     if(i==n){
         return;
     }
     reverseStr(s,i+1,n);
     cout<<s[i];
     return;
 }
 //2nd method
 void reverseStr(string s){
     if(s.length()==0){
         return;
     }
     string ros=s.substr(1);
     reverseStr(ros);
     cout<<s[0];
     return;
 }
 //replace pi with 3.14;
 void replacepi(string s){
     if(s.length()==0){
         return;
     }
     if(s[0]=='p' && s[1]=='i'){
         cout<<3.14;
         replacepi(s.substr(2));
     }else{
         cout<<s[0];
         replacepi(s.substr(1));
     }
 }
 //tower of hanoi
 void toh(int n,char src,char des,char help){
     if(n==0){
         return;
     }
     toh(n-1,src,help,des);
     cout<<"move "<<src<<"to "<<des<<endl;
     toh(n-1,help,des,src);
 }
 string removedup(string s){
     if(s.length()==0){
         return "";
     }
     char ch=s[0];
     string ans=removedup(s.substr(1));
     if(ch==ans[0]){
         return ans;
     }
     return ch+ans;
 }
 //end with x
 string end_with_x(string s){
     if(s.length()==0){
         return "";
     }
     char ch=s[0];
     string ans=end_with_x(s.substr(1));
     if(ch=='x'){
         return ans+ch;
     }
     return ch+ans;
 }
 // print all substring
 void subst(string s,string ans){
     if(s.length()==0){
         cout<<ans<<endl;
         return;
     }
     char ch=s[0];
     string ros=s.substr(1);
     subst(ros,ans);
     subst(ros,ans+ch);
 }
 int main(){
     int a[]={2,1,3,4,5,2};
    //  cout<<sorted(a,3);
    // cout<<first(a,6,0,8);
    // cout<<last(a,6,0,2);
    // string s="binod";
    // reverseStr(s,0,5);
    // reverseStr(s);
    string s1="pirfppis";
    // replacepi(s1);
    // toh(3,'A','C','B');
    
    // cout<<removedup("aaaaed");
    // cout<<end_with_x("xxabxcxd");
    subst("ABC","");
 }