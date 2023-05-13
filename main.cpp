#include<iostream>
#include<vector>
#include<cstdlib>
using std::vector;

//establish values and suits for cards
enum Value {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};
enum Suit {HEARTS, SPADES, DIAMONDS, CLUBS};
//create a data struct for a card that has the basic components of what a card will be
struct Card 
{
    Suit suit;
    Value value;
    int num;
    int numOfSuits = 4;
    int numOfValues = 13;
};
//create a data struct that has the basic components of a 'deck'
struct Deck 
{
    vector<Card> cards;
    int deckSize = 52;
};

//a class to abstract the functions of the 'player' and 'dealer'
class Participent
{
    public:
    //both player and dealer will have a hand & a score
    Deck hand;
    int score;
    //this method will remove a random card from the main deck and place it in the participents deck once
    void Deal(Deck deck)
{
    size_t index = rand() % deck.cards.size();
    hand.cards.push_back(deck.cards[index]);
}
//resets all decks and the score to zero
void resetHand()
{
    hand.cards.clear();
    score = 0;
}

void evaluate()
{
    //first evaluates the score and if neither the dealer or the player won, give an option to hit or stand
    for(Card c : hand.cards)
    {
        score += c.value;
    }
    //both player and dealer will hit until they are equal or lower than 17
    if(score < 17)
    {
      //deal cards
    }
    else if(score >= 17)
    {
        //do nothing
    }
}

};

void setupDeck(Deck);
void Deal(Deck&);
void resetHand();
void evaluate();
void tallyScores(Participent, Participent);
void loop();

int main() 
{
   loop();
}

void loop()
{
    Participent player;
    Participent dealer;
    int l = 0;
    int j = 0;
    Deck mainDeck;
    setupDeck(mainDeck);
    //this will run exactly 100 times
    while(l < 100)
    {
        //checks if j is under two and then will stop working. This deals two cards before everything else starts.
     player.Deal(mainDeck);
     dealer.Deal(mainDeck);
             //starts a repeating loop of checking and printing the results
        player.evaluate();
        dealer.evaluate();
        tallyScores(player, dealer);
    }
    player.resetHand();
    dealer.resetHand();
    mainDeck.cards.clear();
    l++;
}

//checks player and dealers scores and prints to the console
 void tallyScores(Participent player, Participent dealer)
    {
        if(player.score == 21)
        {
            printf("PLAYER WINS!\n");
        }
        else if(dealer.score > 21)
        {
            printf("PLAYER WINS!\n");
        }
        else if(dealer.score == 21)
        {
            printf("PLAYER LOSES!\n");
        }
        else if(dealer.score > player.score && dealer.score > 21)
        {
            printf("PLAYER LOSES!\n");
        }
        else if(dealer.score == player.score)
        {
            printf("DRAW\n");
        }
        
    }

void setupDeck(Deck deck)
{
    
        Card card;
        //increments the suit that is assigned to the card
        for(int suit = 0; suit < card.numOfSuits; suit++)
        {
            //increments the value that is assigned to the card
            for(int value = 0; value < card.numOfValues; value++)
            {
                //assigns the suit and value to a single card
                card.suit = Suit(suit);
                card.value = Value(value);
                Card card;
                card.num = card.value +1;
                deck.cards.push_back(card);
            }
        }

        for(Card c : deck.cards)
        {
            switch(c.value)
            {
            case 0:
            c.num = 1;
            break;

            case JACK:
            c.num = 10;
            break;

            case QUEEN:
            c.num = 10;
            break;
            
            case KING:
            c.num = 10;
            break;
            }
        }

}