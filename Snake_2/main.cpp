#include <iostream>
#include <conio.h>
#include <windows.h>
#include "const.h"
#include "game.h"
#include "snake.h"


int main() {
	snake_size = 4;
	int tail_size = snake_size - 1;
	int currentPosition = 0;

	while (true) {
		system("cls");

		for (int x = 0; x < columns; x++) {

			if (((x + tail_size) >= currentPosition) && (x < currentPosition)) {
				std::cout << tail_symbol;
			}

            else if (x == currentPosition) {
				std::cout << head_symbol;
            }
            else {
                std::cout << " ";
            }
		}
        currentPosition++;
	}
	
	return 0;
}