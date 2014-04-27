
/*======================================================*\
  Wednesday September the 25th 2013
  Arash HABIBI
  Vector.c
\*======================================================*/

#include "Vector.h"

//------------------------------------------------
double det(Vector a,Vector b,Vector c) {
	double res;
	res=a.x*(b.y*c.z-b.z*c.y)-a.y*(b.x*c.z-b.z*c.x)+a.z*(b.x*c.y-b.y*c.x);
	return res;
}

Vector V_new(float x, float y, float z)
{
  Vector v;
  v.x = x;
  v.y = y;
  v.z = z;
  return v;
}

//------------------------------------------------
// a des fin de debug

Vector V_add(Vector v1, Vector v2) {
	Vector y;
	y.x=v1.x+v2.x;
	y.y=v1.y+v2.y;
	y.z=v1.z+v2.z;
	return y;
}

Vector V_substract(Vector v1, Vector v2) {
	Vector y;
	y.x=v1.x-v2.x;
	y.y=v1.y-v2.y;
	y.z=v1.z-v2.z;
	return y;
}

Vector V_multiply(double lambda, Vector v) {
	Vector y;
	y.x=lambda*v.x;
	y.y=lambda*v.y;
	y.z=lambda*v.z;
	return y;
}

Vector V_cross(Vector v1,Vector v2) {
	Vector v;
	v.x=v1.y*v2.z-v1.z*v2.y;
	v.y=v1.z*v2.x-v1.x*v2.z;
	v.z=v1.x*v2.y-v1.y*v2.x;
	return v;
}

int V_isOnTheRight(Vector M, Vector A, Vector B) {
	double val=det(A,B,M);
	if(val>0) {
		return 0;
	}
	else {
		return 1;
	}
}

int segmentsIntersect(Vector p1, Vector p2, Vector q1, Vector q2) {
	double det1=det(q1,q2,p1);
	double det2=det(q1,q2,p2);
	double det3=det(p1,p2,q1);
	double det4=det(p1,p2,q2);
	if (det1*det2<0 && det3*det4<0) {
		return 1;
	}
	else {
		return 0;
	}
}

int V_rayIntersectsSegment(Vector M, Vector u_ray, Vector p1, Vector p2) {
	double det1=det(M,u_ray,p1);
	double det2=det(M,u_ray,p2);
	if (det1*det2<0) {
		return 1;
	}
	else {
		return 0;
	}
}

void V_print(Vector v, char *message) {
  fprintf(stderr,"%s : %f %f %f\n",message, v.x,v.y,v.z);
}

