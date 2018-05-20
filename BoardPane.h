#include <ncurses.h>
#include "Pane.h"
#include "Block.h"

#ifndef __BOARDPANE_H__
#define __BOARDPANE_H__

#define BLOCK_ROW 22
#define BLOCK_COL 12

class BoardPane: public Pane{
public:
  int checkboard[BLOCK_ROW][BLOCK_COL];
  int score;
  int randnum;
  int rotate_num;

  int wall;
  int currentx,currenty;
  bool IsGameOver;
  Block* block_arr[7];

  BoardPane(int x, int y, int w, int h);

  void draw();
  int get_score();
  void BlockMove(int direction);
  void deleteLine(int lineNumber);
  bool isCollision(int row, int col);
};
#endif
