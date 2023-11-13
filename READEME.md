## Certification
"I have read and understood the Academic Misconduct Policy for
Undergraduates, the related sections 102.01-102.016 and 105.15 of the
UC Santa Cruz Student Policies and Regulations Handbook,
and the related sections of the class syllabus."

Akshant Lanjewar

"I wrote this assignment using only permitted sources
 that do not require citation, according to the syllabus."

## How to Compile
To compile the program is simple, simply run the command
```
> make
```
into your CMD, and the project will be compiled and linked.

## How to Run
Here are all the scenarios for command line arguments and how the program should react to each scenarios.

- If the program receives **no command line arguments**
	User receives an error message and the program terminates with a non-zero exit code.
- If the program receives `-`
	This signifies that the user wants to type the file name into the program. Program needs an edge case to handle this case.
- if the program receives `{input_file}.in`
	Then we use the input file and read it in, building the output treating it as directed.
- if the program receives `-U {input_file}.in`
	Then we use the input file, but we build the output treating it as undirected.

## How to Run Tests
The `IntVec` portion of the project has a full test suite written for it. In order to run it, first run the command
```
> make intVecTest
```
Then you can run the code as so
```
> ./intVecTest
```
If the program returns a code of 0, then all the tests have run successfully, meaning that the IntVec library is 100% ready to be used. 