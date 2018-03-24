#include <vector>
#include <stack>
#include <iostream>
#include <list>

using namespace std;

class Graf
{
    struct Node
    {
        size_t connect;
        bool seen;

    };
    size_t controlVertexNr;
    size_t vertexNr;

    //vector<Node> neighbourList;
    vector<vector<Node>> grafTable;

    stack<size_t> helpStack;
    vector <bool> visited;
    vector<size_t> bridges;
public:

    Graf(size_t vertice):vertexNr(vertice)
    {
        grafTable.resize(vertice);
        visited.resize(vertice);

    }
    Graf(){}
    ~Graf(){


    }
    void resize(size_t newSize)
    {
        grafTable.resize(newSize);
        visited.resize(newSize);
        vertexNr = newSize;
    }
    void addVertices(size_t first, size_t second)
    {
        Node node;
        //node->next= nullptr;
        node.seen = false;
        node.connect = second;
       grafTable[first].push_back(node);
        node.connect = first;
        grafTable[second].push_back(node);

    }
    bool areDuplicationsInBridges(size_t i, size_t j)
    {
        for (auto iter = bridges.begin(); iter != bridges.end(); iter++)
        {
            auto first = (*iter);
           auto  second = (*(++iter));
            if ((first == j && second == i)||(first == i && second) == j)
                return true;

        }

        return false;
    }
        bool isConnectivity()
    {


        controlVertexNr= 0;

        while(helpStack.empty()==false)
        {
            auto node = helpStack.top();
            helpStack.pop();
            controlVertexNr++;
            for(auto it = grafTable[node].begin();it!=grafTable[node].end();it++)
            {
                auto u = (*it).connect;
                if(!visited[u])
                {
                    visited[u]= true;
                    helpStack.push(u);
                }
            }

        }
        for(auto it = visited.begin();it!=visited.end();it++)
            if(!(*it))
                return false;
        return true;
    }


    void clearVisits()
    {
        for(auto i = 0; i<vertexNr; i++)
            visited[i] = false;
    }



    vector<size_t> hasBridges()
    {
        for(auto i=0;i<vertexNr;++i)
        {
            for(auto it = grafTable[i].begin();it!=grafTable[i].end();it++)
            {
                clearVisits();
                visited[i]= true;
                visited[(*it).connect]= true;
                for(auto j =0;j<vertexNr;j++)
                    if(!visited[j])
                    {
                        helpStack.push(j);
                        visited[j]=true;
                        break;
                    }


                    if(!isConnectivity())
                    {
                        if(!areDuplicationsInBridges(i, (*it).connect))
                        {
                            bridges.push_back(i);
                            bridges.push_back((*it).connect);
                        }

                    }



            }

        }
        return bridges;
    }


};
