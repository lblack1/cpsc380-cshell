/**
 * Simple c command shell using forked processes and pipes.
 *
 * Author: Lloyd Black
 * Github: github.com/lblack1
 * For CPSC380 - Operating Systems
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

#define BUFFER_SIZE 512
#define READ_END	0
#define WRITE_END	1

typedef enum {false, true} bool;

int main(void)
{
	char write_msg[BUFFER_SIZE];
	char read_msg[BUFFER_SIZE];
	pid_t pid;
	int fd[2];

	/* create the pipe */
	if (pipe(fd) == -1) {
		fprintf(stderr,"Pipe failed");
		return 1;
	}

	/* now fork a child process */
	pid = fork();

	if (pid < 0) {
		fprintf(stderr, "Fork failed");
		return 1;
	}

	if (pid > 0) {  /* parent process */
		/* close the unused end of the pipe */
		close(fd[READ_END]);

		printf("osh > ");

		/* Pipe writing loop */
		while (strcmp(write_msg, "quit\n") != 0) {
	
			fgets(write_msg, BUFFER_SIZE, stdin);

			/* write to the pipe */
			write(fd[WRITE_END], write_msg, strlen(write_msg)+1); 

		}

		/* close the write end of the pipe */
		close(fd[WRITE_END]);
	}
	else { /* child process */
		/* close the unused end of the pipe */
		close(fd[WRITE_END]);

		read(fd[READ_END], read_msg, BUFFER_SIZE);		

		while (strcmp(read_msg, "quit\n") != 0) {
			/* read from the pipe */
			
			system(read_msg);

			printf("osh > ");
			fflush(stdout);

			read(fd[READ_END], read_msg, BUFFER_SIZE);
		}

		/* close the write end of the pipe */
		close(fd[READ_END]);
	}

	return 0;
}
