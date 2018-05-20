#include "StatPane.h"

StatPane::StatPane(int x, int y, int w, int h):Pane(x,y,w,h){}

void StatPane::draw(){
  init_pair(4, COLOR_RED, COLOR_BLACK);
  wattron(win_, COLOR_PAIR(4));
  box(win_, 0, 0);
  mvwprintw(win_, 0, 5, "STATISTICS");
  mvwprintw(win_, 1, 1, "SCORE: ");
  wattroff(win_, COLOR_PAIR(4));
  wrefresh(win_);
}

void StatPane::score_draw(BoardPane *b){
  wattron(win_, COLOR_PAIR(4));
  mvwprintw(win_, 2, 1, "%d", b->get_score());
  wattroff(win_, COLOR_PAIR(4));
  wrefresh(win_);
}
