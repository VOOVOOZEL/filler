# filler
Some kind of "XO" game


Algorithm

On the begining of each turn, a Heat Map is created. It represents the Map of the game. Values are assigned on each case of the map. It starts from the position of the ennemy and is incremented until it reaches the board edges.

Then, the algorithm try to put the piece on each position of the map. One case of the piece has to overlap one of my previous. It calculates the score on each position. The smaller the score is, the best it is, because it will get closer of the ennemy and bother him to play.

