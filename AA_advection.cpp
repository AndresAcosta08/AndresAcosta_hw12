#include <iostream>

using namespace std;

//Se crea la funcion main encargada de solucionar la ecuación de advección
int main(){

//Se establecen las constantes a utilizar.
int i;
int j;
int c=1.0;
double dt=0.001;
double min=-2.0;
double max=2.0;
double dx=0.01;

int nx=((max-min)/dx);
int nt=700.0;
int p = 175;

//Se determinan los arreglos y se inicia en la posicion -2.

double *nuevo = new double[nx];
double *anterior = new double[nx];
double x=-2;

//Se establecen las condiciones de frontera.
for(i=0;i<nx;i++){
	if(x>0.5 or x<-0.5){
		anterior[i]=0;
}
	else{
		anterior[i]=0.5;
}
	cout<<"0 "<<x<<" "<<anterior[i]<<"\n";
	x=x+dx;
}

//Se desarrolla un recorrido a travez del tiempo.
for(j=1;j<=nt;j++){

//Se inicializa nuevamente el valor de x para empezar un nuevo recorrido.
double x=-2;

	for(i=1;i<nx-1;i++){
//Se incerta la ecuacion (1).
		nuevo[i] = anterior[i] - c * dt * (anterior[i]-anterior[i-1])/(dx);
} 
//Se actualiza el arreglo.
	for(i=0;i<nx;i++){
		anterior[i] = nuevo[i];
}
//Se imprimen los resultados.
	if(j%p==0){
		for(i=0;i<nx;i++){		
			cout<<j<<" "<<x<<" "<<nuevo[i]<<"\n";
			x=x+dx;
}
}
}
	return 0;
}
