Author:Juan Villafan

Description: 
My project is simple.
It is a game that works on guessing a random number. The user inputs a name that is saved into a structure. The user then chooses a difficulty, (easy : medium : hard), which will create the guessing range. Easy gives the user 1-20, Medium gives the user 1-50, and Hard gives the user 1-100. To make the game more difficult, the random number changes after each guess:

        -If the original number is 5, and the user guesses incorrectly, the number changes to 15.

The users best score is saved into the structure that carries the name, categorized by difficulty. The user may play he game as many times as they want, but the scores reset after each new gaame is started.

    -User : Juan    Easy Score : 18    Medium Score : 27    Hard Score : 48

The lower the score, the better. In between rounds you can choose to continue, and choose to view your current highscores.Viewing your current highscore is not neccesary and does not affect the code. 


A huge issue that occured was a problem with my recursion. I assumed it had to do with my cin but could not find an easy fix after half an hour. However, with a quick google search and the help of google assistance, i found that cin leaves a \n output which ruins the next recursion and just ends my code, as it read the input as something other than "y", which told my function to end. I learned about cin.ignore, which allowed my program to ignore the \n from each input, letting the recurions run with no issue.
