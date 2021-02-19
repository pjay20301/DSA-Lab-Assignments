#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
int partition(int a[], int low, int high) {
  int pivot = a[high];
  int i = low - 1;
  for(int j = low; j <= high - 1; j++) {
    if(a[j] < pivot) {
      i++;
      swap(&a[i],&a[j]);
    }
  }
  swap(&a[i+1],&a[high]);
  return (i+1);
}
void quicksort(int a[], int low, int high) {
  if(low < high) {
    int pivot = partition(a,low,high);
    quicksort(a,low,pivot-1);
    quicksort(a,pivot+1,high);
  }
  return;
}

int ans = 0;
struct node {
  int vertex;
  struct node* next;
};

struct node* createNode(int v);

struct Graph {
  int numVertices;
  int* visited;
  struct node** adjLists;
};


void DFS(struct Graph* graph, int vertex) {
  struct node* adjList = graph->adjLists[vertex];
  struct node* temp = adjList;
  graph->visited[vertex] = 1;
  ans++;
  while (temp != NULL) {
    int connectedVertex = temp->vertex;

    if (graph->visited[connectedVertex] == 0) {
      DFS(graph, connectedVertex);
    }
    temp = temp->next;
  }
}

struct node* createNode(int v) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}

struct Graph* createGraph(int vertices) {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->numVertices = vertices;

  graph->adjLists = malloc(vertices * sizeof(struct node*));

  graph->visited = malloc(vertices * sizeof(int));

  int i;
  for (i = 0; i < vertices; i++) {
    graph->adjLists[i] = NULL;
    graph->visited[i] = 0;
  }
  return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {

  struct node* newNode = createNode(dest);
  newNode->next = graph->adjLists[src];
  graph->adjLists[src] = newNode;

  newNode = createNode(src);
  newNode->next = graph->adjLists[dest];
  graph->adjLists[dest] = newNode;
}


int main() {
  int n,m;
  scanf("%d %d",&n,&m);
  struct Graph* graph = createGraph(n);
  for(int i = 0; i < m; i++) {
    int u,v;
    scanf("%d %d",&u,&v);
    addEdge(graph, u, v);
  }
  int cnt[n];
  for(int i = 0; i < n; i++) {
    ans = 0;
    if(graph->visited[i] == 0) {
      DFS(graph,i);
    }
    cnt[i] = ans;
  }
  quicksort(cnt,0,n-1);
  double sum = 0;
  int c=0;
  for(int i = n-1; i >= 0; i--) {
      if(sum >= 0.8*n)
        break;
      else sum += cnt[i],c++;
  }
  printf("%d",c);
  return 0;
}