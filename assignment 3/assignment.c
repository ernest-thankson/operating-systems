#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>


#define PI 3.14159

double calcPolygonArea(int pType, double length){
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
	int numSides = atoi(argv[1]);
	double length = (double)argv[2];
	if (argc < 3){
		printf("insufficient arguments supplied\n");
	}
	if (argc >3){
		printf("too many arguments provided\n");
	} 
	if (argc == 3){
		printf("working...\n");
	}
	printf("calcPolygonArea(%d, %f) = %f\n", numSides, length, calcPolygonArea(numSides, length));
	
	
	int childProcess = fork();
	if(childProcess < 0){
	 fprintf(stderr, "There was an error creating the new process\n");
	 exit(1);
	}else if(childProcess == 0){
		printf("detNumTriangles(%d) = %d\n", numSides, detNumTriangles(numSides));
	}
	
	return 0;
}



