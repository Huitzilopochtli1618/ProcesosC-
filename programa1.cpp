
#include <sys/types.h> 
#include <unistd.h> 
#include <sys/wait.h>
#include <stdio.h>
#include <iostream>

using namespace std;

void esperarHijos();
pid_t crearGeneraciones(int);
pid_t crearHijosMismoPadre(int);
void crearArbolBinario(int, int);



int main(){

	crearArbolBinario(5, 0);
	sleep(12);
	esperarHijos();
	
}



pid_t crearGeneraciones(int generaciones){
	pid_t p=0;
	for(int i=1; i<=generaciones;i++){
		if(p==0){
			p=fork();
		}
	}
	return p;
}

pid_t crearHijosMismoPadre(int hijos){
	pid_t p=1;
	for(int i=1;i<=hijos;i++){
		if(p>0){
			p=fork();
		}
	}

	return p;
}



void esperarHijos(){
	int resultado;
	pid_t pidHijo= wait(&resultado);
	while(pidHijo != -1){
		pidHijo=wait(&resultado);
	}
}

void crearArbolBinario(int niveles, int cont){
	if(niveles==1){
		return;
	}
	if(niveles==2){
		crearHijosMismoPadre(2);
		return;
	}

	if(cont<niveles-1){
		if(crearHijosMismoPadre(2)==0){
			crearArbolBinario(niveles, cont+1);
		}
	}
	
	return;
}



