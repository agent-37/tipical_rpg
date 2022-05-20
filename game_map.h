#ifndef _GAME_MAP_H_
#define _GAME_MAP_H_
#define  MAX_SIZE_MAP 100
enum cell  {	};

class game_map {
public:
	int** map;
	game_map() {}
	~game_map() {
		delete[] map;
	}
public:
	void generation();
	void set_cell(int, int, int);
};

#endif // _GAME_MAP_H_


