#include <stdio.h>
#include <stdlib.h>
#define Maxsize 10 //그래프 정점의 최대 개수

typedef struct HeadNode{ //그래프 리스트
    int v=0; //가지고 있는 정점 개수
    struct Node *link; 
}headtype;

typedef struct Node{
    int vertex;
    struct Node *link;
}nodetype;

void init(headtype *h[]){

    for (int i=0;i<Maxsize;i++){
        h[i]=NULL;
    } 

}
int insertvertex (headtype *h[], int v)
{
    if(v==Maxsize)
        return -1;
    h->v++;

    return 1;
}

int insertedge (headtype *h[],int link1, int link2)
{
    return 1;
}

void dfs (headtype *h[])
{

}

void bfs (headtype *h[])
{

}

void print (headtype *h[])
{

}


int main (void){
    
    headtype *head[Maxsize];
    char command;
    int vertex;
    int u, v; //삽입할 edge 저장

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
			init(head);
			break;
		case 'q': case 'Q':
			break;
		case 'v': case 'V':
			printf("Vertex = ");
			scanf("%d", &vertex);
			insertvertex(head,vertex);
			break;
		case 'e': case 'E':
            printf("2 Edges = ");
			scanf("%d %d", &u,&v);
			insertedge(head, u,v);
			break;

		case 'd': case 'D':
			dfs(head);
			break;
		case 'b': case 'B':
			bfs(head);
			break;

		case 'p': case 'P':
			print(head);
			break;

		default:
			printf("\n       >>>>>        retry        <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;
}
