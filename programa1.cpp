
#include <sys/types.h> 
#include <unistd.h> 
#include <sys/wait.h>
#include <stdio.h>
#include <iostream>

using namespace std;

void esperarHijos();
pid_t crearGeneraciones(int);
pid_t crearHijosMismoPadre(int);



int main(){


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

pid_t crearArbolBinario(int niveles, int cont){
	if(niveles==1){
		return -1;
	}
	if(niveles==2){
		return crearHijosMismoPadre(2);
	}
	return p;
}


