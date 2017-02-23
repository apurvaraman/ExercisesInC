Apurva Raman
Reflection 2

### Written Reflection

For sprint 2, we focused on learning more C, so we did more exercises and readings as a result of the discussion we had in our retro at the end of sprint 1. This was helpful for me, although I'm still struggling with working in C. After the retro for sprint 1, we decided to do some more pair programming, and that has been helping me be able to tackle more of the project work without getting stuck after making a silly mistake and then spending a long time tracking it down. As of the current sprint, we are working on more project focused things again, which gives me the opportunity to meet more of my learning goals related to understanding processes, the unix shell, and learning more C.

Our approach to eduScrum hasn't changed much. We met fewer times outside of class, due to doing more individual work.

We are pretty much where we expected we would be in terms of project progress (although I would like to have had a bit more mastery of C). We are unsure whether we are fully equipped to do globbing correctly (less related to regex functionality, but more figuring out how to manage reading input from stdin before a newline character is pressed).

### Head First C exercises

Chapter 2.5: https://github.com/apurvaraman/ExercisesInC/tree/master/exercises/ex02.5
Chapter 3: https://github.com/apurvaraman/ExercisesInC/tree/master/exercises/ex03
Chapter 4: https://github.com/apurvaraman/ExercisesInC/tree/master/exercises/ex04
Chapter 9: https://github.com/apurvaraman/ExercisesInC/tree/master/exercises/ex09


### Think OS reading questions
For this sprint, I completed Think OS 3, 4, and 6.
https://github.com/apurvaraman/ExercisesInC/blob/master/reading_questions/thinkos.md

### Exam question
(Is this question too trivial/specific? I'm unsure whether this is exam-worthy, so I look forward to your feedback. I tried to word it correctly, but perhaps saying "in the file system" is unclear.)

Think OS 4: What happens in the file system when fclose() is called on a file?

The data in the buffer is written to disk and the memory for that file's OpenFileTableEntry (the table data structure that represents the file) is freed.  
