# ProgramExecutor

Creates new process using vfork and initialize it by program which name and arguments are provided by command line. Works like a shell. Project includes comparison of the performance in using fork, vfork and system call.

## What I learned

* Receiving the arguments from command line with appropriate validation
* Forking process (fork and vfork).
* Reinitialization of the child process (familiy of ‘exec’ system-calls)

## Usage

Compile files
```
gcc -Wall main.c argument_parser.c program_executor.c -o program_executor
```
Run command
```
program_executor
```
