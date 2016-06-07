#include<stdio.h>
#include<stdlib.h>

struct AdjacencyNode
{
    int dest;
    AdjacencyNode * next;
};

struct AdjacencyList
{
    AdjacencyNode * head;
};

struct Graph
{
    int v;
    AdjacencyList *array;
};



AdjacencyNode*  createNode(int dest)
{
    AdjacencyNode * newnode =(AdjacencyNode*)malloc(sizeof(AdjacencyNode));
    newnode->dest=dest;
    newnode->next=NULL;

    return newnode;
}

Graph* createGraph(int v)
{
    Graph* graph=(Graph*)malloc(sizeof(Graph));
    graph->v=v;
    graph->array=(AdjacencyList*)malloc(v*sizeof(AdjacencyList));


    int i;
    for(int i=0;i<v;i++)
        graph->array[i].head=NULL;

    return graph;
}

void addEdge(Graph* graph,int src,int dest)
{
        AdjacencyNode* newnode=createNode(dest);

        if(graph->array[src].head==NULL)
        {
            graph->array[src].head=newnode;
        }
        else
        {
            AdjacencyNode* ptr=graph->array[src].head;

            while(ptr->next!=NULL)
                ptr=ptr->next;
            ptr->next=newnode;
        }

        //adding node from destination to src as its undirected graph

        newnode=createNode(src);
          if(graph->array[dest].head==NULL)
        {
            graph->array[dest].head=newnode;
        }
        else
        {
            AdjacencyNode* ptr=graph->array[dest].head;

            while(ptr->next!=NULL)
                ptr=ptr->next;
            ptr->next=newnode;
        }

}

void printGraph(Graph* graph)
{
    int v;
    for(v=0;v<graph->v;++v)
    {
        AdjacencyNode* ptr=graph->array[v].head;
        printf("Adjacency list of vertex %d : ",v);
        while(ptr)
        {
            printf(" -> %d ",ptr->dest);
            ptr=ptr->next;
        }
        printf("\n");
    }
}


int main()
{

    int v=5;
    Graph* graph=createGraph(v);
    addEdge(graph,0,1);
    addEdge(graph,0,4);
    addEdge(graph,1,2);
    addEdge(graph,1,3);
    addEdge(graph,1,4);
    addEdge(graph,2,3);
    addEdge(graph,3,4);
    printGraph(graph);
}
