#include <ncurses.h>

// Maybe use halfdelay to simulate pitches?

char* field_path = "field.map";
/*
char map[58][238] = {
"       __/																 \__       ",
"    __/																    \__	   ",
"___/                                                                                                                                          \___",

};
*/

/* forward declarations */
int initmap(const char *map_path);
void initplayers();

int main() {
	char ch;

	initscr();
	keypad(stdscr, TRUE);				//Enable funtion keys and keypad
	noecho();					//Don't echo input
	printw("Play ball!\n");
	refresh();
	getch();
	
	clear();
	refresh();

	if (initmap(field_path) < 0) {
		printw("Failed to read map file, exiting");
		refresh();
		getch();
		endwin();
		return 0;
	}

	initplayers();

	getch();
	while (ch != 'q') {
		ch = getch();
		//printw("pressed key is %c\n", ch);
		refresh();
	}
	endwin();

	return 0;
}

int initmap(const char *map_path) {
	FILE *mapFile;
	int y = 0;
	char linePtr[238];

	mapFile = fopen(map_path, "r");

	if (mapFile == NULL){
		printw("file open failed");
		refresh();
		getch();
		return -1;
	}

	mapFile = fopen(field_path, "r");
	for (y=0;y<58;y++) {
		fread(linePtr, sizeof(char), 238, mapFile);
		printw(linePtr);
	}
	refresh();	

	return 0;
}

void initplayers() {
	mvaddch(41,118,'P');
	mvaddch(54,118,'C');
	mvaddch(53,116,'B');
	mvaddch(37,142,'1');
	mvaddch(31,131,'2');
	mvaddch(37,94,'3');
	mvaddch(31,105,'S');
	mvaddch(18,75,'L');
	mvaddch(11,119,'M');
	mvaddch(18,161,'R');
}
