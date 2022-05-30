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


void init(listtype *h){ //그래프 리스트 초기화

    h->v=0;
    for (int i=0;i<Maxsize;i++){
        h->list[i]=NULL;
    } 

}
int insertvertex (listtype *h, int v)
{
    for(int i=0;i<v;i++){
        
        if((h->v)>=Maxsize){ //최대 10개 초과
        printf("그래프 최대 정점 개수 초과");
        return -1;
        }

        h->v++; //정점 개수 증가

    }

    return 1;
}

int insertedge (listtype *h,int u, int v)
{ //정점 u와 v 연결

    nodetype *new=(nodetype*)malloc(sizeof(nodetype)); //연결할 노드
    if(u>h->v ||v>h->v){ 
        printf("정점 번호 오류");
        return -1;
    }
    new->vertex=v; 
    new->link=h->list[u]; //정점 u와 연결
    h->list[u]=new;

    return 1;
}

int dfs (listtype *g,int v)
{   //탐색 시작 정점 : list[v]

    if(v>=Maxsize)
        return -1;

    dfsvisit[v]=1;  //방문한 정점 체크
    printf("[%d] ",v); 

    nodetype *ptr=g->list[v];

    for (;ptr;ptr=ptr->link){ //정점의 link의 vertex를 새로운 기준으로
        if (!dfsvisit[ptr->vertex]) //방문하지 않은 노드라면
            dfs(g,ptr->vertex); //recursive dfs
    }
    return 1;

}  
    


int bfs (listtype *g, int v)
{
    if(v>=Maxsize)
        return -1;

    int queue[Maxsize];
    int rear=-1;
    int front=-1;

    nodetype *ptr=g->list[v]; //파악할 리스트
    bfsvisit[v]=1; //방문한 노드 체크
    printf("[%d] ",v);
    queue[++rear]= v; //큐에 정점 삽입

    while(front!=rear){ //큐에 공간 남아있는 동안
        v=queue[++front]; //기준이 되는 정점
        for (;ptr;ptr=ptr->link){ 
            if(!bfsvisit[ptr->vertex]){ //방문하지 않은 노드
                printf("[%d] ", ptr->vertex);
                queue[++rear]=ptr->vertex; //큐에 정점 삽입
                bfsvisit[ptr->vertex]=1; //방문한 노드 체크
            }
        }

    }
    return 1;


}

void print (listtype *g)
{
    for(int i=0;i<g->v;i++){ 
        nodetype *p=g->list[i]; //정점 리스트[]
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
            free(list);
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
            insertedge(list, v,u);  //연결리스트 배열[]에 서로 연결 v,u 바꿔서
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
