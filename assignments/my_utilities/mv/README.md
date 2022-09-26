# my_mv "move" 
A C utility on Ubuntu to move a file.
## Objective
- Move a file from directory to another.
- Copy file's content and remove the original
## Syscalls and commands used 
1. open
2. write 
3. close
4. remove
## Example
### Sample input 0
my_mv move_this.txt file_moved.txt
### Sample output 0
ls --> file_moved.txt 