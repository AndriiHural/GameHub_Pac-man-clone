#ifndef __LEVELMAPS_H__
#define __LEVELMAPS_H__
#define n_row 21 // size row libirinte
#define n_col 22 //size colom libirinte


class LevelMaps
{
protected:
	/*An array describes a map of movements*/
	int level_1[n_row][n_col] = {
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,1,2,1,1,2,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0 },
		{ 0,1,0,0,0,0,0,0,1,0,0,0,0,1,0,0,1,1,1,1,1,0 },
		{ 0,1,1,1,1,0,1,1,1,1,1,0,0,1,0,0,0,1,0,0,1,0 },
		{ 0,0,1,0,1,0,2,0,0,0,1,0,0,1,0,0,0,1,1,0,1,0 },
		{ 0,1,1,0,1,1,1,0,0,0,1,2,1,1,1,1,0,0,1,1,1,0 },
		{ 0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,1,0 },
		{ 0,1,2,1,1,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,1,0 },
		{ 0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,0,1,0,0,1,0 },
		{ 0,0,0,0,0,0,1,1,0,1,0,1,1,1,1,1,1,1,0,0,1,0 },
		{ 1,1,1,1,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,1,0 },
		{ 0,0,0,1,0,0,0,1,1,1,0,0,0,0,0,0,1,1,1,1,1,0 },
		{ 0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1,0 },
		{ 0,1,1,2,1,0,0,1,1,1,1,1,1,1,0,0,1,0,0,0,1,0 },
		{ 0,1,0,0,1,0,0,0,1,0,0,0,0,1,1,1,1,1,1,0,1,0 },
		{ 0,1,1,0,1,1,1,1,1,0,0,0,0,1,0,0,0,0,1,1,1,0 },
		{ 0,0,1,0,1,0,1,0,0,0,0,1,1,1,0,0,0,0,1,0,0,0 },//5
		{ 0,1,1,1,1,0,1,1,1,0,0,1,0,0,0,0,0,1,1,0,0,0 },//6
		{ 0,1,0,0,0,0,0,0,1,0,0,1,1,1,1,1,0,1,0,0,0,0 },//7
		{ 0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,0,0,0,0 },//8
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }//9
	};

	int level_2[n_row][n_col] = {
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,1,1,2,1,1,1,2,1,2,1, 0,1,1,1,2,1,1,2,1,2,0 },
		{ 0,1,0,0,0,2,0,0,0,0,1, 0,1,0,0,0,2,0,0,0,1,0 },
		{ 0,1,0,0,0,1,0,0,0,0,1, 0,2,0,0,0,1,0,0,0,1,0 },
		{ 0,1,2,1,2,1,1,1,2,1,1, 1,2,1,2,1,1,1,2,1,1,0 },
		{ 0,1,0,0,0,1,0,1,0,0,0, 0,0,0,1,0,1,0,0,0,1,0 },
		{ 0,1,1,2,1,1,0,1,2,1,2, 0,1,2,1,0,1,1,1,2,1,0 },
		{ 0,1,1,1,1,1,0,0,0,0,1, 0,2,0,0,0,1,0,0,0,0,0 },
		{ 0,0,0,0,0,1,0,0,0,1,1, 1,0,0,0,1,1,1,0,0,0,0 },
		{ 0,0,0,0,0,1,0,0,0,1,0, 1,2,1,2,1,1,1,0,0,1,0 },
		{ 0,1,1,1,2,1,0,0,0,1,0, 0,0,0,2,0,1,0,0,0,1,0 },
		{ 0,0,0,1,0,2,0,1,1,2,1, 1,1,1,2,0,1,1,1,1,1,0 },
		{ 0,0,0,1,0,1,0,1,0,0,0, 0,0,0,0,0,1,0,0,0,1,0 },
		{ 0,1,2,1,1,2,0,1,1,1,1, 1,1,1,0,0,1,0,1,0,1,0 },
		{ 0,1,0,0,0,2,0,0,1,0,0, 0,0,1,1,1,1,1,1,0,1,0 },
		{ 0,2,0,0,0,1,0,0,1,0,0, 0,0,1,0,0,0,0,1,0,1,0 },
		{ 0,1,1,1,1,2,1,2,1,2,1, 1,1,1,2,2,2,1,1,1,2,0 },//5
		{ 0,1,0,0,0,0,0,1,0,0,0, 1,0,0,0,0,0,1,1,0,2,0 },//6
		{ 0,2,0,1,1,0,0,2,2,1,2, 1,1,1,1,1,0,1,0,0,1,0 },//7
		{ 0,1,1,0,1,2,1,1,0,0,0, 0,0,0,0,1,1,1,2,1,2,0 },//8
		{ 0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0 }//9
														//22  1 2 3 4 5 6 7 8 910 11 
	};
public:
	LevelMaps::LevelMaps();
	LevelMaps::~LevelMaps();
};

#endif 