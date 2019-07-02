## Build Instructions
	Assuming you have cloned the project, the steps needed would only be to type 'make' in	  the project. Once done, build has completed.
## Run Instructions
	After make has been entered, you will type './fc'. This will run the project.

## What your code does
	my program copies bytes from one file into the next. Resulting in copying over the same content. If neither from nor to are created, it creates a new one. If the 'to' file already exist, it overwrites. It does this by making use of system calls as well as knowing where to place bytes once theyve been read.   



## strace/dtruss output

% time     seconds  usecs/call     calls    errors syscall
------ ----------- ----------- --------- --------- ----------------
  0.00    0.000000           0         5           read
  0.00    0.000000           0         6           write
  0.00    0.000000           0         2           close
  0.00    0.000000           0         4           fstat
  0.00    0.000000           0         1         1 lseek
  0.00    0.000000           0         5           mmap
  0.00    0.000000           0         4           mprotect
  0.00    0.000000           0         1           munmap
  0.00    0.000000           0         3           brk
  0.00    0.000000           0         3         3 access
  0.00    0.000000           0         1           execve
  0.00    0.000000           0         1           arch_prctl
  0.00    0.000000           0         4           openat
------ ----------- ----------- --------- --------- ----------------
100.00    0.000000                    40         4 total



## Explanation of Output

read: is called 5 times because there are 4 lines < the buff_max in the file and the 5th would be a 0. therefore explaining the call.
write: is called 6 times because it is the line after read, causing the increment. it breaks out of the loop at this point.
close: is called twice because it closes the file descriptors. which there were only 2.
fstat: is called by the amount of times read was called with the exception of the terminating 0, which was the return once done.
lseek: throws an error because the offset could not be represented accordingly.
mmap: shows the number of time the read write and execute was called???
mprotect: was protecting something having to do with read...
munmap: calls for terminating  a process. Possibly the read.
brk was called to allocate more memory effectively?
access: calls 3 errors because these are not directories. these are files.
execve: called because there is 1 to file name
arch_prctl: something having to do with the memory location...
openat:called because each of the lines in the file had < buff_max and there was 4 lines, so it was called 4 times.  




















