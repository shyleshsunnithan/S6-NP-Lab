#include<stdio.h>
#include<unistd.h>

int main()
{
	int p_id,i,n;
	printf("Enter the Limit (n) : \n");
	scanf("%d",&n);
	
	p_id = fork();
	
	if (p_id==0){
		
		for(i=0;i<n;i++){
			if(i%2==1){
				printf("Parent --->  %d\n",i);
			}
		
		}
	
	}
	
	else{
		
		printf("Parent ID is  %d\n",getppid());
		printf("Child ID is  %d\n",getpid());
		for(i=0;i<n;i++){
			if(i%2==0){
				printf("Child --->  %d\n",i);
			}
		
		}
	
	}
	

}

