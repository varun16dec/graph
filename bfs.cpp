#include<iostream>
#include<list>

using namespace std;
/**
        Breadth first search for a graph using c++ stl
        this version implements undirected graph

*/

class Graph {

    int v;
    list<int> * adj;

  public:

    Graph(int v);                       //initialize no of vertices
    void addEdge(int src,int dest);     //to make edges from src to dest
    void bfs(int s);                    //doing bfs
};


Graph::Graph(int v) {                       //constructor to  initialize veritices and adjacency list

    this->v=v;                              // no of vertices
    adj=new list<int>[v];                   // allocating an array of size v and assigning its pointer to adj
}

void Graph::addEdge(int src,int dest) {
    adj[src].push_back(dest);
}

void Graph::bfs(int s) {

    bool *visited=new bool[v];              //defining an array of size v to maintain its visit property
    for(int i=0; i<v; ++i)
        visited[i]=false;                   //setting all of them unvisited


    list<int> queue;                      //defining queue

    visited[s]=true;                      //mark s as visited and push in
    queue.push_back(s);

    list<int>::iterator i;                //define iterator

    while(!queue.empty()) {

        s=queue.front();
        cout<<s<<" ";
        queue.pop_front();

        for(i=adj[s].begin(); i!=adj[s].end(); ++i) {   //visit all the direct neighbours of s
            if(!visited[*i]) {
                visited[*i]=true;                       //set there visiblity true
                queue.push_back(*i);                    //push it into stack
            }
        }
    }
}
int main() {

    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(2,0);
    g.addEdge(2,3);
    g.addEdge(3,3);

    cout<<"BFS with start vertex 2 : ";
    g.bfs(2);
}
