# simple shell
A C program to mimic simple features of linux shell and apply parent child concept

## Objective
- Executing bash commands (e.g. "ls -l", "pwd", etc.)     
- Executing my commands (e.g. my_cp, my_echo, etc.)
- Tokenize input commands
- Store local varaibles. 
- View local varaibles with command "set".
- Export local variables to environment variables with command "export variable_name".     

## Main commands used 
1. fork, execvp, wait (make parent and child processes)
2. strtok (tokenization)
3. setenv (convert local variable to environment variable)
