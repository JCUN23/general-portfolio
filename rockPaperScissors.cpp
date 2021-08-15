#include <iostream>
#include <cmath>
using namespace std;
#include <cstdlib>
#include <ctime>

int main () 
{
cout << "Rock, Paper, or Scissors: \n";
string answer;
cin >> answer;

while (answer != "Rock" & answer != "Paper" & answer != "Scissors") {
    cout << "That's not one of the options, try again.\n";
    cout << "Rock, Paper, or Scissors: \n";
    string answer;
    cin >> answer;
}
int compChoice;
srand(time(NULL));
compChoice = rand() % 3 + 1;

while ((answer == "Rock" & compChoice == 1) | (answer == "Paper" & compChoice == 2) | (answer == "Scissors" & compChoice == 3)) {
    cout << "Tie, play again.\n";
    return 0;
}
if (answer == "Rock" & compChoice == 2) {
    cout << "Computer chooses Paper, you lose.\n";
}
else if (answer == "Paper" & compChoice == 3) {
    cout << "Computer chooses Scissors, you lose.\n";
}
else if (answer == "Scissors" & compChoice == 1) {
    cout << "Computer chooses Rock, you lose.\n";
}
else if (answer == "Rock" & compChoice == 3) {
    cout << "Computer chooses Scissors, you win.\n";
}
else if (answer == "Paper" & compChoice == 1) {
    cout << "Computer chooses Rock, you win.\n";
}
else if (answer == "Scissors" & compChoice == 2) {
    cout << "Computer chooses Paper, you win.\n";
}
}
