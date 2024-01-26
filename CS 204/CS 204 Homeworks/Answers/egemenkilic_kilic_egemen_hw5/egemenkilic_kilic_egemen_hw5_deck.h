#include <iostream>
#include <string>
#include <ostream>

using namespace std;

struct Card
{
    string name;
    int energy;
};

class Deck
{
    private:
        Card *card;
        int size;
        
    public:
		/*
		----------------------------------------------------------------
						| Constructors and Destructor |
		----------------------------------------------------------------
		*/
		Deck(); // Default consturctor, no parameters
		Deck (int size) // Defaut constructor when a parameter is given
		{
			this->size = size;
			card = new Card[size];
		}
		~Deck();
		Deck(const Deck & copy); // Copy constructor
        Card* clone() const; // Clone for dynamic card array
		/*
		----------------------------------------------------------------
						| Member Operators |
		----------------------------------------------------------------
		*/
		Card operator [] (int idx)	const; 
		const Deck & operator = (const Deck & rhs); 
        Deck & operator += (Deck & rhs); 
		/*
		----------------------------------------------------------------
							| Setters |
		----------------------------------------------------------------
		*/	
		void setSize(int new_size);
		Card & setCards(Card * new_cards);
		/*
		----------------------------------------------------------------
							| Getters |
		----------------------------------------------------------------
		*/
		int getSize () const;
		string cardNameAtIndex(int idx) const;
		Card getCard (Deck deck_name, int idx) const;
		
};

// Default constructor
Deck::Deck() 
{
	size = 0;
	card = NULL;
}

Deck::Deck(const Deck & copy) // Copy constructor
{
	size = copy.size;
	card = copy.clone();
}

// Copy card
Card * Deck::clone() const
{
	Card* cloned_cards = new Card[size];
	
	for (int c = 0; c < size; c++)
	{
		cloned_cards[c] = card[c];
	}
	return cloned_cards;
}

// Retrieve a card from a deck
Card Deck::getCard (Deck deck_name, int idx) const
{
	return deck_name.card[idx];
}

// Retrieve size of deck
int Deck::getSize()	const
{
    return size;
}

// Set size of deck
void Deck::setSize(int new_size)
{
	size = new_size;
}

// Set the cards of deck
Card & Deck::setCards(Card * new_cards)
{
	card = new_cards;
	return *card;
}

// Retrieve card name from a deck
string Deck::cardNameAtIndex(int idx)	const
{
	return this->card[idx].name;
}

bool operator > (Deck deck_name, int card_count)
{
	int deck_name_size = deck_name.getSize();
	return (deck_name_size > card_count);
}

bool operator < (Deck lhs, Deck rhs)
{
	int lhs_limit = lhs.getSize();
	int rhs_limit= rhs.getSize();
	int lhs_total = 0, rhs_total = 0;

	for (int i = 0; i < lhs_limit; i++)
	{
		Card lhs_card = lhs.getCard(lhs, i);
		lhs_total += lhs_card.energy;
	}

	for (int j = 0; j < rhs_limit; j++)
	{
		Card rhs_card = rhs.getCard(rhs, j);
		rhs_total += rhs_card.energy;
	}

	return (lhs_total < rhs_total);
}

bool operator <= (Card lhs, Deck rhs)
{
	string search_name = lhs.name;
	
	int search_energy = lhs.energy;
	int rhs_limit = rhs.getSize();

	for (int i = 0; i < rhs_limit; i++)
	{
		Card rhs_card = rhs.getCard(rhs, i);
		string rhs_card_name = rhs_card.name;
		int rhs_card_energy = rhs_card.energy;

		if ( (search_name == rhs_card_name ) && (search_energy == rhs_card_energy) )
		{
			return true;
		}
	}

	return false;
}

bool operator == (Deck lhs, Deck rhs)
{
	int lhs_limit = lhs.getSize();
	int rhs_limit= rhs.getSize();
	int lhs_total = 0, rhs_total = 0;

	for (int i = 0; i < lhs_limit; i++)
	{
		Card lhs_card = lhs.getCard(lhs, i);
		lhs_total += lhs_card.energy;
	}

	for (int j = 0; j < rhs_limit; j++)
	{
		Card rhs_card = rhs.getCard(rhs, j);
		rhs_total += rhs_card.energy;
	}

	return (lhs_total == rhs_total);
}

