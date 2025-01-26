## SkyRace

### Identification of the team members:

Tao Ran 3035771268 raissa@connect.hku.hk

Cheng Sanli 3035973323 u3597332@connect.hku.hk

Chen Linxi 3036101551 u3610155@connect.hku.hk

Huang Junfei 3035825100 u3582510@connect.hku.hk

Wong Kei In 3036099930 keiin@connect.hku.hk



### Video demo link:
https://connecthkuhk-my.sharepoint.com/:v:/g/personal/u3597332_connect_hku_hk/ETwEkCy_9XRBgPwXcB6HaNUBVHkSZ-vbOZTgqjp1Fs1XNQ?nav=eyJyZWZlcnJhbEluZm8iOnsicmVmZXJyYWxBcHAiOiJPbmVEcml2ZUZvckJ1c2luZXNzIiwicmVmZXJyYWxBcHBQbGF0Zm9ybSI6IldlYiIsInJlZmVycmFsTW9kZSI6InZpZXciLCJyZWZlcnJhbFZpZXciOiJNeUZpbGVzTGlua0NvcHkifX0&e=PQQS78




### Compilation and execution in struction:
For compilation and execution, please type the command "make" in the terminal to compile the files and type "./gamee" to execute the program in the terminal.



### Description of the game:
SkyRace is a simplified version of the classic board game Ludo, featuring an 8x8 game board. It offers two game modes: Mode 1, where a human player competes against a robot player, and Mode 2, which allows two human players to face off. Players take turns rolling the dice to advance a certain number of steps along the perimeter of the board represented by the dots. Unlike traditional Ludo game, in which the player will automatically forward or backward when encountering random events, our random events are designed to be interactive small games that will reward the player(s) if the games results are success or penalize the player(s) when the games' results are failure. Random events occur when player(s) reach(es) the 5th, 10th, 15th, 20th, and 25th steps, adding excitement to the game. The objective is to be the first player to finish one round and claim victory.



### Assumptions of the game:
1. The game is played on a square board of size 8x8, with the edges marked by '.' and the inner cells marked by ' '.
2. The total number of steps to complete a round is calculated as (BOARD_SIZE * 4) - 4, which is 28 steps for an 8x8 board.
3. The game supports two modes: Single Player (against a Robot Player) and Two Players.
4. The players start at position 0 and move around the board in a clockwise direction.
5. The players take turns rolling a dice and moving their positions based on the dice roll result.
6. If a player's position exceeds the total number of steps, they are set back to the starting position (0) and win.
7. There are specific positions on the board (5, 6, 10, 11, 15, 16, 20, 21, 25, 26) where random events occur when a player lands on them.
8. In Single Player mode, the Robot player automatically rolls the dice and moves. If the Robot player lands on a specific position, a random event is triggered for them.
9. The game ends when either both players have finished the round (reached position 0), or one player has finished while the other hasn't.
10. The dice is a normal dice with the probability of 1 to 6 being equal.
11. "boom" event assumes that there are only four options and the player can only select one of these. The probability of selecting each color as the correct answer is the same. 
12. "navigation" event assumes that the answer is only two-digit.
13. "rsp" event assumes that the player knows the rule of the rock-paper-scissors game and the game assumes that the players do not want to play the third round after the winner is known.
14. “hangman” event assumes all the words are from wordlist.txt. The string: secret_word has a length between 3 and 7. 
15. "surprise" event assumes the probability of being rewarded and punished after choosing smashing the egg are the same.



### The apperance of the initial game board:

B&nbsp;.&ensp;&ensp;.&ensp;&ensp;.&ensp;&ensp;.&ensp;&ensp;.&ensp;&ensp;.&ensp;&ensp;.  
.&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;.  
.&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;.  
.&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;.  
.&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;.  
.&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;.  
.&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;.  
.&ensp;&nbsp;.&nbsp;&ensp;.&nbsp;&ensp;.&nbsp;&ensp;&nbsp;.&nbsp;&ensp;&nbsp;.&nbsp;&ensp;&nbsp;.&nbsp;&ensp;&nbsp;. 
 

Where:
B stands for the initial position that Player 1 and Player 2 are in the same position. If they are seperate, 1 stands for Player 1, and 2 stands for Player 2.





### Game rules:
1. At the beginning of the game, choose Mode 1 or Mode 2: Mode 1, where a human player competes against a robot player, and Mode 2, which allows two human players to face off.
2. Enter "r", Player 1 rolls the dice, followed by Player 2 (or Robot Player). 
3. Players move forward a number of steps based on the result of their dice roll. For example, if a player rolls a 4, they move forward four steps. (Wait for 2 seconds to join the next round if no event is triggered.)
4. When a player reaches the 5th, 6th, 10th, 11th, 15th, 16th, 20th, 21th, 25th or 26th step, a random event is triggered.
The random events include:
- Boom: Players must guess the color (red, green, blue or yellow) of the a bomb. Guessing correctly allows them to move forward 3 steps, while an incorrect guess results in moving back 2 steps. (game1_boom.h & game1_boom.cpp)
- Navigation: Players have to guess a two-digit number. If the guess is larger than the answer, it will show that your guess is larger than the answer; Otherwise, it will show that your guess is smaller than the answer. The players will have five chances. A correct guess allows them to move forward 3 steps, while an incorrect guess leads to moving back 1 step. (game2_navigation.h & game2_navigation.cpp)
- RSP: Players engage in three games of rock, paper, scissors with a wizard. If the players win, they will move forward 2 steps; Otherwise, they will move back 1 step. (game3_rsp.h & game3_rsp.cpp)
- Hangman: Players must guess the correct answer to a given word, all the words are the name of animals. The screen will show a series of dashes that present the length of guessed word. Players need to enter a alphabet to guess. If the players correctly guess all the letters before the complete "hangman" is drawn (in 6 times), they will be able to move forward 2 steps, otherwise they will move back 1 step. (game4_hangman.h & game4_hangman.cpp)
- Surprise: Mid-flight, the players stumble upon a mysterious airborne surprise. Players choose whether to smash an egg or let it be. Smashing it could bring rewards to make the players forward 2 steps or bring punishments and slide back 2 steps. Otherwise, the players will stay at the current position. (game5_surprise.h & game5_surprise.cpp)
5. When a robot reaches the 5th, 6th, 10th, 11th, 15th, 16th, 20th, 21th, 25th or 26th step, a random event is triggered. The game includes an element of chance through random events. After each player's turn, the AI player triggers a random event that can either propel them forward or set them back. The possible events are as follows:
- Lucky Win: The robot player moves forward 2 steps.
- Lucky Win: The robot player moves forward 1 step.
- Lucky Win: The robot player moves forward 3 steps.
- Unlucky Loss: The robot player moves backward 2 steps.
- Unlucky Loss: The robot player moves backward 1 step.
- Unlucky Loss: The robot player moves backward 3 steps.
6. Players continue taking turns, rolling the dice, advancing steps, and triggering special events until one player reaches the finish line (the initial dot on the game board).
7. The first player to reach the finish line wins the game, and the game concludes.






