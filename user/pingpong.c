#include "kernel/types.h"
#include "kernel/fcntl.h"
#include "user/user.h"


int main(int argc,char *argv[])
{
	int child_fd[2];
	int parent_fd[2];

	//Buffer to write and read from
	int child_buf[1];
	int parent_buf[1];
	
	if(pipe(child_fd)<0)
		exit(1);

	if(pipe(parent_fd)<0)
		exit(1);

	if(fork()==0)
	{
		while(read(child_fd[0],child_buf,1)<=0)
		{}
		printf("The child is reading from the pipe with %d \n",getpid());
		write(parent_fd[1],parent_buf,1);
		exit(0);
	}
	else
	{
		write(child_fd[1],child_buf,1);
		while(read(parent_fd[0],parent_buf,1)==0)
		{}
		printf("The parent is reading from the pipe with %d \n",getpid());
		wait(0);
		exit(0);
	}

}
