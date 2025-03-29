#include <cstdlib>
#include <iostream>
#include <string>

void display() {
  std::cout << "Welcome to the Number Gessing Game!\n"
            << "Guess a number between 1 and 100.\n";
}

void logi(int randNum, int &attempts, int maxAttempts) {
  int guess;
  std::cout << "Enter your guess: ";
  std::cin >> guess;
  attempts++;

  if (guess < randNum) {
    std::cout << "No, you are small\n";
    if (attempts < maxAttempts) {
      logi(randNum, attempts, maxAttempts);
    } else {
      std::cout << "Loseeeeeee.  " << randNum << std::endl;
    }
  } else if (guess > randNum) {
    std::cout << "No, you are big\n";
    if (attempts < maxAttempts) {
      logi(randNum, attempts, maxAttempts);
    } else {
      std::cout << "Loseeeeeee.  " << randNum << std::endl;
    }
  } else {
    std::cout << "Yeah, you are right:)\n";
  }
}

void easy() {
  std::cout << "easy mode\n";
  srand(static_cast<unsigned int>(time(nullptr)));
  int randNum = rand() % 100 + 1;
  int attempts = 0;
  int maxAttempts = 10;
  logi(randNum, attempts, maxAttempts);
}

void medium() {
  std::cout << "medium mode\n";
  srand(static_cast<unsigned int>(time(nullptr)));
  int randNum = rand() % 100 + 1;
  int attempts = 0;
  int maxAttempts = 5;
  logi(randNum, attempts, maxAttempts);
}

void difficult() {
  std::cout << "difficult mode\n";
  srand(static_cast<unsigned int>(time(nullptr)));
  int randNum = rand() % 100 + 1;
  int attempts = 0;
  int maxAttempts = 3;
  logi(randNum, attempts, maxAttempts);
}

void chooseMode() {
  std::cout << "Choose mode: \n"
            << "1. easy 10 times\n"
            << "2. medium 5 times\n"
            << "3. difficult 3 times\n"
            << "\n"
            << ">>>>>> ";
  int input;
  std::cin >> input;
  if (input == 1) {

    easy();
  } else if (input == 2) {
    medium();
  } else if (input == 3) {
    difficult();
  } else {
    std::cout << "Just 1, 2 or 3\n";
  }
}

int main(int argc, char *argv[]) {
  std::string more;
  display();
  while (more != "q") {
    chooseMode();
    std::cout << "Again?  'q' to quit, any key to continue\n";
    std::cin >> more;
  }
  return 0;
}