### Explanation of Features Implemented and Coding Elements:
1. Generation of random game sets or events:
   - The game generates random events when players land on specific positions on the board.
   - The "boom" event (game1_boom.h), "navigation" event (game2_navigation.h) and "surprise" event (game5_surprise.h) generate random answers that affect the player's position.
   - The "rock-paper-scissors" event (game3_rsp.h) generates random choices for the wizard opponent.
   - The "hangman" event (game4_hangman.h) randomly selects a word from a file for the player to guess.

2. Data structures for storing game status:
   - The game uses a 2D vector `board` to represent the game board and store the positions of the players.
   - The `player1Pos` and `player2Pos` variables keep track of the current positions of the players on the board.
   - The `player1Finished` and `player2Finished` flags indicate whether each player has finished the game.

3. Dynamic memory management:
   - The game uses STL containers such as `vector` and `dynamic arrays` for dynamic memory management.
   - The `board` vector is dynamically resized based on the `BOARD_SIZE` constant.
   - The `words` vector in the "hangman" event is dynamically populated with words loaded from a file.
   - The `hangman_art` dynamic array in the "hangman" event is used.

4. File input/output:
   - The "hangman" event (game4_hangman.h) loads words from a file named "wordlist.txt" using the `load_words_from_file` function.
   - The loaded words are stored in the `words` vector for use in the "hangman" game.

5. Program codes in multiple files:
   - The game code is organized into multiple files, each representing a different module or event.
   - The main file (gamee.cpp) includes the necessary header files for each event (game1_boom.h, game2_navigation.h, game3_rsp.h, game4_hangman.h, game5_surprise.h).
   - The separate compilation of these files allows for modular development and easier maintenance of the codebase.

6. Proper Indentation:
- The code follows a consistent indentation style, making it easier to read and understand the structure of the code.
- Each block of code, such as loops, conditionals, and function definitions, is properly indented to clearly distinguish the scope and hierarchy of the code.
- The consistent use of indentation enhances the readability and maintainability of the codebase.

7. Naming Styles:
- The code follows a consistent naming convention for variables, functions, and constants.
- Variable and function names are descriptive and meaningful, indicating their purpose or functionality.
- Constants are named using uppercase letters and underscores to differentiate them from variables.
- The consistent naming style improves code comprehension and makes it easier for other developers to understand the purpose of each entity in the codebase.

Examples:
- Variables: `player1Pos`, `player2Pos`, `player1Finished`, `player2Finished`
- Functions: `initBoard`, `displayBoard`, `rollDice`, `movePlayer`, `aiRandomEvent`
- Constants: `BOARD_SIZE`, `TOTAL_STEPS`

8. In-Code Documentation:
- The code includes comments and documentation to explain the purpose, functionality, and important details of various code segments.
- The comments provide insights into the logic behind certain operations, making it easier for developers to understand and maintain the codebase.
- The documentation also includes explanations of specific events, such as the "boom" event, "navigation" event, "rock-paper-scissors" event, "hangman" event, and "surprise" event.





### Non-Standard Libraries:
- No non-standard libraries are used, ensuring compliance with the course requirements that all necessary functionalities must be self-contained within the 
  provided code, and no additional installations are required for compiling and running the game on any standard system.




### Creative and Fun Elements:
- Combination of Modes: The game offers two different modes of play, Mode 1 (human player vs. robot player) and Mode 2 (two human players). This allows for flexibility and accommodates different player preferences and scenarios.

- Random Events: The game introduces random events triggered when players reach specific steps. These events add an element of surprise and variety to the gameplay, making it more engaging and unpredictable.

- Variety of Challenges: The random events present different challenges for the players to overcome. From guessing the color of a bomb to solving a navigation puzzle, playing rock, paper, scissors with a wizard, or guessing words in hangman, the game incorporates a range of mini-games that test players' skills and knowledge.

- Time Element: The game incorporates a time element by introducing a 2-second delay between rounds if no event is triggered. This adds a sense of urgency and keeps the gameplay dynamic.

- Strategic Choices: The surprise event introduces a choice for players to either smash an egg or let it be. This decision can bring rewards or punishments, allowing players to make strategic choices that may impact their progress in the game.

- Multiplayer Interaction: The game encourages interaction and competition between players. In Mode 1, a human player competes against a robot player, while in Mode 2, two human players face off against each other. This fosters social engagement and creates opportunities for friendly competition.
