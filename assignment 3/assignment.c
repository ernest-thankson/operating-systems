#include <stdio.h>
#include <math.h>




/*
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
*/

int main(int argc, char *argv[]){
	if (argc < 3){
		printf("insufficient arguments supplied");
	}
	if (argc >3){
		printf("too many arguments provided");
	}
	if (argc == 3){
		printf("working...");
	}
	//printf("calcPolygonArea(4, 5.0) = %f\n", calcPolygonArea(4, 5.0));
	//printf("detNumTriangles(4) = %d\n", detNumTriangles(4));
}
