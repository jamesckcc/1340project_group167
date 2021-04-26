1340project_group167
# team members:
u3582155 Chan Kwok Cheung
u3574505 Lau Cheuk Ning


# Introduction of game:
-Minesweeper is a single-player game with three difficulties, which are beginner mode(9x9=81 grids board with 10 bombs), intermediate mode(16x16=256 grids board with 40 bombs),   expert mode(24x24=547 grids board with 120 bombs) 

-winning method: To find out all the grids without bombs or flag all the bombs

# Gamerule:
1. After select the mode you want, the game will generate a board which the grid is in "*" format. 
2. You need to select an unopened grid each time and try not to select a grid with bombs. When the selected grid is opened, it will show a number which represent the bombs          adjacent to the grid. if the selected grid shows 0, it means that no bomb is next to it and all the grids adjacent to it will be opened too.
3. Other than open a grid each time, you can also select to use flag to locate the position of bombs. The number of flags that you can use are equal to the number of bombs. 


# Compilation and execution instructions:
please use the X2Go's terminal to run the game.
compilation method:
make msp
./msp
execution method:
1. You need to input the number for selecting to play a new game or loading the saved game or exit. if you select to play a new game, you need to input the number for selecting the number of game mode.
As the game board is in a square pattern which y-axis is number(1,2,3...) and x-axis is character(a,b,c...). 
2. when you are going to open a grid, you can input "p" in the beginning and the grid you want in yx format, such as p1a, p9c. 
3. when you are going to flag a grid, you can input "f" in the beginning and the grid you want in yx format, such as f1a, f9c. 
4. when you are going to unflag a grid, you can input that grid again same as the format of flag a grid.
5. If you want to save or exit the game when you are playing, you can input "s".


# Features of minesweeper
1. generate a board with different number of grids(for example (9X9),(16X16),(24X24)) and random placement of bombs.
2. Data structures for storing game status: 
3. Dynamic memory management: real time define the size for the minesweeper board
4. File input/output: allow the users to save the game status when they are playing the minesweeper, also allow the users to load the saved files(the minesweeper board they saved) and continue the game play.
5. Program codes in multiple files: we have seperate the programe code in different file which are the msp.cpp(save the function of running the game), msp.h(declare the existence of the function), msp_main.cpp(the main function for execute the game).
