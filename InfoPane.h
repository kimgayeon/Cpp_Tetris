#include <ncurses.h>
#include "Pane.h"
#ifndef __INFOPANE_H__
#define __INFOPANE_H__

class InfoPane:public Pane{
public:
  char name[20];

  void set_name(char name[]);
  InfoPane(int x, int y, int w, int h);
  void draw();
};
#endif
