# Final Project (Explorer Mode) for Math173 in Fall 2014

#### These are the instructions Professor Arenas provided:

####  Exam Part 1: The Exploration Tool

======
In this part of the exam you will create a tool where users can explore the effect of bias
on housing patterns. You may model this portion after “Exploration mode.exe” (make
sure all bitmap files are in the same directory as the executable before you test it).

Your program should begin by querying the user for

• The bias, expressed as a decimal number

• The proportion of red residents, a decimal number between 0 and 1 inclusive.

• The proportion of green residents, a decimal number between 0 and 1 inclusive.

The two proportion values do not need to add up to 1. There can be empty space
(unoccupied houses).

The program should generate a 15 unit by 15 unit grid of randomly placed red and green
residents in the proportions specified. These residents should either be happy, sad, or
indifferent according to the rules described above.  At this point the user is allowed to move residents using the mouse to unoccupied posi-
tions. The user may only move residents who are sad – indifferent and unhappy residents
can not be moved. Keep in mind that by moving residents the state of neighboring
residents will tend to change – someone who was happy before may become sad.
The program must report the level of segregation in real-time as the user moves around
residents. When all residents are happy or indifferent the user can no longer interact with
the grid.


Extra credit: Pressing ‘r’ reloads the grid in a new configuration. This is not easy! Your understanding of memory management will need to be perfect.
======

#### Please see Final exam score.txt for final score