#include <stdio.h>
#include <stdlib.h>
#define Maxsize 10 //그래프 정점의 최대 개수

typedef struct Node{
    int vertex;
    struct Node *link;
}nodetype;

typedef struct List{ //그래프 리스트
    int v; //가지고 있는 정점 개수
    nodetype *list[Maxsize]; 
}listtype;

int dfsvisit[Maxsize]; 
int bfsvisit[Maxsize];


void init(listtype *h){

    h->v=0;
    for (int i=0;i<Maxsize;i++){
        h->list[i]=NULL;
    } 

}
int insertvertex (listtype *h, int v)
{
    for(int i=0;i<v;i++){
        
        if((h->v)+1>Maxsize){ //최대 10개 초과
        printf("그래프 최대 정점 개수 초과");
        return -1;}

    h->v++; //정점 개수 증가

    }

    return 1;
}

int insertedge (listtype *h,int u, int v)
{ //정점 u와 v 연결

    nodetype *new=(nodetype*)malloc(sizeof(nodetype)); //새로운 노드 
    if(u>h->v ||v>h->v){
        printf("정점 번호 오류");
        return -1;
    }
    new->vertex=v;
    new->link=h->list[u];
    h->list[u]=new;

    return 1;
}

void dfs (listtype *g,int v)
{   //탐색 시작 정점 : list[v]

    dfsvisit[v]=1;
    printf("[%d] ",v);

    nodetype *ptr=g->list[v];

    for (;ptr;ptr=ptr->link){
        if (!dfsvisit[ptr->vertex])
            dfs(g,ptr->vertex);
    }

}  
    


void bfs (listtype *g, int v)
{
    int queue[Maxsize];
    int rear=0;
    int front=0;

    nodetype *ptr=g->list[v];
    bfsvisit[v]=1;
    printf("[%d] ",v);
    queue[rear++]= v; 

    while(front!=rear){
        v=queue[++front];
        for (;ptr;ptr=ptr->link){
            if(!bfsvisit[ptr->vertex]){
                printf("[%d] ", ptr->vertex);
                queue[rear++]=ptr->vertex;
                bfsvisit[ptr->vertex]=1;
            }
        }

    }



}

void print (listtype *g)
{
    for(int i=0;i<g->v;i++){
        nodetype *p=g->list[i];
        printf("정점 [%d]의 인접 리스트 -> ",i);
        while(p!=NULL){
            printf("[%d] ",p->vertex); 
            p=p->link;
        }
        printf("\n");
    }
}


int main (void){
    
    listtype *list=(listtype*)malloc(sizeof(listtype));

    char command;
    int vertex;
    int u, v; 

    printf("[--------------- [조은지] [2021076020] ---------------]");
    
   do{
		printf("\n\n");
		printf("----------------------------------------------------------------\n");
		printf("                       Graph Searches                           \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize Graph     = z                                     \n");
		printf(" Insert Vertex        = v      Insert Edge                  = e \n");
		printf(" Depth First Search   = d      Breath First Search          = b \n");
		printf(" Print Graph          = p      Quit                         = q \n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'z': case 'Z':
			init(list);
			break;
		case 'q': case 'Q':
			break;
		case 'v': case 'V':
			printf("삽입할 정점 개수 입력 = ");
			scanf("%d", &vertex);
			insertvertex(list,vertex);
			break;
		case 'e': case 'E':
            printf("연결할 정점 2개 입력 = ");
			scanf("%d %d", &u,&v);
			insertedge(list, u,v);
            insertedge(list, v,u);
			break;

		case 'd': case 'D':
            printf("dfs 시작 정점 입력: ");
            scanf("%d",&v);
			dfs(list,v);
			break;
		case 'b': case 'B':
            printf("bfs 시작 정점 입력: ");
            scanf("%d",&v);
			bfs(list,v);
			break;

		case 'p': case 'P':
			print(list);
			break;

		default:
			printf("\n       >>>>>        retry        <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;
}
