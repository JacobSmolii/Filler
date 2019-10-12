# Filler
## Game-playing AI project in C language

### Project Overview

The purpose of this project is to write a competitive AI to place more random objects sent by Virtual Machine on a playing board than the opponent. To put a piece, the player have to write its coordinates in the "Y X\n" format on the standard input (stdin). The game appears on the standard input. 

## Algorithm

On the begining of each turn, a Heat Map is created. It represents the Map of the game. Values are assigned on each case of the map. It starts from the position of the ennemy and is incremented until it reaches the board edges :

![image]https://user-images.githubusercontent.com/45500862/66694730-8e9fbd80-ec6b-11e9-8e8b-ec83ce075893.png





#### Usage: ./filler_vm -f path [-i | -p1 path | -p2 path] <b>[-s | -q | -t time]
   -t  --time		set timeout in second
   <br>-q  --quiet		quiet mode
   <br>-i  --interactive	interactive mode(default)
   <br>-p1 --player1	use filler binary as a first player
   <br>-p2 --player2	use filler binary as a second player
   <br>-f  --file		use a map file (required)
   <br>-s  --seed		use the seed number (initialization random) (man srand)</b>
   

