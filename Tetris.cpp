#include <iostream>
#include "Tetris.h"
#include "InfoPane.h"
#include "HelpPane.h"
#include "NextPane.h"
#include "BoardPane.h"
#include "StatPane.h"
#include "Block.h"
#include <unistd.h>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

Tetris::Tetris(){
  initscr();
  keypad(stdscr, TRUE);
	noecho();
	curs_set(0);
  start_color();
  cbreak();
  refresh();
  infoPane_ = new InfoPane(1,1,25,5);
  helpPane_ = new HelpPane(1,6,25,12);
  nextPane_ = new NextPane(1,18,25,5);
  boardPane_ = new BoardPane(30,0,22,22);
  statPane_ = new StatPane(60,3,20,20);
}

Tetris::~Tetris(){
  delete infoPane_;
  delete helpPane_;
  delete nextPane_;
  delete boardPane_;
  delete statPane_;
  endwin();
}

void Tetris::setname(char name[]){
  infoPane_->set_name(name);
}

void Tetris::play(){
  int input;
  updateScreen();
  while(!(boardPane_->IsGameOver)){
    input = getch();

    if(input == 'q')  break;
    boardPane_ -> BlockMove(input);

    updateScreen();
  }
}

void Tetris::playFile(char* filename){
  ifstream instream("input.txt");
  char name[20];
  instream >> name;
  setname(name);

  int seed;
  instream >> seed;
  srand(seed);
	char key;

	updateScreen();
	while(!(boardPane_->IsGameOver)){
    sleep(1);
		instream >> key;
    boardPane_->BlockMove(key);
		updateScreen();
	}
}

void Tetris::updateScreen(){
  infoPane_->draw();
  helpPane_->draw();
  nextPane_->draw();
  boardPane_->draw();
  statPane_->draw();
  statPane_->score_draw(boardPane_);
}
