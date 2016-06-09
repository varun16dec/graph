#include<iostream>
#include<list>

using namespace std;
/**

        Connected components of an undirected graph using BFS
        graph is :
        {0,2},{0,4}{2,4},{4,6},{4,8}
        {1,3}
        {5,7},{5,9},{7,9};

*/
class Graph{

        int v;                      //no of vertices
        list<int> * adj;            //adjacency list pointer
        bool *visited;              //pointer to array to maintain visited property

        public:

        Graph(int v)                //initialize and assigning mememory
        {
            this->v=v;
            adj=new list<int>[v];
            visited=new bool[v];

        }

        void addEdge(int src,int dest)      //adding edges
        {
            adj[src].push_back(dest);       //src to destination
            adj[dest].push_back(src);       //as undirected so from destination to source too
        }

        void BFS(int s)
        {
            list<int> queue;                //queue
            visited[s]=true;                //setting the first vertex as visited
            queue.push_back(s);             //inserting in queue's rear

            list<int>::iterator i;          //defining an iterator for list

            while(!queue.empty())           //while queue is not empty
            {
                s=queue.front();            //assign s as front of queue
                cout<<s<<" ";               //print it
                queue.pop_front();          //delete queue front
                for(i=adj[s].begin();i!=adj[s].end();++i)       //for each vertex check its neighbour vertex
                {
                if(!visited[*i])                                //if vertex is not visited
                {
                    visited[*i]=true;                           //set to visited
                    queue.push_back(*i);                        //insert in queue's rear
                }
                }
            }
        }
        void connectivity()
        {
                for(int i=0;i<v;++i)                            //for each vertex
                if(!visited[i])                                 //if not visited
                {
                    cout<<endl<<"Connectivity starting vertex : "<<i<<" : ";
                    BFS(i);                                                     //call bfs for that vertex

                 }
        }
};
int main()
{
    Graph g(10);
    g.addEdge(0,2);
    g.addEdge(0,4);
    g.addEdge(2,4);
    g.addEdge(4,6);
    g.addEdge(4,8);
    g.addEdge(1,3);
    g.addEdge(5,7);
    g.addEdge(5,9);
    g.addEdge(7,9);

    g.connectivity();
}
