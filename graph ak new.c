#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


void creategf();
void displaygf();
void dfs(int v);
void initialize();
void bfs(int v);

int adjt[20][20];
int n; //n is no of vertices
int edges;
int v;

int stack[20];
int que[20];
int visited[20] ={0};
int main(){
    creategf();
    displaygf();
    initialize();
    
    printf("Graph traversal using Deapth first search\n");
    dfs(v);
    
    printf("\nGraph traverslusing Breadth first search\n");
    bfs(v);
    return 0;
}


void creategf(){
    int origin,dest;
    printf("Enter the no of vertices\n");
    scanf("%d",&n);
    edges = n*(n-1);
	int i;
    for( i=0;i<edges;i++)
    {
        printf("Enter the edge press 0,0 to quit\n");
        scanf("%d%d",&origin,&dest);
        if((origin ==0) && (dest==0))
            break;
        else
            adjt[origin-1][dest-1] = 1;
    }
}
void initialize(){
    printf("Enter the starting node\n");
    scanf("%d",&v);
    int i;
    for( i=0;i<n;i++){
        visited[i]= false;
    }
    
}
void displaygf(){
	int i, j;
    for (i=0;i<n;i++)
    {for (j=0;j<n;j++)
        {
            printf("%3d",adjt[i][j]);
        }
            printf("\n");
    }

}


int top = -1;
void dfs(int v){
    int i;
	stack[top++] = v-1;
	visited[v-1] = 1;
	printf("%d  ", v);
	for(i = 0; i < n; i++){
		if(adjt[v-1][i] == 1 && visited[i] == 0){
			dfs(i+1);
		}
	}
}

    
void bfs(int v){
	int i;
    for(i=0;i<n;i++)
        visited[i]= false;
    int front,rear;
    front = -1;
    rear = -1;
    printf("%2d->",v);
    visited[v-1]= true;
    rear ++;
    front == -1? front ++, front;
    que[rear]= v;
    while(front <=rear){
        v =que[front];
        front++;
        int i;
        for(i =0;i<n;i++){
            if ((adjt[v][i] == 1) && (visited[i] == false))
            {
                printf("%2d->",i);
                visited[i] = true;
                rear++;
                que[rear]=i;
            }
        }
    printf("%2d",i);
    }
}
   


