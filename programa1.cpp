
#include <sys/types.h> 
#include <unistd.h> 
#include <sys/wait.h>
#include <stdio.h>
#include <iostream>

using namespace std;

void esperarHijos();
pid_t crearGeneraciones(int);


int main(){

	crearGeneraciones(5);

	esperarHijos();
	sleep(8);
	
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

void esperarHijos(){
	int resultado;
	pid_t pidHijo= wait(&resultado);
	while(pidHijo != -1){
		pidHijo=wait(&resultado);
	}
}

