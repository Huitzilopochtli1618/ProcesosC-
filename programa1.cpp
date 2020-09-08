
#include <sys/types.h> 
#include <unistd.h> 
#include <sys/wait.h>
#include <stdio.h>
#include <iostream>

using namespace std;

void esperarHijos();
pid_t crearGeneraciones(int);


int main(){


	
}



pid_t crearGeneraciones(int generaciones){
	pid_t p=1;
	for(int i=1; i<=generaciones;i++){
		p=fork();
	}
	return p;
}

