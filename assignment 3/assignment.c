#include <stdio.h>
#include <math.h>





#define PI 3.14159

double calcPolygonArea(int pType, double length){
	double numerator = pow(length, 2) * pType;
	double denominator = 4 * sin(PI/pType)/cos(PI/pType);
	double area = numerator/denominator;
	return area;
}


int main(){
	printf("calcPolygonArea(4, 5.0) = %f", calcPolygonArea(4, 5.0));
}
