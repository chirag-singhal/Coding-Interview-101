#include <stdio.h>

int bits;

void p(int m);
void d();
void g();
void h();

int main() {
	printf("MAIN -> %u\n", &bits);
	int a = 0;
	int hi = 10e2;
	int m;
	while(a < hi) {
		m = a + (hi - a) / 2;
		p(m);
		a = m + 1;	
	}
	g();
	h();
	d();
	
	return 0;	
}

void p(int m) {
	if(!m)
		return;
	printf("PILANI %d -> %u\n", &m);
	p(m - 1);
}

void d() {
	int dub;
	printf("DUBAI -> %u\n", &dub);
}

void g() {
	int goa;
	printf("GOA -> %u\n", &goa);
}

void h() {
	int hyd;
	printf("HYDERABAD -> %u\n", &hyd);
}
