const int L = 5;                 // max lenght Snake
const int columns = 20;
const char field_symbol = ' ';
const char border_symbol = '*';
const char tail_symbol = '#';
const char head_symbol = '@';

enum DIRECTION {
	RIGHT, 
	LEFT,
	UP,
	DOWN
};

enum KEYS {
	RIGHT_ARROW = 77,
	LEFT_ARROW = 75,
	UP_ARROW = 72,
	DOWN_ARROW = 80,
	ESC = 27
};


