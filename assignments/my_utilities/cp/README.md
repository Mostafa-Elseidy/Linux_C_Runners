# my_cp "copy" 
A C utility on Ubuntu to copy a file.
## Objective
- Copy a file from directory to another.
- Copy file's content in batches
## Syscalls and commands used 
1. open
2. write 
3. close
## Example
### Sample input 0
my_cp copy_this.txt copy_this2.txt
### Sample output 0
ls --> copy_this.txt, copy_this2.txt 