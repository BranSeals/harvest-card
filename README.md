# Harvest Card Game

## About
Harvest Card Game (working title) is a C++ console application of an original farming-themed card game being developed for commercial release. This project is meant to prototype and playtest the physical card game, and was also used as a final project in my computer science courses.

## Status

This project is not currently being developed or maintained.

The purpose of this project is prototype the card game, and as such it is not a representation of the final game. Not all cards and features are complete, and parts of the game are subject to change. The rules are manually set to be low for ease of testing, and is not meant to be played as-is.

More features can be added such as Seasonal event support, and more efficient data structures.

## Author
Bran Seals; Senior QA Engineer. I'm more apt to break code than create it, so I'm happy to receive input, advice, criticism, or other forms of help.

## Objective
One to four players use their starting gold to buy crop seeds, tools, and livestock from a shared market to gradually build and grow their farm over many seasons. The player that builds the most wealth by the end of the game wins.

## Contents

### Gold
The game's currency. This doubles as the player's score at the end of the game. Gold can be earned by selling crops or tending to livestock.

### Seed Deck
Contains various seasonal crops. These cards are planted and raised by the player. These cards are sold during harvest at the end of each season. Bonus gold is earned if the crop's season matches the current season.

### Livestock Deck
Contains various farm animals. Livestock can offer gold at the end of every turn when tended to by tools. Each livestock card has a matching tool card (e.g. Cow and Milk Pail).

### Tool Deck
Contains tools to work the farm. A tool card can be used once per turn to raise a crop or tend to an animal.

## Play Area

### Market
Contains the Seed, Livestock, and Tool decks. Three of each will be face-up, signifying they are for sale. At the beginning of each player’s turn, empty slots in the market will be filled using the corresponding decks.

### Player Farm
Each player has an area containing crops, tools, and livestock they have purchased. This area reprensents the player's hand, and is visible to all players.

### Current Season
Contains the current season’s deck, acting as a game timer. A season card is flipped every turn, and when the deck is depleted, the season is over and harvesting begins. The next season’s deck will then be placed in this location. The size of Season decks will determine how long the game lasts.

## Game Flow
Game is played as follows:
* Youngest player goes first, with play moving clockwise.
* At the beginning of each player’s turn, a Season card is turned face-up. If this card describes an event, it must be handled at this point.
* Each player takes turns until the Season deck runs out of cards.
* When the Season deck runs out of cards, a harvest begins – players tally up the crops they were able to grow during the season and earn gold for each. Seasonal crops matching the season get a bonus. Crop cards are then turned face-down and the next season begins. (NOTE: Crop cards may be removed here).
* The next season’s deck is placed in the Current Season area and normal gameplay resumes.
* Game is played until a specified amount of time has passed.

## Player Turn
Each turn involves the following actions:
* Turn over a Season card and respond to its event (if any).
* Refill any empty market slots from the item decks.
* Use gold to buy any amount of seeds, tools, or livestock from the market.
* Place any items purchased directly into your farm. Seed cards are placed face-down.
* Use Tool cards to work your farm (e.g. Watering Can turns Seed card face-up, which now shows a raised crop).
* Turn ends when all Tool cards are used, or earlier if desired.

## File List

### Class files
Header and implementation files for the project's classes, each of which are described in detail below.

### cards.txt
This plaintext file contains information on all cards used in this project. This file is used as input to create Card objects during gameplay. This can be optimized by pulling the file into memory to speed up card creation.

### cards_edit.txt
This plaintext file contains an easier-to-read format for editing purposes. Paired with the CardEdit class, this file is converted and written into cards.txt.

### UML.txt
Contains a plaintext UML representation of the classes and their relationships. Can be used with [PlantText](https://www.planttext.com/).

### evaluation.txt
Contains an analysis of various data structures used during the evaluation project for my Computer Science III (Data Structures) course. This version of the program is not currently uploaded, but the document describes which structure I have chosen to implement in future versions as well as the data that supports this decision.

## Classes

### Card
Each card contain the following attributes:
* Card ID - unique value representing card
* Season - card associated with which season
* Name - title of card
* Description - describes how card works
* Effect - what card does
* Effect Target - what card type or ID is targeted
* Value - gold gained when sold
* Cost - how much card costs in market
* Face Up - face-up or face-down

### Deck
Currently, the Deck class represents the suite of decks used to fill the market rather than a single, logical deck. This class will be changed later to describe a single deck, and this suite of decks will be moved into the Game class.

### Farm
Represents a player's hand and contains seeds, tools, and livestock cards. Cards are added here after being purchased from the market, and are acted on during a player's turn.

### Game
Initializes the rules, players, decks, season, and market. Contains the main game loop, and determines which cards are used in the game.

### Market
Displays three cards each of crop seeds, tools, and livestock for sale to the current player. When a card is purchased here, a card will be drawn from the Deck class to replace it.

### Player
Contains player information, an instance of Farm (the player hand), and methods to allow a player to interact with the market and their farm.

### Season
Contains information on the game length, the current season, and displays an event card and handles its effect.

### CardEdit
Contains functions to read and write card information between cards.txt and cards_edit.txt files. If edit file does not exist, it can be created using existing card file and calling the function updateEditFile(). If edit file has been modified, the cards.txt file can be updated by calling updateCardFile().
