#include <conio.h>
#include <windows.h>
#include "const.h"
#include "game.h"
#include "snake.h"
#include "field.h"
#include "food.h"


size_t main() {

	st_snake snake(3, RIGHT);
	st_food food;
	st_field field(20, 10);
	st_game game;
	
	game.start(game, snake, field, food);

	return 0;
}
