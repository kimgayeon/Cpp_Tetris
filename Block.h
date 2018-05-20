#include <ncurses.h>

#ifndef __BLOCK_H__
#define __BLOCK_H__

const int SHAPE_SIZE = 4;

class Block{
public:
  int shape[SHAPE_SIZE][SHAPE_SIZE];

  Block();
  void Block_init();
  void set_block(int x, int y, int value);
  int get_shape(const int x, const int y);
  virtual void rotate_block(int x, int y, int rotate_num){
    if(x<0 || y<0 || x>=SHAPE_SIZE || y>=SHAPE_SIZE) return;
  }
};

class O_Block : public Block{
public:
  O_Block();
  void rotate_block(int x, int y, int rotate_num){};
};


class L_Block : public Block{
public:
  L_Block();
  void rotate_block(int x, int y, int rotate_num);
};

class J_Block : public Block{
public:
  J_Block();
  void rotate_block(int x, int y, int rotate_num);
};

class S_Block : public Block{
public:
  S_Block();
  void rotate_block(int x, int y, int rotate_num);
};

class Z_Block : public Block{
public:
  Z_Block();
  void rotate_block(int x, int y, int rotate_num);
};

class T_Block : public Block{
public:
  T_Block();
  void rotate_block(int x, int y, int rotate_num);
};

class I_Block: public Block{
public:
  I_Block();
  void rotate_block(int x, int y, int rotate_num);
};
#endif
