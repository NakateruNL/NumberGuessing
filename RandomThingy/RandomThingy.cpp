#include <iostream>
#include <time.h>

// Casino number guessing game

int main()
{
    int DiceRoll, RndRange{}, GuessNumber, Choice;
    

    srand(time(NULL));


    // Input

    Begin:
    std::cout << "(1) for custom range (2) for random range [Limit 100]\n";
    std::cin >> Choice;

    if (Choice == 1) {
        goto Switch;
    }
    else if (Choice == 2) {
        goto Switch;
    }
    else {
        std::cout << "Choose either 1 or 2.\n";
        goto Begin;
    }

    Switch:
    switch (Choice) {
        case 1: {
            Range:
            std::cout << "Enter a custom range: \n";
            std::cin >> RndRange;
                
            if (RndRange > 100) {
                std::cout << "Your choice can't be higher than 100.\n";
                goto Range;
                }

            DiceRoll = rand() % RndRange + 1;
            goto Guess;
            // 1- Input
            // std::cout << DiceRoll << "\n";
            break;
            
        }
        case 2: {
            DiceRoll = rand() % 100 + 1; 
            RndRange = 100;
            goto Guess; // 1-100
            // std::cout << DiceRoll << "\n";
            
        }
           Guess:
           int Guess;
           std::cout << "What number do you guess? Range (1-" << RndRange << ")\n";
           std::cin >> Guess;

           if (Guess != DiceRoll) {
               std::cout << "Your guess is wrong ";
               if (Guess > DiceRoll) {
                   std::cout << "the number is lower.\n"; 
               }
               else if (Guess < DiceRoll) {
                   std::cout << "the number is higher.\n";
               }
               goto Guess;
           }
           else {
               std::cout << "Congratulations, you guessed it right!";
               std::cout << "\n" << "\n" << "\n" << "\n";
               std::cout << "Made by Avoidy#5910 and ZwieberVos#3182\n";
           }

           std::string terminate;
           std::cout << "Enter Q to Quit!\n";
           std::cin >> terminate;

           if (terminate == "q" || terminate == "Q") {
               exit(1);
           }


    }

}