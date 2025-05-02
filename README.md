# GamblingLife 

## Project Context
The "GamblingLife" project is a C implementation of an interactive and immersive BlackJack game. The goal was to create a game that integrates classic BlackJack mechanics while adding advanced features such as statistics management and an interactive interface using Raylib.

## Implemented Features

### Game Rules
The project follows the classic BlackJack rules, including:
- Draw a card ("Hit")
- Stay ("Stand")
- BlackJack (21 with two cards: an Ace and a 10-value card)
- Double down: doubling the bet after the first two cards and drawing one final card.

### Card Management
Cards are drawn randomly, with an accurate representation of their values:
- Face cards (Jack, Queen, King) are worth 10 points.
- Aces can be worth either 1 or 11 points, depending on the player's hand.

### Bank and Credit Management
The player starts with a certain amount of virtual credits:
- Winnings and losses are calculated based on bets and game results.
- The bank handles winnings payouts and collects losses.

### Saving and Statistics
- Player credits are saved in a file, allowing game state persistence between sessions.
- Statistics include winrate calculation (percentage of games won), also stored in a file.

### Interactive Interface
The display was implemented using Raylib, offering a dynamic and intuitive graphical interface that enhances the user experience.

## Technical Choices

### Naming Conventions
To ensure code consistency and adhere to conventions, the lowerCamelCase naming style was adopted. This improved code readability and maintainability.

### Data Management
Saving data in `.txt` files was chosen to allow credit and statistics persistence between sessions. This was a good balance between complexity and functionality.

### Raylib for the Interface
Raylib was chosen for its ease of use and graphical capabilities. It enabled the application to be more interactive and visually appealing.

## Challenges Faced

- **Ace Management:** The dual value of the Ace (1 or 11) required particularly complex logic to prevent errors in point calculations.
- **Randomization and Fairness:** Ensuring a fair random draw while avoiding duplicates required a rigorous deck logic implementation.
- **Data Persistence:** Managing files to save credits and statistics required special attention to avoid data corruption.
- **Card Drawing:** Ensuring that drawn cards do not repeat incorrectly.
- **Raylib Integration:** Although powerful, learning and integrating Raylib took time, especially for real-time event handling and rendering across different resolutions.
- **User Error Handling:** Managing cases where user inputs were incorrect or unexpected (such as invalid bets) required robust validation.

## Possible Improvements

- **Multiplayer:** Allowing multiple players in the same session (or AI players competing).
- **Different Casinos:** Introducing casinos from around the world (Monte Carlo, Las Vegas) with different entry fees, minimum/maximum bets, and various dealers.
- **Statistics Optimization:** Displaying additional details such as the average number of rounds won or lost.
- **Adding Side Bets**
- **Adding Bonuses**
- **Animations:** Special animations for the dealer when dealing cards, victory sequences, unique card designs, etc.
 
