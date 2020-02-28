#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fd1[2];
    int fd2[2];
    int val = 0;
    int msg = 0;

    // create pipe descriptors
    pipe(fd1);
    pipe(fd2);

    // fork() returns 0 for child process, child-pid for parent process.
    if (fork() != 0)
    {
        // parent: writing only, so close read-descriptor.
       close(fd1[0]);

        // send the value on the write-descriptor.
        printf("Enter the Number to be sent : ");
        scanf("%d",&val);
        write(fd1[1], &val, sizeof(val));
        printf("Parent(%d) send value: %d\n", getpid(), val);
        
        close(fd1[1]);
        
        read(fd2[0], &msg, sizeof(val));
        if(msg==1){
        	printf("divisble by 3 \n");
        }
        
       else if (msg==0){
       	printf("not divisible by 3 \n");
       }

        // close the write descriptor
        //close(fd[1]);
        close(fd2[0]);
    }
    else
    {   // child: reading only, so close the write-descriptor
        close(fd1[1]);
	int msg;
        // now read the data (will block)
        read(fd1[0], &val, sizeof(val));
        printf("Child(%d) received value: %d\n", getpid(), val);
	
	 close(fd1[0]);
	
	if(val%3==0){
		msg=1;
		//write(fd[1], &msg, sizeof(val));
	}
	if(val%3!=0){
		msg=0;
		//write(fd[1], &msg, sizeof(val));
	}
	write(fd2[1], &msg, sizeof(val));
        // close the read-descriptor
       // close(fd[0]);
        close(fd2[1]);
    }
    return 0;
}
