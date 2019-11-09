To compile: run 'make' command
To run: run 'make run' command

Version 2.00

It is still an ascii game for linux terminal environment but now with a UI!

Comments:
    Grid logic seems good, converting it to cartesian doesn't seem to provide any added advantage
    other than more readable code for indexes!

Scope of updates:

    Make UI more friendly and polished!

    Refactor the code to be more object oriented!


-----------------------------------------------------------------------------

Version 1.00

It is now an ascii game for linux terminal environment.

Game ends when the warrior is killed by enemies.

Comments:
    Previos version was build for windows
    Added makefile
    No memleaks
    
Scope of updates:

    _getch() was used for windows version -> getchar() is used currently -> ncurses needs to be implemented 

    better GUI is required 

    the code can be more object Oriented 
    check the grid number logic as well.
