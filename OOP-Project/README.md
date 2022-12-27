The project contains three classes - football player, team and championship. Each team has a player type vector and each league has a team type vector.

In the main function of the program, players and teams are initially read from two files, via a stream. Next, we create an object of type Championship and give it a name. 
We create two vectors of player type and team type, and then through methods we load them with the information we have read from the files.
We set the vector of teams to the championship and call the friend function play(League& league) as the only parameter we pass the championship. 
The work of this function as well as the internal function playGame(Team& team1, Team& team2) is to realize playing each team with each, as in playGame(Team& team1, 
Team& team2) we generate random numbers from 1 to 3 according to srand() whether the first team will win, tie or the second team will win and we modify the points and 
data of both teams accordingly. At the end, we sort the teams by points in descending order and print the data of each team.
