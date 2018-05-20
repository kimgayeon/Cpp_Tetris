#include <ncurses.h>
#include "Pane.h"
#include "BoardPane.h"

#ifndef __STATPANE_H__
#define __STATPANE_H__
class StatPane: public Pane{
public:
  StatPane(int x, int y, int w, int h);
  void draw();
  void score_draw(BoardPane *b);
};
#endif
