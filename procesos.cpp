
#include <sys/types.h> 
#include <unistd.h> 
#include <sys/wait.h>
//librerias necesarias para fork y wait
#include <stdio.h>

void esperarHijos();
pid_t crearGeneraciones(int);
pid_t crearHijosMismoPadre(int);
void crearArbolBinario(int, int);

int main(){

	//Menu-------------------------------------------------------------------------------------

	int eleccion;

	printf("--------------------------------\n");
	printf("Seleccione una opcion\n");
	printf("\t1 Abanico de procesos\n");
	printf("\t2 Lista de procesos cada uno con un descendiente\n");
	printf("\t3 Arbol binario de procesos\n\n\t");
	
	scanf("%d", &eleccion);
	int e;
	switch(eleccion){
		case 1:

			printf("\n¿Cuantos hijos desea que tenga el abanico?\n");
			scanf("%d", &e);
			printf("\n Creando abanico...\nen otra terminal use el comando ps lf\n\n");
			crearHijosMismoPadre(e);
			break;

		case 2:
			printf("\n¿Cuantos elemetos desea que tenga la lista de procesos?\n");
			scanf("%d", &e);
			printf("\n creado lista...\nen otra terminal use el comando ps lf\n\n");
			crearGeneraciones(e);
			break;

		case 3:
			printf("\n¿Cuantos niveles desea que tenga el arbol binario ?\n");
			scanf("%d", &e);
			printf("\n creado arbol...\nen otra terminal use el comando ps lf\n\n");				
			crearArbolBinario(e, 0);
			break;
	}
	//-----------------------------------------------------------------------------------------------
	sleep(10);
	esperarHijos();	
}


pid_t crearGeneraciones(int generaciones){
	//Crea cadenas de procesos, mediante hijos
	pid_t p=0;
	for(int i=1; i<generaciones;i++){
		if(p==0){
			p=fork();
		}
	}
	return p;
}

pid_t crearHijosMismoPadre(int hijos){
	//Crea abanico de procesos
	pid_t p=1;
	for(int i=1;i<=hijos;i++){
		if(p>0){
			p=fork();
		}
	}
	return p;
}

void crearArbolBinario(int niveles, int cont){
	//Crea arbol binario de procesos con n niveles
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

void esperarHijos(){
	//espera a todos sus hijos
	int resultado;
	pid_t pidHijo= wait(&resultado);
	while(pidHijo != -1){
		pidHijo=wait(&resultado);
	}
}




