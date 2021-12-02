#include<iostream>
using namespace std;
class PQueue
{
    public:
    int *PQpriority;
    char *PQdata;
    int front,rear;
    PQueue(int size){
        PQdata=new char[size];
        PQpriority=new int[size];
        front=rear=-1;
    }
    void insert(char element,int pr){
        int i;
        if(front==-1){
            front=rear=0;
            PQdata[0]=element;
            PQpriority[0]=pr;
        }
        else{
            for(i=rear;i>=front;i--){
                if(pr>PQpriority[i]){
                    PQdata[i+1]=PQdata[i];
                    PQpriority[i+1]=PQpriority[i];
                }else{
                    break;
                }
            }
            PQdata[i+1]=element;
            PQpriority[i+1]=pr;
            rear++;
            cout<<"inserted"<<endl;
        }
    }
    void deletion(){
        if(front==-1){
            cout<<"underflow"<<endl;
            return;
        }
        if(front==rear){
            front=rear=-1;
        }
        else{
            front++;
        }
    }
    void getFirst(){
        if(front==-1){
            cout<<"empty"<<endl;
        }        
        cout<<PQdata[front];
    }

};
int main()
{
    PQueue obj(4);
    obj.insert('A',4);
    obj.insert('B',5);
    obj.deletion();
    obj.getFirst();
}