  Apurva Raman
  Reflection 1

  ### Written Reflection

  For this sprint, I wanted to get a sense of how a shell worked and interfaced with the OS and start learning C. I accomplished that, although perhaps not necessarily in the way I expected to. I was able to contribute to the project code by writing the process execution method, but I found my C skills aren't quite at the place they need to be to debug problems we ran into effectively. Doing more of the exercises should give me a better sense of how a C program should be structured and what might not be working effectively. As of this sprint, we are focusing more on exercises and getting a better foundation in C, which is helpful. It can be a bit difficult to keep up as I am still very much struggling with C, but it's not too overwhelming.

  We've been doing pretty well with eduScrum thus far, although our ceremonies are perhaps not as formal (with the exception of the retrospective and planning). It's a little strange to have structured standups at the beginning of class, but we aren't all necessarily on the same page about the work we are doing, so perhaps that might be something we should change.

  We were pretty well prepared for the sprint review since we had been discussing the readings. Starting the project helped as well because it gave me the opportunity to make a lot of mistakes. Even if I was tackling something completely wrong and ended up scrapping the whole thing, it gave me the opportunity to see more error messages and forced me to start thinking about memory much more. This helped me understand the questions better and also helped me identify gaps in my understanding that I could ask for clarification about during the sprint review (although perhaps that isn't the intention of the review).

  ### Head First C exercises
  Head First C 1: https://github.com/apurvaraman/ExercisesInC/tree/master/exercises/ex02

  Head First C 2: https://github.com/apurvaraman/ExercisesInC/tree/master/exercises/ex02

  ### Think OS reading questions
  For this sprint, I completed Think OS 1 and 2.
  https://github.com/apurvaraman/ExercisesInC/blob/master/reading_questions/thinkos.md

  ### Exam question
  HFC 6, ThinkOS 3: I did the reading questions and read through HFC 6 last sprint because we were having issues gaps in C knowledge for the project, so I chose to include it for this exam question even though the readings we "assigned" for Sprint 1 did not include this information.

  Where is the memory allocated for a variable assigned inside a function? If you want the value to persist over multiple function calls, what might you do? Where would the memory be allocated for your solution?

  Answer: The memory is stack allocated. You might use a static local variable to allow for the value of the variable to persist with repeated function calls. You might also define a global variable. In either case, it would be assigned in the static segment.
