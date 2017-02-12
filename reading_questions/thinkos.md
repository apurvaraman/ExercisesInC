## Chapter 1


### Compilation (Completed)

1) Give an example of a feature common in interpreted languages that is rare in compiled languages.

Dynamic typing.

2) Name two advantages of static typing over dynamic typing.

Dynamic typing saves space and checks for errors at compile time, so the code does not have to be run.

3) Give an example of a static semantic error.


An incompatible type: int a = 1.5;

4) What are two reasons you might want to turn off code optimization?

If there is a subtle bug, optimization may alter the program's behavior.
Optimization also takes more time.


5) When you run `gcc` with `-S`, why might the results look different on different computers?

It is configured to generate assembly code specific to your architecture.

6) If you spell a variable name wrong, or if you spell a function name wrong,
the error messages you get might look very different.  Why?

Spelling a function name wrong is an error found by the linker because the linker checks for functions. Spelling a variable name wrong is found by the compiler.

7) What is a segmentation fault?

Reading/writing to an incorrect location in memory.


## Chapter 2 (Completed)


### Processes

1) Give a real-world example of virtualization (ideally not one of the ones in the book).

When buying winter boots over break, I went to the website of the shoe store near my house and requested that the shoes I wanted to try be delivered to the store. The physical store only had a small selection of shoes, but I could request any of the shoes the chain of stores had stocked provided I was willing to wait for the delivery.

2) What is the difference between a program and a process?

A process is a software object or data structure that represents a program and contains information about the program and its execution.

3) What is the primary purpose of the process abstraction?  What illusion does the process abstraction create?

The abstraction allows programmers to not have to worry about how a particular program might interact with other programs. It creates the illusion of a dedicated memory and hardware.

4) What is the kernel?

The kernel is the part of the OS responsible for core functionality (like threads).

5) What is a daemon?

Daemons run in the background and perform OS services.



## Chapter 3


### Virtual memory (Completed)

1) The Georgian alphabet has 33 letters.  How many bit are needed to specify a letter?

6 bits (6b100001).

2) In the UTF-16 character encoding, the binary representation of a character can take up to 32 bits.  
Ignoring the details of the encoding scheme, how many different characters can be represented?

2^32 (32d4294967296)

3) What is the difference between "memory" and "storage" as defined in Think OS?

RAM is referred to as memory and HDD/SSD is referred to as storage.

4) What is the difference between a GiB and a GB?  What is the percentage difference in their sizes?

GiB is 2^30 bytes and GB is 10^9 bytes. A GiB is about 7.374% larger than a GB.

5) How does the virtual memory system help isolate processes from each other?

It employs memory protection by allocating different parts of the physical address space to each process, regardless of whether the same virtual addresses are used because it is done on a per-process basis.

6) Why do you think the stack and the heap are usually located at opposite ends of the address space?

The stack and heap are both things that we want to be able to expand, and there are some situations where we allocate a lot of stack memory and not much heap and vice versa. It makes sense to have them grow in opposite directions to minimize the chance that they interfere with each other.

7) What Python data structure would you use to represent a sparse array?

dict, since it is an unordered set of key-value pairs.

8) What is a context switch?

A context switch is when an OS interrupts a running process, saves the state, and then starts another process.

In this directory, you should find a subdirectory named `aspace` that contains `aspace.c`.  Run it on your computer and compare your results to mine.

Your results:
Address of main is   0x      40057c
Address of global is 0x      60104c
Address of local is  0x7fffd26139c4
Address of p is      0x     1c3b010

My results:
Address of main is 0x40057d
Address of global is 0x60104c
Address of local is 0x7ffe119a47d4
Address of p is 0xb68010


1) Add a second call to `malloc` and check whether the heap on your system grows up (toward larger addresses).  

The addresses increased, so it grows up.

2) Add a function that prints the address of a local variable, and check whether the stack grows down.  

The addresses decreased, so it grows down.

