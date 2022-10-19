# Echo any command 
A C program on Ubuntu that echo any command.
## Objective
- Echo any command entered by the user.
- If the user entered "exit", the shell will reply with "Good Bye :)" and terminate. 
## Commands used for compilation 
1. gcc -E code.c > code.i (Preprocessing)
2. gcc -S code.i  (Compiling)  
3. gcc -c code.s  (Assembling)
4. gcc -o code.out code.o  (Linking)
## Example
### Sample input 0
pwd
### Sample output 0
pwd
### Sample input 1
exit
### Sample output 1
Good Bye :)