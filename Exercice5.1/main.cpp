#include <iostream>
#include <time.h>

enum class GameState {
	INIT,
	PLAY,
	END,
	EXIT
};

void FindMysteryNumber(int mysteryNumber, int& turnNumber, GameState& gameState) {
	int solution = 0;

	while (solution != mysteryNumber) {
		turnNumber++;
		std::cout << "Try finding the mystery number :\n";
		std::cin >> solution;


	}
	gameState = GameState::END;
}


void GenerateMysteryNumber(int& mysteryNumber) {

	srand(time(NULL));
	mysteryNumber = rand() % 101;


}

int main() {
	GameState gameState = GameState::INIT;

	int mysteryNumber = 0;
	int turnNumber = 0;
	do

	{
		switch (gameState) {
		case GameState::INIT:

			GenerateMysteryNumber(mysteryNumber);
			std::cout << mysteryNumber << "\n";


			gameState = GameState::PLAY;
			break;

		case GameState::PLAY:


			FindMysteryNumber(mysteryNumber, turnNumber, gameState);

			break;

		case GameState::END:


			std::cout << "number of turns to find the mystery number :" << turnNumber << "\n";
			std::cout << "mystery number was : " << mysteryNumber << "\n";
			gameState = GameState::EXIT;

			break;

		case GameState::EXIT:
			break;
		}
	}

	while (gameState != GameState::EXIT);
	system("pause");
	return EXIT_SUCCESS;
}