3) Choose a random number between 1 and 32, and allocate two chunks with that size.  
How much space is there between them?  Hint: Google knows how to subtract hexadecimal numbers.

32 bytes.

## Chapter 4


### Files and file systems

1) What abstractions do file systems provide?  Give an example of something that is logically
true about files systems but not true of their implementations.

The file system abstraction models storage as a persistent mapping between a file name and a series of bytes. The OS translates byte-based operations (which is how the file system works logically) into blocks (which is how it is implemented).

2) What information do you imagine is stored in an `OpenFileTableEntry`?

It should contain a read/write flag, a position, a pointer to the memory, and possibly an offset to deal with blocks.

3) What are some of the ways operating systems deal with the relatively slow performance of persistent storage?

Caching and good cache replacement policies, prefetching, block transfers, and buffering.

4) Suppose your program writes a file and prints a message indicating that it is done writing.  
Then a power cut crashes your computer.  After you restore power and reboot the computer, you find that the
file you wrote is not there.  What happened?

The value was likely saved in a buffer, which did not persist, before it could be written to persistent memory.

5) Can you think of one advantage of a File Allocation Table over a UNIX inode?  Or an advantage of a inode over a FAT?

A FAT seems like a more direct representation of the memory on the disk, and there seems to be less overhead for the metadata and other information being stored.
I think with using inodes you can change a file and a process already using it will be unaffected.

6) What is overhead?  What is fragmentation?

Space overhead is the amount of space that needs to be allocated. Fragmentation is when some memory is being left unused (either whole or partial blocks).

7) Why is the "everything is a file" principle a good idea?  Why might it be a bad idea?

The "everything is a file" principle is useful because streams are useful in cases like using piping and network communications. I'm not sure where it might be not useful, unless there is some additional overhead to treating everything like something that can be read/written to.

If you would like to learn more about file systems, a good next step is to learn about journaling file systems.  
Start with [this Wikipedia article](https://en.wikipedia.org/wiki/Journaling_file_system), then
[Anatomy of Linux Journaling File Systems](http://www.ibm.com/developerworks/library/l-journaling-filesystems/index.html).  
Also consider reading [this USENIX paper](https://www.usenix.org/legacy/event/usenix05/tech/general/full_papers/prabhakaran/prabhakaran.pdf).


## Chapter 5


### Bits and bytes

1) Suppose you have the value 128 stored as an unsigned 8-bit number.  What happens if you convert
it to a 16-bit number and accidentally apply sign extension?

2) Write a C expression that computes the two's complement of 12 using the XOR bitwise operator.
Try it out and confirm that the result is interpreted as -12.

3) Can you guess why IEEE floating-point uses biased integers to represent the exponent rather than a
sign bit or two's complement?

4) Following the example in Section 5.4, write the 32-bit binary representation of -13 in single precision
IEEE floating-point.  What would you get if you accidentally interpreted this value as an integer?

5) Write a function that takes a string and converts from lower-case to upper-case by flipping the sixth bit.  
As a challenge, you can make a faster version by reading the string 32 or 64 bits at a time, rather than one
character at a time.  This optimization is made easier if the length of the string is a multiple of 4 or 8 bytes.



## Chapter 6 (complete)


### Memory management

1) Which memory management functions would you expect to take constant time?  Which ones take time proportional to the size of the allocated chunk?

free seems like the only one that would take constant time since it just deallocates the pointer to the chunk, and since it is fast regardless of the number of free chunks, this seems to be the case. calloc is dependent on chunk size as well as the number of free chunks. (malloc does not usually depend on the size of the chunk. realloc can be fast if the new size is smaller than the current size, so in that way it is dependent on the size of the chunk but probably isn't proportional)

2) For each of the following memory errors, give an example of something that might go wrong:

a) Reading from unallocated memory.

Reads a value from whatever is stored at that memory location.

b) Writing to unallocated memory.

A bad value gets written, but you won't know it's an issue until it's read, which could be much later.

