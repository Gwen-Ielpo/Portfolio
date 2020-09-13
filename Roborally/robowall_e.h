#include "dijkstra.h"

typedef struct{
    int priority;
    RRRobotMove* move;
}card;

RRRobotMove drawCard();

nod* whosNext(nod*, nod*, RRRobotMove**, RRRobotMove*, RRBoard*);

RRRobotMove* dontStopTillGetEnough(nod*, nod*, RRBoard*);