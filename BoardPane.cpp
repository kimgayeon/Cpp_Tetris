#include "BoardPane.h"
#include "Block.h"
#include <cstdlib>
#include <ctime>

BoardPane::BoardPane(int x, int y, int w, int h): Pane(x,y,w,h){

  IsGameOver = false;
  currentx = 1;
  currenty = 4;
  wall = 100;
  score = 0;
  randnum = rand()%7;
  rotate_num = 0;

  block_arr[0] = new O_Block();
  block_arr[1] = new L_Block();
  block_arr[2] = new J_Block();
  block_arr[3] = new S_Block();
  block_arr[4] = new Z_Block();
  block_arr[5] = new T_Block();
  block_arr[6] = new I_Block();


  for(int i=0; i<BLOCK_ROW; i++){ //checkboard 0으로 초기화, 벽설정
    for(int j=0; j<BLOCK_COL; j++){
      checkboard[i][j] = 0;
      if(i == BLOCK_ROW-1 || j==-1 || j == BLOCK_COL){
        checkboard[i][j] = wall;
      }
    }
  }
}

int BoardPane::get_score(){return score;}

void BoardPane::BlockMove(int direction){
  if((direction == KEY_RIGHT) || (direction == 'r')){
    if(!isCollision(0,1)) currenty++;
  }
  else if((direction == KEY_LEFT) || (direction == 'l')){
    if(!isCollision(0,-1)) currenty--;
  }
  else if((direction == KEY_DOWN) || (direction == 'g')){
    if(!isCollision(1,0)) currentx++;
  }
  else if((direction == ' ') || (direction == 'd')){
    while(!isCollision(1,0))  currentx++;
  }
  else if((direction == KEY_UP) || (direction == 't')){
    if(!isCollision(0,0)){
      ++rotate_num;
      block_arr[randnum]->rotate_block(currentx,currenty,rotate_num);
      if(isCollision(0,0)){
        rotate_num--;
        block_arr[randnum]->rotate_block(currentx, currenty,rotate_num);
      }
    }
  }

  if(isCollision(1,0)){
    //고정
    for(int row = 0; row < SHAPE_SIZE; row ++){
      for(int col = 0; col < SHAPE_SIZE; col++){
        if(block_arr[randnum]->get_shape(row, col) != 0)
          checkboard[currentx+row][currenty+col] = block_arr[randnum]->get_shape(row, col);
      }
    }
    for(int j=0; j<10; j++){
      if(checkboard[0][j]!=0){
        draw();
        IsGameOver = true;
        return;
      }
    }
    currentx = 1;
    currenty = 4;
    randnum = rand()%7;
		rotate_num = 0;
		if (isCollision(1,0))
		{
			draw();
      IsGameOver = true;
			return;
		}
  }

  int count;
  int lineNumber = 0;
  while(lineNumber<21){
    count=0;
    for(int j=0; j<10; j++){
      if(checkboard[lineNumber][j]){
        count++;
      }
    }
    if(count==10){
      deleteLine(lineNumber);
      continue;
    }
    lineNumber++;
  }
}

bool BoardPane::isCollision(int row, int col){
  for(int iter_row = 0; iter_row < SHAPE_SIZE; iter_row++){
    for(int iter_col = 0; iter_col < SHAPE_SIZE; iter_col++){
      if(block_arr[randnum]->get_shape(iter_row,iter_col)!=0 && (currentx+row+iter_row<0 || currentx+row+iter_row>BLOCK_ROW-2 || currenty+col+iter_col<0 || currenty+col+iter_col>=BLOCK_COL-2 || checkboard[currentx+row+iter_row][currenty+col+iter_col] != 0)){
        return true;
      }
    }
  }
  return false;
}

void BoardPane::draw(){
  wrefresh(win_);
  box(win_, 0,0);
  init_pair(5,COLOR_GREEN, COLOR_BLACK); //안의 판
  //init_pair(6,COLOR_BLACK, COLOR_GREEN); //보드판 테두리


  init_pair(10, COLOR_BLACK, COLOR_YELLOW);  //O_Block
  init_pair(11, COLOR_BLACK, COLOR_BLUE);  //L_Block
  init_pair(12, COLOR_BLACK, COLOR_GREEN);  //J_Block
  init_pair(13, COLOR_BLACK, COLOR_MAGENTA);  //S_Block
  init_pair(14, COLOR_BLACK, COLOR_RED);  //Z_Block
  init_pair(15, COLOR_BLACK, COLOR_CYAN);  //T_Block
  init_pair(16, COLOR_BLACK, COLOR_WHITE);  //I-Block
  /*//보드판 테투리 출력
  wattron(win_, COLOR_PAIR(6));
  for(int i=0; i<height_; i++){
    mvwhline(win_, i, 0, ACS_CKBOARD, width_);
  }
  wattroff(win_, COLOR_PAIR(6));
  wrefresh(win_);
  */
  //출력
  for(int i = 1; i<21; i++){
    for(int j = 1; j<11  ; j++){
        if(checkboard[i][j-1] != 0){
          wattron(win_, COLOR_PAIR(checkboard[i][j-1]+9));
          mvwprintw(win_,i,j*2-1,"  ");
          wattroff(win_, COLOR_PAIR(checkboard[i][j-1]+9));
        }

        else{ //안의 판.
          wattron(win_, COLOR_PAIR(5));
          mvwprintw(win_,i,j*2-1,"  ");
          wattroff(win_, COLOR_PAIR(5));
        }

    }
  }
  wrefresh(win_);

  //block출력
  for(int i = 0; i < SHAPE_SIZE; i++)
	{
		for(int j = 0; j <SHAPE_SIZE; j++)
		{
			if(block_arr[randnum]->get_shape(i,j) != 0){
				wattron(win_,COLOR_PAIR(block_arr[randnum]->get_shape(i,j)+9));
				mvwprintw(win_, currentx+i,(currenty+j)*2+1,"  ");
				wattroff(win_,COLOR_PAIR(block_arr[randnum]->get_shape(i,j)+9));
			}
		}
	}
  wrefresh(win_);
}

void BoardPane::deleteLine(int lineNumber){
  score++;
  while(lineNumber>=0){
    for(int j=0; j<10; j++){
      checkboard[lineNumber][j]=checkboard[lineNumber-1][j];
    }
    lineNumber--;
  }
  for(int j=0; j<10; j++){
    checkboard[0][j] = 0;
  }
}