const Deck & Deck::operator = (const Deck & rhs)
{
	card = rhs.clone();
	size = rhs.size;
	return *this;
}

Deck operator + (Deck lhs, Card rhs)
{
	Deck plus_deck;
	plus_deck.setSize(lhs.getSize() + 1);
	
	Card * deck_cards = new Card[lhs.getSize() + 1];
	
	int lhs_index = 0;

	for (;lhs_index < lhs.getSize(); lhs_index++)
	{
		deck_cards[lhs_index].name = lhs.getCard(lhs, lhs_index).name;
		deck_cards[lhs_index].energy = lhs.getCard(lhs, lhs_index).energy;
	}
	
	// New card's index will be deck_cards' last indexed card.
	int new_card_index = lhs_index;

	deck_cards[new_card_index].name = rhs.name; 
	deck_cards[new_card_index].energy = rhs.energy;

	plus_deck.setCards(deck_cards);

	return plus_deck;
}

Deck operator + (Deck & lhs, Deck & rhs)
{
	Deck plussed_deck;
	plussed_deck.setSize( lhs.getSize() + rhs.getSize() );

	Card * plussed_cards = new Card[lhs.getSize() + rhs.getSize()];

	int lhs_index = 0;

	for (; lhs_index < lhs.getSize(); lhs_index++)
	{
		plussed_cards[lhs_index].name = lhs.getCard(lhs, lhs_index).name;
		plussed_cards[lhs_index].energy = lhs.getCard(lhs, lhs_index).energy;
	}

	int lindex = lhs_index;

	for (int rindex = 0; rindex < rhs.getSize(); rindex++)
	{
		plussed_cards[lindex + rindex].name = rhs.getCard(rhs, rindex).name;
		plussed_cards[lindex + rindex].energy = rhs.getCard(rhs, rindex).energy;
	}
	
	plussed_deck.setCards(plussed_cards);

	return plussed_deck;
}

Deck operator - (Deck & lhs, int rhs)
{
	int new_size = lhs.getSize() - rhs;

	Deck minussed;
	minussed.setSize(lhs.getSize() - rhs);

	Card * minussed_cards = new Card[new_size];

	int lhs_size = lhs.getSize();

	for (int i = rhs; i < lhs_size; i++)
	{
		minussed_cards[i-rhs].name = lhs.getCard(lhs, i).name;
		minussed_cards[i-rhs].energy = lhs.getCard(lhs, i).energy;
	}
	
	minussed.setCards(minussed_cards);
	
	return minussed;
}

Deck & Deck::operator += (Deck & rhs)
{
	// I wrote the following but in an office hour I
	// was given the alternative to use the uncommented part and I
	// decided to use it instead to get more familiar with 
	// using this pointer.

/*	Card * new_cards = new Card[this->size + rhs.getSize()];
	Deck new_deck;

	int i = 0;
	for (; i < this->size; i++)
	{
		new_cards[i].name = this->card[i].name;
		new_cards[i].energy = this->card[i].energy;
	}

	for (int j = 0; j < rhs.getSize(); j++)
	{
		new_cards[i].name = this->card[i].name;
		new_cards[i].energy= this->card[i].energy;
		i++;
	}

	delete [] this->card;

	this->card = new_cards;
	
	return *this;
	*/
	*this = *this + rhs;
	return *this;
}

Card Deck::operator [] (int idx)	const
{
	return this->card[idx];
}

ostream & operator << (ostream & os, Deck deck_name)
{
    int limit = deck_name.getSize();

    for (int i = 0; i < limit; i++)
    {
        string card_name = deck_name.getCard(deck_name, i).name;
        int card_energy = deck_name.getCard(deck_name, i).energy;
        cout << i + 1 << ": "<< card_name << " - " << card_energy << endl;
    }
    return os;
}

Deck::~Deck()
{
	size = 0;
	delete [] card;
}