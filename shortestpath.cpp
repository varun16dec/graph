#include<iostream>
#include<list>

using namespace std;

/**
            Shortest path evaluation
            Breadth first search is used for shortest path evaluation
*/

class Graph {

    int v;          //no of vertices
    list<int>* adj; //pointer to adjacency list

  public:

    Graph(int v) {
        this->v=v;              //initialize the vertices
        adj=new list<int>[v];   //make adjacency list
    }
    void addEdge(int src,int dest) {
        adj[src].push_back(dest);       //add an edge from source to destination
        adj[dest].push_back(src);       //as undirected add an edge from destination to sourcce too
    }
    void BFSAndDistance(int s) {
        bool * visited=new bool[v];     //list maintain the visited property of a vertex
        int  * distance=new int[v];     //list stores the shortest distance from origin vertex

        for(int i=0; i<v; ++i) {        //for each vertex
            visited[i]=false;           //set visited to false
            distance[i]=999;            //and distance from origin vertex infinite(used a large integer ex. 999)
        }

        list<int> queue;                //queue for bfs implementation

        visited[s]=true;                //set the visited property of starting vertex as true
        distance[s]=0;                  //and distance to 0
        queue.push_back(s);             //add it to queue then

        list<int>::iterator i;          //define an list iterator
        while(!queue.empty()) {
            s=queue.front();            //take out front of queue
            cout<<"Vertex : "<<s<<"  Distance : "<<distance[s]<<endl;       //print vertex no and shortest distance
            queue.pop_front();          //pop the front from queue

            for(i=adj[s].begin(); i!=adj[s].end(); ++i) {       //for each vertex check its list
                if(!visited[*i]) {                              //if not visited
                    visited[*i]=true;                           //then set visited to true
                    distance[*i]=distance[s]+1;                 //and add the distance +1 to the neighbour one
                    queue.push_back(*i);                        //insert the vertex to queue
                }
            }
        }
    }
};
int main() {
    Graph g(4);         //make a graph of 4 vertices
    g.addEdge(0,2);     //define edges
    g.addEdge(0,1);
    g.addEdge(2,3);
    g.addEdge(3,3);

    cout<<"shortest path starting with vertex : 2"<<endl;
    g.BFSAndDistance(2);        //call method for shortest path calculation
}
