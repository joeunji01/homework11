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


void init(listtype *h){

    h->v=0;
    for (int i=0;i<Maxsize;i++){
        h->list[i]=NULL;
    } 

}
int insertvertex (listtype *h, int v)
{
    if((h->v)+1>Maxsize){ //최대 10개 초과
        printf("그래프 최대 정점 개수 초과");
        return -1;
    }
    h->v++; //정점 개수 증가

    return 1;
}

int insertedge (listtype *h,int u, int v)
{ //정점 번호 u와 기존 연결, v는 새로운 정점

    nodetype *new; //새로운 노드 
    if(u>=h->v ||v>=h->v){
        printf("정점 번호 오류");
    }
    new->vertex=v;
    new->link=h->list[u];
    h->list[u]=new;

    return 1;
}

void dfs (listtype *g,int v)
{   //탐색 시작 정점 : list[v]
    nodetype *ptr;
    int visit[Maxsize];
    visit[v]=1;
    
    printf("[%d] ",v);
    for (ptr=g->list[v]->link;ptr;ptr=ptr->link){
        if(!visit[ptr->vertex])
            dfs(g,ptr->vertex);
    }
    


}

void bfs (listtype *g)
{

}

void print (listtype *g)
{

}


int main (void){
    
    listtype *list;
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
			printf("Vertex = ");
			scanf("%d", &vertex);
			insertvertex(list,vertex);
			break;
		case 'e': case 'E':
            printf("연결할 정점, 새로운 정점 입력 = ");
			scanf("%d %d", &u,&v);
			insertedge(list, u,v);
			break;

		case 'd': case 'D':
			dfs(list,v);
			break;
		case 'b': case 'B':
			bfs(list);
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