c) Reading from a freed chunk.

This is similar to reading from unallocated memory.

d) Writing to a freed chunk.

This is similar to writing to unallocated memory.

e) Failing to free a chunk that is no longer needed.

Memory leak, could lead to running out of available memory.

3) Run

    ps aux --sort rss

to see a list of processes sorted by RSS, which is "resident set size", the amount of physical
memory a process has.  Which processes are using the most memory?

Processes launched from atom and firefox.

4) What's wrong with allocating a large number of small chunks?  What can you do to mitigate the problem?

malloc isn't space efficient because there is an overhead associated with the tags and pointers. Allocating them in arrays may be more efficient.

If you want to know more about how malloc works, read
[Doug Lea's paper about dlmalloc](http://gee.cs.oswego.edu/dl/html/malloc.html)



## Chapter 7


### Caching

1) What happens if a program writes a new value into the program counter?

2) What is the fundamental problem caches are meant to solve?

3) If cache access time is 1 ns and memory access time is 10 ns, what is the average
access time of a program with hit rate 50%?  How about 90%?

4) The book gives several examples of programming language features, like loops, that tend
to improve locality in the access pattern of instructions and/or data.  Can you think of other examples?  
Or counter-examples that might decrease locality?

5)  If you refactor a program to improve locality, would you say the program is "cache aware"?  Why not?

6) See if you can estimate the cost of a memory cache by comparing the prices of two similar CPUs with
different cache sizes.

7) Why are cache policies generally more complex at the bottom of the memory hierarchy?

8) Can you think of a strategy operating systems could use to avoid thrashing or recover when it occurs?

Run the cache code on your laptop or another computer and see if you can infer the cache size and block size.  
If you can find the technical specifications for your computer, see if your inferences are right.

1) In this directory you should find a subdirectory named `cache` that contains `cache.c` and supporting files.  Read `cache.c`, then run `make` and `./cache`.

2) Run `python graph_data.py` to see the results.  What can you infer about the cache structure on your computer?


## Chapter 8


### Multitasking

1) What is the kernel's most basic task?

2) When an interrupt occurs, what part of the hardware state is saved by hardware?

3) What is the difference between an interrupt and a context switch?

4) Give an example of an event that might cause a process to move from the blocked to the ready state.

5) Why might a scheduler want to give higher priority to an I/O bound process?

When I make French toast, I usually make a batch of 12 slices.  But my griddle only has room for 8 slices.  Each piece of toast has to cook for 5 minutes on each side.  How can I schedule 12 slices onto 8 "cores" to minimize the elapsed time to cook all 12 slices?  (Note: this question is not hypothetical; this is really how I make French toast.)



## Chapter 9


### POSIX threads and mutexes

As you read Chapter 9, you should compile and run the example code.  By the nature of multi-threaded programs, you results will probably be different from mine, possibly in interesting ways.

1) Why does each thread have its own stack?

2) What does the `gcc flag -lpthread` do?

3) What does the argument of `pthread_exit` do?

4) Normally the same thread that created a thread also waits to join it.  What happens if another thread tries to join a thread it did not create?

5) What goes wrong if several threads try to increment a shared integer at the same time?

6) What does it mean to "lock a mutex"?



## Chapter 10


### Condition variables

1) What does it mean to say that a data structure is thread safe?

2) In the circular buffer implementation of a queue, why is the maximum number of elements in the queue `n-1`,
if `n` is the size of the array?

3) If there is no mutex to protect the queue, give an example of a sequence of steps that could leave
the queue in an inconsistent state.

4) When a thread calls cond_wait, why does it have to unlock the mutex before blocking?

5) When a thread returns from cond_wait, what do we know is definitely true?  What do we think is probably true?

6) What happens if you signal a condition variable when there are no waiting threads?

7) Do you have to lock the mutex to signal a condition variable?

8) Does the condition have to be true when you signal a condition variable?



## Chapter 11


### Semaphores in C
