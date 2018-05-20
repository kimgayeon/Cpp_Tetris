#include <ncurses.h>
#include <iostream>
#include <fstream>
#include <cstdlib>

#include "Tetris.h"
#include "Pane.h"
#include "InfoPane.h"
#include "HelpPane.h"
#include "NextPane.h"
#include "BoardPane.h"
#include "StatPane.h"
#include "Block.h"

using namespace std;

int main(int argc, char* argv[]){
	if(argc > 1){                      //input 파일 입력
		Tetris t;
		t.playFile(argv[1]);
	}
	else {                                //키보드 입력
		cout << "테트리스 게임을 시작합니다." << endl;
		cout << "사용자의 이름을 입력하세요." << endl;
		cout << "이름: ";
		char name[20];
		cin >> name;
		cout << name;

		int seed = time(NULL);
	  srand(seed);
		
		Tetris t;
		t.setname(name);
		t.play();
	}

	return 0;
}
