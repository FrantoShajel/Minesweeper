# Minesweeper
A beginner version of the famous Minesweeper Game using basic functions in C++
## How To Play
Just run the code in a C++ environment and the game starts in the output screen of the IDE.
## Choose Difficulty <br/>
1 -> Easy <br/>
2 -> Medium <br/>
3 -> Difficult <br/>
## Navigation
Then the game starts with a 8x8 grid. The number of bombs to be found in the grid depends on the level of difficulty chosen. The navigation through the grid is using the following keys:<br/>
  - A - Left
  - D - Right 
  - W - Up 
  - S - Down 
  - K - Action
## Choose Action  
The action option(K) provides a new set of options that can be performed on the particular cell.<br/>
  > Open(O)		- This option opens the cell and indicates the number of the cell(i.e, the total number of bombs in its neighbouring cells).<br/>
  
  > Flag(F)		- This option helps to flag the bomb cells so that the player does not get confused.<br/>
  
  > Unflag(U)	- This option unmarks the flagged cell 
## Win/Lose
-> The player wins when all the safe cells are opened. <br/>
-> The player loses if he/she opens any cell hiding the bomb.
## Note
The grid size does not change with the level of difficulty. Since this is a beginner model, I have set different number of bombs for each level of difficulty (easy -> 8 / medium -> 12 / difficult -> 16). 
