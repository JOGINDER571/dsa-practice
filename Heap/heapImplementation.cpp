#include<iostream>
#include<math.h>
using namespace std;
void swap(int &x,int &y){
    int temp=x;
    x=y;
    y=temp;
}
class Minheap
{
    public:
    int* harr;
    int capacity;
    int heap_size;

    Minheap(int cap){
        heap_size=0;
        capacity=cap;
        harr=new int[cap];
    }

    void searchVal(int k)
    {
        for(int i=0;i<heap_size;i++){
            if(harr[i]==k){
                cout<<"found"<<endl;
                return;
            }
        }
        cout<<"not found"<<endl;
    }
    void printarr(){
        for(int i=0;i<heap_size;i++){
            cout<<harr[i]<<" ";
        }
        cout<<endl;
    }
    int height(){
        return ceil(log2(heap_size+1))-1;
    }
    int parent(int i){
        return (i-1)/2;
    }
    int left(int i){
        return (2*i+1);
    }
    int right(int i){
        return (2*i+2);
    }
    void insert(int val){
        if(capacity==heap_size){
            cout<<"overflow"<<endl;
        }
        heap_size++;
        int i=heap_size-1;
        harr[i]=val;
        while(i!=0 && harr[parent(i)]>harr[i]){
            swap(harr[parent(i)],harr[i]);
            i=parent(i);
        }
    }
    int getMin(){
        return harr[0];
    }
    void heapify(int i){
        int l=left(i);
        int r=right(i);
        int smallest=i;
        if(l<heap_size &&harr[l]<harr[i]){
            smallest=l;
        }
        if(r<heap_size &&harr[r]<harr[l]){
            smallest=r;
        }
        if(smallest!=i){
            swap(harr[i],harr[smallest]);
            heapify(smallest);
        }
    }
    int extractMin(){
        if(heap_size<=0){
            return INT_FAST8_MAX;
        }
        if(heap_size==1){
            return harr[heap_size-1];
        }
        int root=harr[0];
        harr[0]=harr[heap_size-1];
        heap_size--;
        heapify(0);
        return root;
    }
    void deletion(int i){
        deletekey(i,INT8_MIN);
        extractMin();
    }
    void deletekey(int i,int value){
        harr[i]=value;
        while (i!=0 && harr[i]<harr[parent(i)])
        {
            swap(harr[i],harr[parent(i)]);
            i=parent(i);
        }
    }
};
int main()
{
    int size;
    cin>>size;
    Minheap obj(size);
    cout<<"min heap created"<<endl;
    int option,value;

    do
    {
        /* code */
        cout<<"what operation do you want to perform."<<" enter 0 for exit"<<endl;
        cout<<"1. insert key/node"<<endl;
        cout<<"2. search key/node"<<endl;
        cout<<"3. delete key/node"<<endl;
        cout<<"4. get min"<<endl;
        cout<<"5. extract min"<<endl;
        cout<<"6. height of heap"<<endl;
        cout<<"7. print traversal of heap"<<endl;
        cout<<"8. clear screen"<<endl;
        cout<<"0. Exit"<<endl;

        cin>>option;
        switch (option)
        {
        case 1:
            cout<<"Enter value";
            cin>>value;
            obj.insert(value);
            break;
        case 2:
            obj.searchVal(value);
            break;
        case 3:
            obj.deletion(3);
            break;
        case 4:
            cout<<obj.getMin()<<endl;
            break;
        case 5:
            cout<<obj.extractMin();
            break;
        case 6:
            cout<<obj.height();
            break;
        case 7:
            obj.printarr();
            break;
        case 8:
            system("cls");
            break;
        case 0:
            cout<<"Exit";
            break;
        
        default:
            cout<<"enter proper option";
        }
        
    } while (option!=0);
    

}