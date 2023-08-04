// Assessment test 2
// Game of twenty-one

#include "deck.h"
#include <iostream>


int main()
{
    Deck<Card> deck1;

    for (auto card : deck1) {
        std::cout << card.suite << ", " << card.value << '\n';
    }

    

    
}