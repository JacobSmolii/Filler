# Filler
## Game-playing AI project in C language

### Project Overview

The purpose of this project is to write a competitive AI to place more random objects sent by Virtual Machine on a playing board than the opponent. To put a piece, the player have to write its coordinates in the "Y X\n" format on the standard input (stdin). The game appears on the standard input. 

## Algorithm

On the begining of each turn, a Heat Map is created. It represents the Map of the game. Values are assigned on each case of the map. It starts from the position of the ennemy and is incremented until it reaches the board edges :

![image](https://user-images.githubusercontent.com/45500862/66694881-8b0d3600-ec6d-11e9-8697-079b5a15fc07.png)

Then, the algorithm try to put the piece on each position of the map. One case of the piece has to overlap one of my previous. It calculates the score on each position. The smaller the score is, the best it is, because it will get closer of the ennemy and bother him to play.

![image](https://user-images.githubusercontent.com/45500862/66694834-e3900380-ec6c-11e9-83b2-e0ff9664f144.png)

A piece may look something like this:

![image](https://user-images.githubusercontent.com/45500862/66694901-ed663680-ec6d-11e9-8b02-6514bfd2ff3f.png)


#### Usage: ./filler_vm -f path [-i | -p1 path | -p2 path] <b>[-s | -q | -t time]
   -t  --time		set timeout in second
   <br>-q  --quiet		quiet mode
   <br>-i  --interactive	interactive mode(default)
   <br>-p1 --player1	use filler binary as a first player
   <br>-p2 --player2	use filler binary as a second player
   <br>-f  --file		use a map file (required)
   <br>-s  --seed		use the seed number (initialization random) (man srand)</b>
   

