#include<iostream>
#include<vector>
#include<list>
#include<iterator>
using namespace std;
class Edge
{
    public:
    int DestinationVid;
    int weight;
    Edge(){

    }
    Edge(int Dvid,int w){
        DestinationVid=Dvid;
        weight=w;
    }
    void setEdgevalue(int Dvid,int w){
        DestinationVid=Dvid;
        weight=w;
    }
    void setWeight(int w){
        weight=w;
    }
    int getVid(){
        return DestinationVid;
    }
    int getWeight(){
        return weight;
    }

};
class Vertex
{
    public:
    int state_id;
    string state_name;
    list<Edge>edge_list;
    Vertex(){}
    Vertex(int id,string sname){
        id=0;
        sname="";
    }
    void setId(int id){
        state_id=id;
    }
    void setName(string sname){
        state_name=sname;
    }
    int getId(){
        return state_id;
    }
    string getSname(){
        return state_name;
    }
    list<Edge> getEdgelist(){
        return edge_list;
    }
};
class Graph
{
    public:
    vector<Vertex>vertices;
    void addvertex(Vertex newvertex){
        bool check=checkIfVertexExistById(newvertex.getId());
        if(check){
            cout<<"already present"<<endl;
            return;
        }
        vertices.push_back(newvertex);
        cout<<"v added"<<endl;

    }
    bool checkIfVertexExistById(int id){
        for(int i=0;i<vertices.size();i++){
            if(vertices.at(i).getId()==id){
                return true;
            }
        }
        return false;
    }
    void printgraph(){
        for(int i=0;i<vertices.size();i++){
            cout<<vertices.at(i).getSname();
        }
    }
};

int main()
{
    Graph g;
    Vertex v1;
    int option,id;
    string sname;

    do
    {
        /* code */
        cout<<"what operation do you want to perform."<<" enter 0 for exit"<<endl;
        cout<<"1. Add vertex"<<endl;
        cout<<"2. update vertes"<<endl;
        cout<<"3. delete vertex"<<endl;
        cout<<"4. Add edge"<<endl;
        cout<<"5. update edge"<<endl;
        cout<<"6. delete edge"<<endl;
        cout<<"7. check if 2 vertices are neigbor"<<endl;
        cout<<"8. print all neigbors"<<endl;
        cout<<"9. print graph"<<endl;
        cout<<"10. clear screen"<<endl;
        cout<<"0. Exit"<<endl;

        cin>>option;
        switch (option)
        {
        case 1:
            cout<<"add vertex id";
            cin>>id;
            cout<<"add state name";
            cin>>sname;
            v1.setId(id);
            v1.setName(sname);
            g.vertices.push_back(v1);
            break;
        case 2:
            
            break;
        case 3:
        
            break;
        case 4:
            
            break;
        case 5:
            
            break;
        case 6:
            
            break;
        case 7:
            
            break;
        case 8:
            system("cls");
            break;
        case 9:
            
            break;
        case 10:
            
            break;
        case 0: 
            cout<<"Exit";
            break;
        
        default:
            cout<<"enter proper option";
        }
        
    } while (option!=0);
}