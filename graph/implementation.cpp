#include <iostream>
#include <vector>
#include <list>
#include <iterator>
using namespace std;
class Edge
{
public:
    int DestinationVid;
    int weight;
    Edge()
    {
    }
    Edge(int Dvid, int w)
    {
        DestinationVid = Dvid;
        weight = w;
    }
    void setEdgevalue(int Dvid, int w)
    {
        DestinationVid = Dvid;
        weight = w;
    }
    void setWeight(int w)
    {
        weight = w;
    }
    int getDVid()
    {
        return DestinationVid;
    }
    int getWeight()
    {
        return weight;
    }
};
class Vertex
{
public:
    int state_id;
    string state_name;
    list<Edge> edge_list;
    Vertex() {}
    Vertex(int id, string sname)
    {
        id = 0;
        sname = "";
    }
    void setId(int id)
    {
        state_id = id;
    }
    void setName(string sname)
    {
        state_name = sname;
    }
    int getId()
    {
        return state_id;
    }
    string getSname()
    {
        return state_name;
    }
    list<Edge> getEdgelist()
    {
        return edge_list;
    }
    void printEdgeList()
    {
        cout << "[";
        for (auto it = edge_list.begin(); it != edge_list.end(); it++)
        {
            cout << it->getDVid() << "(" << it->getWeight() << ") --> ";
        }
        cout << "]";
        cout << endl;
    }
};
class Graph
{
public:
    vector<Vertex> vertices;
    //add vertex
    void addvertex(Vertex newvertex)
    {
        bool check = checkIfVertexExistById(newvertex.getId());
        if (check)
        {
            cout << "already present" << endl;
            return;
        }
        vertices.push_back(newvertex);
        cout << "v added" << endl;
    }
    bool checkIfVertexExistById(int id)
    {
        for (int i = 0; i < vertices.size(); i++)
        {
            if (vertices.at(i).getId() == id)
            {
                return true;
            }
        }
        return false;
    }
    //add edge
    void addEdgebyid(int id1, int id2, int w)
    {
        int check1 = checkIfVertexExistById(id1);
        int check2 = checkIfVertexExistById(id2);
        if (check1 && check2)
        {
            int check3 = checkIfEdgeExistById(id1, id2);
            if (check3)
            {
                cout << "Edge already exist" << endl;
            }
            else
            {
                for (int i = 0; i < vertices.size(); i++)
                {
                    if (vertices.at(i).getId() == id1)
                    {
                        Edge e(id2, w);
                        vertices.at(i).edge_list.push_back(e);
                    }
                    else if (vertices.at(i).getId() == id2)
                    {
                        Edge e(id1, w);
                        vertices.at(i).edge_list.push_back(e);
                    }
                }
                cout << "added successfully" << endl;
            }
        }
        else
        {
            cout << "invalid id" << endl;
        }
    }
    bool checkIfEdgeExistById(int id1, int id2)
    {
        Vertex v = getVertexbyid(id1);
        list<Edge> e;
        e = v.getEdgelist();
        bool flag = false;
        for (auto it = e.begin(); it != e.end(); it++)
        {
            if (it->getDVid() == id2)
            {
                flag = true;
                return flag;
                break;
            }
        }
        return flag;
    }
    Vertex getVertexbyid(int id)
    {
        Vertex temp;
        for (int i = 0; i < vertices.size(); i++)
        {
            temp = vertices.at(i);
            if (temp.getId() == id)
            {
                return temp;
            }
        }
        return temp;
    }
    void printgraph()
    {
        for (int i = 0; i < vertices.size(); i++)
        {
            Vertex temp;
            temp = vertices.at(i);
            cout << temp.getSname() << "(" << temp.getId() << ")--> ";
            temp.printEdgeList();
        }
    }
};

int main()
{
    Graph g;
    Vertex v1;
    int option, id;
    string sname;

    do
    {
        /* code */
        cout << "what operation do you want to perform."
             << " enter 0 for exit" << endl;
        cout << "1. Add vertex" << endl;
        cout << "2. update vertes" << endl;
        cout << "3. delete vertex" << endl;
        cout << "4. Add edge" << endl;
        cout << "5. update edge" << endl;
        cout << "6. delete edge" << endl;
        cout << "7. check if 2 vertices are neigbor" << endl;
        cout << "8. print all neigbors" << endl;
        cout << "9. print graph" << endl;
        cout << "10. clear screen" << endl;
        cout << "0. Exit" << endl;

        cin >> option;
        switch (option)
        {
        case 1:
            cout << "add vertex id";
            cin >> id;
            cout << "add state name";
            cin >> sname;
            v1.setId(id);
            v1.setName(sname);
            g.vertices.push_back(v1);
            break;
        case 2:

            break;
        case 3:

            break;
        case 4:
            cout << "Edge operation :" << endl;
            cout << "Enter source id" << endl;
            cin >> id;
            cout << "Enter destinaton id" << endl;
            int did, weight;
            cin >> did;
            cout << "enter weight" << endl;
            cin >> weight;
            g.addEdgebyid(id, did, weight);
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
            g.printgraph();
            break;
        case 10:

            break;
        case 0:
            cout << "Exit";
            break;

        default:
            cout << "enter proper option";
        }

    } while (option != 0);
}