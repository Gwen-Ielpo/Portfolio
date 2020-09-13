#include "wobowall_e.h"
//#include "board_display.h"
#include <time.h>
#include <pthread.h>
#include <unistd.h>

#include "board_display.h"

#include <stdio.h>
#include <stdlib.h>

void show( RRRobot* r1, RRRobot* r2)
{

    RRRobot* robot = r1;
    RRRobot* prev_robot = r2;

    RRBoard board ;

    rr_board_init(&board, "board.txt") ;

    if(!board.tile_size)
    {
        printf("the board has no tiles\n") ;
        rr_board_destroy(&board) ;
        return ;
    }

    rr_board_show(&board, "roborally.svg", robot, prev_robot) ;

    rr_board_destroy(&board) ;

    return;
}


typedef struct{
    RRRobot * robot, *prev_robot;
}magic_box;

void robot_cpy(const RRRobot* from, RRRobot* to)
{
  memcpy(to, from, sizeof(RRRobot)) ;
}

void move_print(
        RRRobotMove move
)
{
  static const char* translations[8] =
          {
                  "moving forward 1 tile",
                  "moving forward 2 tiles",
                  "moving forward 3 tiles",
                  "moving backward 1 tile",
                  "rotating left",
                  "rotating right",
                  "u turning",
                  "not moving"
          } ;
  printf("%s\n", translations[move]) ;
}

void robot_print(const RRRobot* robot)
{
  static const char* translations[5] =
          {
                  "east",
                  "north",
                  "west",
                  "south",
                  "dead"
          } ;

  printf(
          "robot is at (%d, %d) looking %s\n",
          robot->line,
          robot->column,
          translations[robot->status]
  ) ;
}

int main (int argc, char **argv)
{
    clock_t t1, t2;

    t1 = clock();
  RRBoard board ;

  rr_board_init(&board, "board.txt") ;

  if(!board.tile_size) {
    printf("the board has no tile\n") ;
    return 0 ;
  }

  RRRobot robot ;
  robot.line = board.tiles[0].line ;
  robot.column = board.tiles[0].column ;
  robot.status = RR_ROBOT_S ;

  RRRobot prev_robot ;
  robot_cpy(&robot, &prev_robot) ;

  pthread_t th;
  magic_box box;
  box.prev_robot = &prev_robot;
  box.robot = &robot;
  pthread_create (&th, NULL, show, & box);


  nod** Tab = malloc(sizeof(nod*)*50000);
  nod * D = initNod(&robot);
  initGraph(D, &board, Tab);
  robot_print(D->data);
  nod * goal = findNode(5, 9, RR_ROBOT_S);

    //byDijkstra(D, goal, getTab(), getId());
   reverseDijkstra(goal, getTab(), getId());
    RRRobotMove* path =dontStopTillGetEnough(D, goal, &board);
  freeGraph();
  free(Tab);
  //free(moves);
  freeNode(D);
  rr_board_destroy(&board) ;

    t2 = clock();

    float diff = ((float)(t2 - t1) / 1000000.0F ) * 1000;
    printf("The fonction took %f ms to resolve this puzzle\n", diff);

    for(int i = 1 ; i < path[0]; ++i) {
        robot_print(&robot);
        rr_board_play(&board, &robot, path[i]);
        sleep(1);
    }

    pthread_join(th, NULL);

    rr_board_destroy(&board) ;

  return 0 ;
}