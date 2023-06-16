#include <iostream>
using namespace std;

class Image {
public: int image0() {
        cout << " _______" << endl;
        cout << " |     |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << "=========" << endl;
    }
    int image1() {
        cout << " _______" << endl;
        cout << " |     |" << endl;
        cout << " |     O" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << "=========" << endl;
}
int image2() {
    cout << " _______" << endl;
    cout << " |     |" << endl;
    cout << " |     O" << endl;
    cout << " |     |" << endl;
    cout << " |" << endl;
    cout << " |" << endl;
    cout << "=========" << endl;
}
    int image3() {
        cout << " _______" << endl;
        cout << " |     |" << endl;
        cout << " |     O" << endl;
        cout << " |    /|" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << "=========" << endl;
}
int image4() {
    cout << " _______" << endl;
    cout << " |     |" << endl;
    cout << " |     O" << endl;
    cout << " |    /|\\" << endl;
    cout << " |" << endl;
    cout << " |" << endl;
    cout << "=========" << endl;
}
int image5() {
    cout << " _______" << endl;
    cout << " |     |" << endl;
    cout << " |     O" << endl;
    cout << " |    /|\\" << endl;
    cout << " |    /" << endl;
    cout << " |" << endl;
    cout << "=========" << endl;
}

int image6() {
    cout << " _______" << endl;
    cout << " |     |" << endl;
    cout << " |     O" << endl;
    cout << " |    /|\\" << endl;
    cout << " |    / \\" << endl;
    cout << " |" << endl;
    cout << "=========" << endl;
}
};

void displayHangman(int attempts) {
    Image i;
    switch (attempts) {
        case 0: i.image0(); break;
        case 1: i.image1(); break;
        case 2: i.image2(); break;
        case 3: i.image3(); break;
        case 4: i.image4(); break;
        case 5: i.image5(); break;
        case 6: i.image6(); break;
    }
}

const char* getRandomString(const char* strings[], int size) {
    srand(static_cast<unsigned int>(time(0)));
    int randomIndex = rand() % size;
    return strings[randomIndex];
}

int main() {
    const char* strings[] = {"apple", "banana", "orange", "grape", "pineapple"};
    int size = sizeof(strings) / sizeof(strings[0]);
    string secretWord = getRandomString(strings, size);
    int maxAttempts = 6, incorrectAttempts = 0;
    string guessedLetters;


    while (incorrectAttempts < maxAttempts) {
        displayHangman(incorrectAttempts);
        for (char letter : secretWord) {
            if (guessedLetters.find(letter) != string::npos) {
                cout << letter << " ";
            } else {
                cout << "_ ";
            }
        }

        cout << "\n\n";

        // Prompt the user for a guess
        char guess;
        cout << "Enter your guess: ";
        cin >> guess;

        // Add the guessed letter to the string
        guessedLetters += guess;

        // Check if the guess is incorrect
        if (secretWord.find(guess) == string::npos) {
            incorrectAttempts++;
            cout << "Incorrect guess. Attempts remaining: " << maxAttempts - incorrectAttempts << "\n";
        }

        cout << "\n-----------------\n";

        // Check if the word has been completely guessed
        bool wordGuessed = true;
        for (char letter : secretWord) {
            if (guessedLetters.find(letter) == string::npos) {
                wordGuessed = false;
                break;
            }
        }

        // End the game if the word has been guessed
        if (wordGuessed) {
            cout << "Congratulations! You guessed the word: " << secretWord <<"\n" ;
            break;
        }
    }

    // If the number of incorrect attempts reaches the maximum, the player loses
    if (incorrectAttempts == maxAttempts) {
        cout << "Game over! You failed to guess the word.\n";
    }

    return 0;
}
