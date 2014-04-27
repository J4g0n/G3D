#include "Polygon.h"

void P_init(Polygon *p) {
	p->_nb_vertices=0;
	p->_is_closed=0;
	p->_is_filled=0;
	p->_is_convex=0;
}

void p_copy(Polygon *original, Polygon *copie) {
	int i;
	copie->_nb_vertices=original->_nb_vertices;
	copie->_is_closed=original->_is_closed;
	copie->_is_filled=original->_is_filled;
	copie->_is_convex=original->_is_convex;
	for(i=0;i<original->_nb_vertices;i++) {
		copie->_vertices[i].x=original->_vertices[i].x;
		copie->_vertices[i].y=original->_vertices[i].y;
		copie->_vertices[i].z=original->_vertices[i].z;
	}
}

void P_addVertex(Polygon *P, Vector v, unsigned int pos) {
	P->_nb_vertices++;
	P->_vertices[pos].x=v.x;
	P->_vertices[pos].y=v.y;
	P->_vertices[pos].z=v.z;
}

void P_removeLastVertex(Polygon *P) {
	P->_nb_vertices--;
}

void P_draw(Polygon *P) {
	int i;
	for(i=0;i<P->_nb_vertices;i++) {
	}//j'en suis la cf drawQuad
}

void P_print(Polygon *P, char *message) {
	int i;
	printf("Nbres sommet: %d\n",P->_nb_vertices);
	for(i=0;i<P->_nb_vertices;i++) {
		printf("Sommet %d: (x=%f, y=%f,	z=%f)\n",i,P->_vertices[i].x,P->_vertices[i].y,P->_vertices[i].z);
	}
}

void  P_tournerAutourDeLAxeY(Polygon *P, double radians) {
}
