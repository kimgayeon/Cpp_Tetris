#include "Block.h"

Block::Block(){
  for(int i=0; i<SHAPE_SIZE; i++){
    for(int j=0; j<SHAPE_SIZE; j++){
      shape[i][j] = 0;
    }
  }
}

void Block::Block_init(){ //블록 0으로 초기화
  for(int i=0; i<SHAPE_SIZE; i++){
    for(int j=0; j<SHAPE_SIZE; j++){
      shape[i][j] = 0;
    }
  }
}

void Block::set_block(int x, int y, int value){ //블록 value로 초기화
  if(x<0|| y<0 || x>=SHAPE_SIZE || y>=SHAPE_SIZE) return;

  shape[x][y] = value;
}

int Block::get_shape(const int x, const int y){ //블록 재설정
  if(x<0 || y<0 || x>=SHAPE_SIZE || y>=SHAPE_SIZE);
  return shape[x][y];
}

O_Block::O_Block():Block(){
  Block_init();
  set_block(0,0,1);
  set_block(0,1,1);
  set_block(1,0,1);
  set_block(1,1,1);
}

L_Block::L_Block():Block(){
  Block_init();
  set_block(0,1,2);
  set_block(1,1,2);
  set_block(2,1,2);
  set_block(2,2,2);
}

void L_Block::rotate_block(int x, int y, int rotate_num){
  if(rotate_num%4==0){
    Block_init();
		set_block(0,1,2);
		set_block(1,1,2);
		set_block(2,1,2);
		set_block(2,2,2);
  }
  else if(rotate_num%4==1){
    Block_init();
		set_block(0,2,2);
		set_block(1,0,2);
		set_block(1,1,2);
		set_block(1,2,2);
  }
  else if(rotate_num%4==2){
    Block_init();
		set_block(0,0,2);
		set_block(0,1,2);
		set_block(1,1,2);
		set_block(2,1,2);
  }
  else if(rotate_num%4==3){
    Block_init();
		set_block(2,0,2);
		set_block(1,0,2);
		set_block(1,1,2);
		set_block(1,2,2);
  }
}

J_Block::J_Block():Block(){
  Block_init();
  set_block(0,1,3);
  set_block(1,1,3);
  set_block(2,0,3);
  set_block(2,1,3);
}

void J_Block::rotate_block(int x, int y, int rotate_num){
  if(rotate_num%4==0){
    Block_init();
    set_block(0,1,3);
    set_block(1,1,3);
    set_block(2,0,3);
    set_block(2,1,3);
  }
  else if(rotate_num%4==1){
    Block_init();
		set_block(1,0,3);
		set_block(1,1,3);
		set_block(1,2,3);
		set_block(2,2,3);
  }
  else if(rotate_num%4==2){
    Block_init();
		set_block(0,1,3);
		set_block(0,2,3);
		set_block(1,1,3);
		set_block(2,1,3);
  }
  else if(rotate_num%4==3){
    Block_init();
		set_block(0,0,3);
		set_block(1,0,3);
		set_block(1,1,3);
		set_block(1,2,3);
  }
}

S_Block::S_Block():Block(){
  Block_init();
  set_block(0,1,4);
  set_block(1,1,4);
  set_block(1,2,4);
  set_block(2,2,4);
}

void S_Block::rotate_block(int x, int y, int rotate_num){
  if(rotate_num%4==0){
    Block_init();
    set_block(0,1,4);
    set_block(1,1,4);
    set_block(1,2,4);
    set_block(2,2,4);
  }
  else if(rotate_num%4==1){
    Block_init();
    set_block(0,1,4);
    set_block(0,2,4);
    set_block(1,0,4);
    set_block(1,1,4);
  }
  else if(rotate_num%4==2){
    Block_init();
    set_block(0,1,4);
    set_block(1,1,4);
    set_block(1,2,4);
    set_block(2,2,4);
  }
  else if(rotate_num%4==3){
    Block_init();
    set_block(0,1,4);
    set_block(0,2,4);
    set_block(1,0,4);
    set_block(1,1,4);
  }
}

Z_Block::Z_Block():Block(){
  Block_init();
  set_block(0,1,5);
  set_block(1,0,5);
  set_block(1,1,5);
  set_block(2,0,5);
}

void Z_Block::rotate_block(int x, int y, int rotate_num){
  if(rotate_num%4==0){
    Block_init();
    set_block(0,1,5);
    set_block(1,0,5);
    set_block(1,1,5);
    set_block(2,0,5);
  }
  else if(rotate_num%4==1){
    Block_init();
    set_block(0,0,5);
    set_block(0,1,5);
    set_block(1,1,5);
    set_block(1,2,5);
  }
  else if(rotate_num%4==2){
    Block_init();
    set_block(0,1,5);
    set_block(1,0,5);
    set_block(1,1,5);
    set_block(2,0,5);
  }
  else if(rotate_num%4==3){
    Block_init();
    set_block(0,0,5);
    set_block(0,1,5);
    set_block(1,1,5);
    set_block(1,2,5);
  }
}

T_Block::T_Block():Block(){
  Block_init();
  set_block(0,1,6);
  set_block(1,0,6);
  set_block(1,1,6);
  set_block(1,2,6);
}


void T_Block::rotate_block(int x, int y, int rotate_num){
  if(rotate_num%4==0){
    Block_init();
    set_block(0,1,6);
		set_block(1,0,6);
		set_block(1,1,6);
		set_block(1,2,6);
  }
  else if(rotate_num%4==1){
    Block_init();
    set_block(0,1,6);
		set_block(1,0,6);
		set_block(1,1,6);
		set_block(2,1,6);
  }
  else if(rotate_num%4==2){
    Block_init();
    set_block(2,1,6);
    set_block(1,0,6);
    set_block(1,1,6);
    set_block(1,2,6);
  }
  else if(rotate_num%4==3){
    Block_init();
    set_block(0,1,6);
		set_block(1,1,6);
		set_block(1,2,6);
		set_block(2,1,6);
  }
}

I_Block::I_Block():Block(){
  Block_init();
  set_block(0,1,7);
	set_block(1,1,7);
	set_block(2,1,7);
	set_block(3,1,7);
}

void I_Block::rotate_block(int x, int y, int rotate_num){
  if(rotate_num%4==0){
    Block_init();
    set_block(0,1,7);
		set_block(1,1,7);
		set_block(2,1,7);
		set_block(3,1,7);
  }
  else if(rotate_num%4==1){
    Block_init();
    set_block(1,0,7);
		set_block(1,1,7);
		set_block(1,2,7);
		set_block(1,3,7);
  }
  else if(rotate_num%4==2){
    Block_init();
    set_block(0,1,7);
		set_block(1,1,7);
		set_block(2,1,7);
		set_block(3,1,7);
  }
  else if(rotate_num%4==3){
    Block_init();
    set_block(1,0,7);
		set_block(1,1,7);
		set_block(1,2,7);
		set_block(1,3,7);
  }
}
