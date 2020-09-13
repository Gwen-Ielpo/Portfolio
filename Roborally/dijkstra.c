//
// Created by enzo on 09/03/16.
    //
 //
#include <unistd.h>                                 //
#include "dijkstra.h"                               //
#include "board.h"
/*
*** stack smashing detected ***: ./example terminated
Aborted

 */
FILE* fdp;
dyntab * heap;                                                    //
int nb_nodes;                                       //
nod**** dijkstra;                                     //	this array will contain every nodes of the graph
nod * goal;                                         //
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
static void robot_print(const RRRobot* robot)       //
{                                                   //
    static const char* translations[5] =            //
            {                                       //
                    "east",                         //
                    "north",                        //
                    "west",                         //
                    "south",                        //
                    "dead"                          //
            } ;                                     //
    printf(                                         //
            "robot is at (%d, %d) looking %s\n",    //
            robot->line,                            //
            robot->column,                          //
            translations[robot->status]             //
    ) ;                                             //
    /*char str[35];
    str[0] = '\0';
    strcat(str, "robot is at (\0");
    char tmp = robot->line + '0';
    str[strlen(str)] = tmp;
    str[strlen(str)] = '\0';
    strcat(str, ", \0");
    tmp = robot->column + '0';
    str[strlen(str)] = tmp;
    str[strlen(str)] = '\0';
    strcat(str, ") looking \0");
    strcat(str, translations[robot->status]);
    strcat(str, "\n\0");
    fwrite(str , 1 , strlen(str) , fdp);*/
}                                                   //

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
RRRobotMove*										//
byDijkstra(nod* N, nod* D, nod ** Tab, int nb){     //	this function will calculate the shortest path in a graph
    nb_nodes = nb;                                  //	N is the start point of the graph and D is the goal     //
    dijkstra = Tab;                                 //
    goal = D;                                       //
    heap = initHeap(compareNodes, sizeof(nod**));
    for(int i = 0 ;  i < 100 ; ++i)
        for(int j = 0 ;  j < 100 ; ++j)
            for(RRRobotStatus k = RR_ROBOT_E ;  k <= RR_ROBOT_DEAD ; ++k) {
                if(Tab[i + j * LINE + k*LINE*COL] != NULL) {
                    Tab[i + j * LINE + k*LINE*COL]->goaldist = INT_MAX;
                    Tab[i + j * LINE + k*LINE*COL]->end = 0;
                    Tab[i + j * LINE + k*LINE*COL]->visited = 0;
                }
            }								        //	examine I'll set it to 1
    push(&N, heap);                                        //  I add the starting point in the reachable array
    close(fdp);
    N->dist = 0;                                    //	the starting node is at 0 distance from itself
    nod * bestNodes;
    while(!goal->visited) {                          //	i'll run the program till every nodes will be visitedr
        bestNodes = *(nod**)pop( heap);
        updateNeibs(bestNodes);                     //	updateNeibs update the distance from a node to an other + the distance
    }
    puts("finish");
    RRRobotMove* Path                               //	i'll return an array which contain the shortest path of the graph nodes by nodes + 1 an end nodes
            = malloc(sizeof(RRRobotMove )* (D->dist + 2));
    nod * flag = D;							        //	this array will be as long as the distance between the beginning and the goal
    int j = D->dist + 1;                            //
    while(flag != NULL){                                             //	in this loop I add every move I have made from the begining till the end
        Path[j] = flag->move;                       //
        robot_print(flag->data);
        flag = flag->prev;				        	//
        printf("%d \n", j);
        -- j;                                       //
    }			//
    Path[0] = D->dist + 2;				            //  little trick : in the first case I indicate the array's size
    freeHeap(heap);
    return Path;							        //	and then we return the array
}											        //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void reverseDijkstra(nod* goal, nod ** Tab, int nb){
    nb_nodes = nb;
    dijkstra = Tab;
    fdp = fopen("robot", "w");
    for(int i = 0 ;  i < 100 ; ++i)
        for(int j = 0 ;  j < 100 ; ++j)
            for(RRRobotStatus k = RR_ROBOT_E ;  k <= RR_ROBOT_DEAD ; ++k) {
                if(Tab[i + j * LINE + k*LINE*COL] != NULL) {
                    Tab[i + j * LINE + k*LINE*COL]->goaldist = INT_MAX;
                    Tab[i + j * LINE + k*LINE*COL]->end = 0;
                    Tab[i + j * LINE + k*LINE*COL]->visited = 0;
                }
            }
    heap = initHeap(compareNodes, sizeof(nod**));
    push(&goal, heap);

    goal->goaldist = 0;
    nod * bestNodes;
    while(nb_nodes != 0){                         //	i'll run the program till every nodes will be visited
        bestNodes = *(nod**)pop( heap);
      //  printf("%p, %p \n",inTab(bestNodes->data, Tab, nb), bestNodes);;
        updateParents(bestNodes);
    }
    puts("finish");
    freeHeap(heap);
}
void 								        		//
updateGoalDist(nod* N1, nod* N2){		        	    //
    N2->goaldist = N1->goaldist + 1;		        		///
}
void
updateParents(nod * N){
    -- nb_nodes;
    nod * P;
    for(int i = 0 ; i < N->parent->size ; ++i) {    //
        P = *(nod**)dyntab_return(N->parent, i, sizeof(nod*));
        if (P != NULL                      //
            && N->data->status != RR_ROBOT_DEAD) {
            if (P->goaldist > N->goaldist + 1)     //	if the new path is shorter than the previous one
                updateGoalDist(N, P);
            if (P->visited == 0)         //
                push(&P, heap);                   //
        }                                           //
    }                                               //	I'll set the distance of his neighbour to his distance +1
    N->visited = 1;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void 										        //
updateNeibs(nod* N){                                //
    -- nb_nodes;                                    //
    for(int i = 0 ; i < 7 ; ++i) {                  //
        if (N->neib[i] != NULL                      //
            && N->data->status != RR_ROBOT_DEAD) {  //	for every neighbour's node ...
            if (N->neib[i]->dist > N->dist + 1)     //	if the new path is shorter than the previous one
                updateDist(N, N->neib[i]);          //
            if (N->neib[i]->visited == 0) {         //
                push(&(N->neib[i]), heap);                //
                N->neib[i]->move = i;               //  i will give the RRRobotMove
            }                                       //
        }                                           //
    }                                               //	I'll set the distance of his neighbour to his distance +1
    N->visited = 1;
}								        			//
//
void 								        		//
updateDist(nod* N1, nod* N2){		        	    //
    N2->dist = N1->dist + 1;		        		//
    N2->prev = N1;					        		//
}									        		//

int compareNodes(nod** N1, nod** N2){
    if((*N1)->dist < (*N2)->dist)
        return 1;
    return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////



