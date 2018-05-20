#include "Pane.h"
#include "InfoPane.h"
#include "HelpPane.h"
#include "NextPane.h"
#include "BoardPane.h"
#include "StatPane.h"
#include "Block.h"

#ifndef __TETRIS_H__
#define __TETRIS_H__
class Tetris{
    Pane *helpPane_, *nextPane_;
    BoardPane *boardPane_;
    StatPane *statPane_;
    InfoPane *infoPane_;
public:
	Tetris();
	~Tetris();

  void setname(char name[]);
	void play();
  void playFile(char* filename);
	void updateScreen();
};
#endif
