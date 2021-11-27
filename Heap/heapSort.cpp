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
        heap_size=cap;
        capacity=cap;
        harr=new int[cap];  
    }
    void printarr(){
        for(int i=0;i<capacity;i++){
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
    void getunsortedarr(){
        cout<<"enter"<<capacity<<"no of elements to sort"<<endl;
        for(int i=0;i<capacity;i++){
            cin>>harr[i];
        }
    }
    void heapsort(){
        int temp[capacity];
        for(int i=0;i<capacity;i++){
            temp[i]=extractMin();
            cout<<temp[i]<<" ";
        }
    }
};    

int main()
{
    int size;
    cout<<"enter size"<<endl;
    cin>>size;
    Minheap obj(size);
    obj.getunsortedarr();
    cout<<"unsort arr"<<endl;
    obj.printarr();
    for(int i=(size/2)-1;i>=0;i--){
        obj.heapify(i);
    }
    cout<<"sort arr"<<endl;
    obj.heapsort();

}