#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct A{}; // POD
struct B{ ~B(){} }; // non-POD
struct C{ ~C(){} }; // non-POD

template <class T>
void* operator new[](size_t size,T* p){
	printf("new[](size=%ld,address=%p)\n",size,p);
	return p;
}


void* operator new[](size_t size,void* p){
	printf("new[](size=%ld,address=%p)\n",size,p);
	return p;
}

int main(void){
	
	// struct A is a POD type
	A *a = new(&a)A[1];
	intptr_t a_offset = (intptr_t)((uint8_t*)a-(uint8_t*)&a);
	printf("A raw ptr = %p\n",&a);
	printf("A new ptr = %p\n",a);
	printf("A offset  = %ld\n",a_offset);
	printf("\n");
	
	// struct B has a destructor
	B *b = new(&b)B[1];
	intptr_t b_offset = (intptr_t)((uint8_t*)b-(uint8_t*)&b);
	printf("B raw ptr = %p\n",&b);
	printf("B new ptr = %p\n",b);
	printf("B offset  = %ld\n",b_offset);
	printf("\n");
	
	// struct C has a destructor
	C *c = new((void*)&c)C[1];
	intptr_t c_offset = (intptr_t)((uint8_t*)c-(uint8_t*)&c);
	printf("C raw ptr = %p\n",&c);
	printf("C new ptr = %p\n",c);
	printf("C offset  = %ld\n",c_offset);
	printf("\n");
	
	return 0;
}

