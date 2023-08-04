#ifndef DECK_H
#define DECK_H
#include <vector>
#include <string>

class Card
{
    public:

        // note: I couldn't get the enum classes to work but left them here for
        // future possibilities

        // enum class Suite {
        // hearts,
        // spades,
        // clubs,
        // diamonds,
        // };

        // enum class Value {
        // two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace
        // };

        // Card(Suite in_suite, Value in_value);

        Card(std::string in_suite, int in_value);
        
        ~Card();

        std::string suite {};
        int value {};


    private:   
        // Suite suite {};
        // Value value {};
        // bool ace_is_14 {true};
};

template <typename T>
class Deck 
{
    public:
        using storage_type = std::vector<T>;
        using value_type = T;
        using reference = T&;
        using const_reference = const T&;
        using iterator = typename storage_type::iterator;
        using const_iterator = typename storage_type::const_iterator;
        using size_type = typename storage_type::size_type;

        Deck() {
            fill_deck();
            current_size = 52;
        }

        T& top() {
            return deck.back();
        }

        T& bottom() {
            return deck.front();
        }

        T draw() {
            T card = deck.back();
            deck.pop_back();
            return card;
        }

        iterator begin() {
            return deck.begin();
        }

        const_iterator cbegin() {
            return deck.cbegin();
        }

        iterator end() {
            return deck.end();
        }

        const_iterator cend() {
            return deck.cend();
        }

        void fill_deck() {
            std::string suite;
            for (int i = 1; i < 14; ++i) {
                for (int j = 0; j < 4; ++j){
                    if (j == 0) {
                        suite = "hearts";
                    } else if (j == 1) {
                        suite = "spades";
                    } else if (j == 2) {
                        suite = "clubs";
                    } else {
                        suite = "diamonds";
                    }
                    
                    Card card (suite, i);
                    deck.push_back(card);
                }
            }       
        }

        ~Deck() {};

    private:
        storage_type deck {};
        unsigned int current_size {};
        const unsigned int MAX_SIZE {52};
    
};

Card::Card(std::string in_suite, int in_value) {
    suite = in_suite;
    value = in_value;
}

// Card::Card(Card::Suite in_suite, Card::Value in_value) {
//     suite = in_suite;
//     value = in_value;
// }

Card::~Card() {   
}


#endif