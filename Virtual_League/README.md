# VIRTUAL LEAGUE

**FEATURES**
- There are 18 teams in the Virtual League. This number can be changed if necessary. 
- Team names (one or more words) and coach names (two words) are read from the file named “takimlar.txt”.
- While the team names are read from the file, aliases of the related teams are created. These nicknames must consist of 2 or 3 letters. 
- Each team has a different nickname. 
- Nickname and technical director information of the relevant team whose team name is entered in the application are displayed on the screen. 

An example of nicknames is shown below.

![TeamNickname](https://user-images.githubusercontent.com/59221929/155006716-8ab34183-1615-47c0-aa9d-ba055492dea8.png)

- Teams are formed by producing player information. Random football player names and surnames can be generated from the information in the “name.txt” and “surname.txt” files.
- Age information from 18 to 36 and jersey number from 1 to 99 are randomly assigned to players.
- The region in which the player plays is determined as Defender (D) - Midfielder (O) - Striker (F). 
- The average performance of the player is determined by a random number between 30 and 100. The performance value can also be changed via the menu.

- While forming teams of 11 players, the following items are considered:
  + When creating teams from random players, the formation information received from the user must be followed. If the user leaves this information blank, 4 Defenders – 4 Midfielders – 2 Forwards should be assigned by default.
  + Each team must be formed with an average performance of at least 60 (Total Player Performance / 11).
  + Each team must be formed with an average age of at least 25 and at most 32.
  + All player information and team information of the team whose nickname is entered in the application should be displayed on the screen.




