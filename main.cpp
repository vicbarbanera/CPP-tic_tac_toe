#include <iostream>

using std::string;

void printStructure();
void assignPosition();
bool winValidation();

char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row{}, column{};
char token{'X'}; // sempre que a variavel for tipo char, usar aspas simples
bool tie{false};
string p1{}, p2{};

int main() {

  std::cout << "Please enter the name of the first player: ";
  getline(std::cin, p1);

  std::cout << "\nPlease enter the name of the second player: ";
  getline(std::cin, p2);

  // will keep on iterating till functionThree() is returning false
  while (!winValidation()) {
    printStructure();
    assignPosition();
    winValidation();
  }

  if (token == 'X' && tie == false) {
    std::cout << p2 << " wins!" << std::endl;
  }

  else if (token == '0' && tie == false) {
    std::cout << p1 << " wins!" << std::endl;
  }

  else {
    std::cout << "It is a draw!" << std::endl;
  }

  return 0;
}

void printStructure() {

  std::cout << "    |    |    \n";
  std::cout << "  " << space[0][0] << " |  " << space[0][1] << " |  "
            << space[0][2] << " \n";
  std::cout << "____|____|____\n";
  std::cout << "    |    |    \n";
  std::cout << "  " << space[1][0] << " |  " << space[1][1] << " |  "
            << space[1][2] << " \n";
  std::cout << "____|____|____\n";
  std::cout << "    |    |    \n";
  std::cout << "  " << space[2][0] << " |  " << space[2][1] << " |  "
            << space[2][2] << " \n";
  std::cout << "    |    |    \n";
}

void assignPosition() {

  int digit{};

  if (token == 'X') {
    std::cout << p1 << ", please enter an option: "; // p1 e' o player 1
    std::cin >> digit;
  }

  if (token == '0') {
    std::cout << p2 << ", please enter an option: "; // p2 e' o player 2
    std::cin >> digit;
  }

  if (digit == 1) {
    row = 0;
    column = 0;
  }

  if (digit == 2) {
    row = 0;
    column = 1;
  }

  if (digit == 3) {
    row = 0;
    column = 2;
  }

  if (digit == 4) {
    row = 1;
    column = 0;
  }

  if (digit == 5) {
    row = 1;
    column = 1;
  }

  if (digit == 6) {
    row = 1;
    column = 2;
  }

  if (digit == 7) {
    row = 2;
    column = 0;
  }

  if (digit == 8) {
    row = 2;
    column = 1;
  }

  if (digit == 9) {
    row = 2;
    column = 2;
  }

  else if (digit < 1 || digit > 9) {
    std::cout << "Invalid!\n";
  }

  if (token == 'X' && space[row][column] != 'X' && space[row][column] != '0') {
    space[row][column] = 'X';
    token = '0';
  }

  else if (token == '0' && space[row][column] != '0' &&
           space[row][column] != 'X') {
    space[row][column] = '0';
    token = 'X';
  }

  else {
    std::cout << "There is no empty space.\n";
    assignPosition();
  }
}

bool winValidation() {

  for (int i{0}; i < 3; i++) {
    if (space[i][0] == space[i][1] && space[i][0] == space[i][2] ||
        space[0][i] == space[1][i] && space[0][i] == space[2][i]) {
      return true;
    }
  }

  if (space[0][0] == space[1][1] && space[1][1] == space[2][2] ||
      space[0][2] == space[1][1] && space[1][1] == space[2][0]) {
    return true;
  }

  for (int i{0}; i < 3; i++) {
    for (int j{0}; j < 3; j++) {
      if (space[i][j] != 'X' && space[i][j] != '0') {
        return false;
      }
    }
  }
  tie = true;
  return false;
}
