#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>


#define PI 3.14159
#define READ_END 0
#define WRITE_END 1

double calcPolygonArea(int pType, int length){
	double numerator = pow(length, 2) * pType;
	double denominator = 4 * sin(PI/pType)/cos(PI/pType);
	double area = numerator/denominator;
	return area;
}

int detNumTriangles(int numSide){
	int ans = numSide - 2;
	return ans;
}


int main(int argc, char *argv[]){
	int write_message = atoi(argv[1]);
	int read_message;
	int pipe_channel[2];
	int numSides = atoi(argv[1]);
	int length = atoi(argv[2]);
	if (argc < 3){
		printf("insufficient arguments supplied\n");
	}
	if (argc >3){
		printf("too many arguments provided\n");
	} 
	if (argc == 3){
		printf("working...\n");
	}
	if(pipe(pipe_channel) == -1){
		fprintf(stderr,"The pipe could not be created");
		return 1;
	}
	
	
	
	int childProcess = fork();
	if(childProcess < 0){
	 fprintf(stderr, "There was an error creating the new process\n");
	 exit(1);
	}else if(childProcess > 0){
		printf("calcPolygonArea(%d, %d) = %f\n", numSides, length, calcPolygonArea(numSides, length));
		close(pipe_channel[READ_END]);
		write(pipe_channel[WRITE_END], &write_message, sizeof(write_message));
		close(pipe_channel[WRITE_END]);
	}else{
		close(pipe_channel[WRITE_END]);
		read(pipe_channel[READ_END],&read_message,sizeof(read_message));
		printf("detNumTriangles(%d) = %d\n", read_message, detNumTriangles(read_message));
		close(pipe_channel[READ_END]);
		
	}
	
	return 0;
}



