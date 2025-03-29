#include <cstdlib>
#include <ios>
#include <iostream>
#include <limits>
#include <optional>
#include <random>
#include <string>
#include <tuple>

void display() {
  std::cout << "Welcome to the Number Gessing Game!\n"
            << "Guess a number between 1 and 100.\n";
}

int generateRandomNumber() {
  static std::random_device rd;
  static std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(1, 100);
  return dis(gen);
}

std::optional<int> getUserInput() {
  int guess;
  if (std::cin >> guess)
    return guess;
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return std::nullopt;
}

void logi(int maxAttempts) {
  int randNum = generateRandomNumber();
  int attempts = 0;

  while (attempts < maxAttempts) {
    std::cout << "Enter your guess: ";
    auto guessOpt = getUserInput();

    if (!guessOpt) {
      std::cout << "Invalid input. Pls enter a valid number.\n";
      continue;
    }
    int guess = *guessOpt;
    attempts++;

    if (guess < randNum) {
      std::cout << "No, you are small\n";
    } else if (guess > randNum) {
      std::cout << "No, you are big\n";
    } else {
      std::cout << "Yeah, you are right:)\n";
      return;
    }
  }
  std::cout << "Loseeeeeee.  " << randNum << std::endl;
}

void chooseMode() {
  constexpr int EASY_ATTEMPTS = 10;
  constexpr int MEDIUM_ATTEMPTS = 5;
  constexpr int DIFFCULT_ATTEMPTS = 3;

  std::cout << "Choose mode: \n"
            << "1. easy 10 times\n"
            << "2. medium 5 times\n"
            << "3. difficult 3 times\n"
            << "\n"
            << ">>>>>> ";
  int input;
  if (!(std::cin >> input)) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Invalid input, pls enter a valid number.\n";
    return;
  }

  switch (input) {
  case 1:
    std::cout << "easy mode\n";
    logi(EASY_ATTEMPTS);
    break;
  case 2:
    std::cout << "medium mode\n";
    logi(MEDIUM_ATTEMPTS);
    break;
  case 3:
    std::cout << "difficult mode\n";
    logi(DIFFCULT_ATTEMPTS);
    break;
  default:
    std::cout << "pls enter 1, 2, or 3.\n";
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
