# cpsc380-cshell
A simple c shell using forked processes and pipes.

Lloyd Black
2295968
lblack@chapman.edu
CPSC380
Tom Springer

A program that accepts arbitrary commands and executes them in the same direcory as the shell executable. Meant to demonstrate basic forking and pipe IPC.

1. Source Files - sshell.c

2. Issues - The cd command doesn't fail, but also doesn't change directories.

3. References - man pages, stack overflow, in-class lecture notes, collaboration with Matt Raymond (https://www.github.com/raymo116), Silberschatz, Galvin, and Gagne Operating System Concepts  - Ninth Edition

4. Description of Program - Reads in commands from the user and executes them in a child process using the same directory location and environment varibles as the compiled sshell executable.
