# Harvest Card Game

## About

Harvest Card Game (working title) is a C++ console application of an original farming-themed card game being developed for commercial release. This project is meant to prototype and playtest the physical card game, and was also used as a final project in my computer science courses.


## Author

My name is Bran Seals and I am recent Computer Science graduate (AS) based in Columbus, Indiana. I have an interest in most everything, consider myself a lifelong learner, and enjoy being well-rounded.

I'm happy to receive input, advice, criticism, or other forms of help, as there are always new things to learn in this field. If you have any feedback, job opportunities (I'm seeking!), or just want to say hello, feel free to write to brandon.seals@gmail.com.


## Objective

One to four players use their starting gold to buy crop seeds, tools, and livestock from a shared market to gradually build and grow their farm over many seasons. The player that builds the most wealth by the end of the game wins.


## Contents



## Play Area



## Game Flow



## Player Turn



## Classes

### Card
A card contain the following attributes:

Card ID - unique value representing card
Season - card associated with which season
Name - title of card
Description - describes how card works
Effect - what card does
Effect Target - what card type or ID is targeted
Value - gold gained when sold
Cost - how much card costs in market
Face Up - face-up or face-down


### Deck
Currently, the Deck class represents the suite of decks used to fill the market rather than a single, logical deck. This class will be changed later to describe a single deck, and this suite of decks will be moved into the Game class.

### Farm
Represents a player's hand and contains seeds, tools, and livestock cards. Cards are added here after being purchased from the market, and are acted on during a player's turn. 

### Game
Initializes the rules, players, decks, season, and market. Contains the main game loop.

### Market
Displays three cards each of crop seeds, tools, and livestock for sale to the current player. When a card is purchased here, a card will be drawn from the Deck class to replace it.

### Player
Contains player information, an instance of Farm (the player hand), and methods to allow a player to interact with the market and their farm. 

### Season
Contains information on the game length, the current season, and displays an event card and handles its effect.