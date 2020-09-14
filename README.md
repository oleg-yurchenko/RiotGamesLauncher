# Riot Games Launcher
This launcher is compiled with Visual Studio 2019 and uses the [Sciter SDK](https://sciter.com/) This particular version is designed for windows, but I'm sure if you edit (Insert name of class that runs different games) for your preferred system, it would be able to work nicely, although Riot is releasing a new anti-cheat which prevents some systems from playing the game with wine.
# What is this project?
This is a launcher for all of Riot Games' games. They are soon to be releasing an open-world game [here](https://www.pcgamesn.com/league-of-legends/open-world-rpg) and have also teased a fighting game [here](https://www.pcgamer.com/league-of-legends-fighting-game-project-l/). Since they are going to be expanding their game library, I feel that it is time to create a proper launcher instead of having your desktop filled with seperate launcher for their games.
# How does it work?
Riot Games has a seperate client that is installed when you download any of their games called the Riot Games Client. What it does is it initializes all the files and launches the game when you click the desktop shortcut. After examining the shortcuts, it is possible to figure out how to launch this client from the terminal with specific command line variables such as the name and patchline of the game. This means that it is possible to launch any of Riot Games' game by running a simple command and replacing the name of the game and the patchline.
