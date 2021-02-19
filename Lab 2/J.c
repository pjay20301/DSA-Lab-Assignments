#include <stdio.h>
#include<stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int V;
    struct Node** AdjLists;
    int* visited;
    int* dist;
    int* pre;
};

struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode -> vertex = v;
    newNode -> next = NULL;
    return newNode;
};

struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph -> V = vertices;

    graph -> AdjLists = malloc(vertices * sizeof(struct Node*));
    graph -> visited = malloc(vertices * sizeof(int));
    graph -> dist = malloc(vertices * sizeof(int));
    graph -> pre = malloc(vertices * sizeof(int));

    int i;
    for(int i = 0; i < vertices; i++) {
        graph -> AdjLists[i] = NULL;
        graph -> visited[i] = 0;
        graph -> dist[i] = 1e9;
        graph -> pre[i] = -1;
    }
    return graph;
}

void addEdge(struct Graph* graph, int u, int v) {
    struct Node* newNode = createNode(v);
    newNode -> next = graph -> AdjLists[u];
    graph -> AdjLists[u] = newNode;

    newNode = createNode(u);
    newNode -> next = graph -> AdjLists[v];
    graph -> AdjLists[v] = newNode;
}

struct queue {
    int nodes[5000];
    int front;
    int rear;
};

struct queue* createQueue() {
    struct queue* q = malloc(sizeof(struct queue));
    q -> front = -1;
    q -> rear = -1;
    return q;
};
void enqueue(struct queue* q, int v){
    if(q -> rear == 5000 - 1)
        return;
    else {
        if(q -> front == -1)
            q -> front = 0;
        q -> rear++;
        q -> nodes[q -> rear] = v;
    }
}

int isEmpty(struct queue* q) {
    if(q -> rear == -1)
        return 1;
    else 
        return 0;
}

int dequeue(struct queue* q) {
    int node;
    if(isEmpty(q)) {
        node = -1;
    } else {
    node = q -> nodes[q -> front];
    q -> front++;
    if(q -> front > q -> rear) {
        q -> front = q-> rear = -1;
    }
    }
    return node;
}

void bfs(struct Graph* graph, int start, int end) {
    struct queue* q = createQueue();

    graph -> visited[start] = 1;
    graph -> dist[start] = 0;
    enqueue(q,start);
    while(!isEmpty(q)) {
        int current = dequeue(q);
        struct Node* temp = graph -> AdjLists[current];
        while(temp) {
            int adj = temp -> vertex;

            if(graph -> visited[adj] == 0) {
                graph -> visited[adj] = 1;
                graph -> dist[adj] = graph -> dist[current] + 1;
                graph -> pre[adj] = current;
                enqueue(q,adj);
            }
            temp = temp -> next;
        }
    }
    int maxDist = 100 * (graph -> dist[end]);
   printf("%d",maxDist);
   return;
}

int main() {
    int n,m,a,b;
    scanf("%d %d %d %d",&n,&m,&a,&b);
    struct Graph* graph = createGraph(n);
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d",&u,&v);
        addEdge(graph,u,v);
    }
    bfs(graph,a,b);

    return 0;
}