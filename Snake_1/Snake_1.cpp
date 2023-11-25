//Задание 1

#include <iostream>
#include <conio.h>


int Drawing(int codeKey) {
	char headSnake = '@';
	std::cout << headSnake << std::endl;
	return 0;
}


void cliMessage(int code) {
	switch (code) {
	case 0:
		std::cout << "Welcom to the Snake game!" << std::endl;
		break;
	case 1:
		std::cout << "Wrong press!" << std::endl;
		break;
	default:
		std::cout << "Good bye!" << std::endl;
		break;
	}
}


int InputKey() {

	enum Controller {
		RIGHT = 77,
		LEFT = 75,
		UP = 72,
		DOWN = 80,
		EXIT = 27
	};

	unsigned int codeKey = -1;

	do {
		codeKey = _getch();

		if (codeKey == 224) {
			codeKey = _getch();
		}

		switch (codeKey) {
		case RIGHT:
			Drawing(RIGHT);
			break;
		case LEFT:
			Drawing(LEFT);
			break;
		case UP:
			Drawing(UP);
			break;
		case DOWN:
			Drawing(DOWN);
			break;
		case EXIT:
			cliMessage(EXIT);
			break;
		default:
			cliMessage(1);
			break;
		}
	} while (codeKey != EXIT);
	return 0;
}


int main() {
	cliMessage(0);
	InputKey();

	return 0;
}
