#include "board_display.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{

  RRRobot* robot;// = r1;
  RRRobot* prev_robot;// = r2;
  if(argc < 2)
  {
    printf("usage : %s <board filename>\n", argv[0]) ;
    return 1 ;
  }

  RRBoard board ;

  rr_board_init(&board, argv[1]) ;

  if(!board.tile_size)
  {
    printf("the board has no tiles\n") ;
    rr_board_destroy(&board) ;
    return 0 ;
  }

  rr_board_show(&board, "roborally.svg", robot, prev_robot) ;

  rr_board_destroy(&board) ;

  return 0 ;
}
