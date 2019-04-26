#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// funcion de filtro de orden 2 que filtra una señal dada
void filtroOrden2 (double t[],double Vx[],double Vy[], int numelem);

int main(void)
{
	// cantidad de elementos del archivo
	FILE* f = fopen("lockin.dat", "r");
	
	if (f == NULL)
		{
			puts("problem to open the file");
			return 1;
		}
	int elementos = 0;
	double x, y;
	
	while(fscanf(f, "%lf %lf", &x, &y) != EOF)
		elementos++;
	fclose(f);
	
	//una vez obtenidas la cantidad de elementos del archivo
	//se crearan dos vectores de la dimension de elementos contados
	double f0 = 26.0/1000.0;
	double tiempo[elementos];
	double Vx[elementos];
	double Vy[elementos];
	
	// volvemos a abrir el archivo para poner cada fila en su correspondiente vector
	//donde el tiempo se pondra en el vector tiempo[] y la tension en Vx[]
	f = fopen("lockin.dat", "r");
	if (f == NULL)
		{
			puts("problem to open the file");
			return 1;
		}
	int i = 0;
	while(fscanf(f, "%lf %lf", &tiempo[i], &Vx[i]) != EOF)
		i++;
	fclose(f);
	
	// descomponemos el valor de la tension V (representado como Vx) en sus componentes X e Y
	for (i = 0; i < elementos; i++)
	{
		Vy[i] = Vx[i]*sin(2*M_PI*f0*tiempo[i]);
		Vx[i] = Vx[i]*cos(2*M_PI*f0*tiempo[i]);
	}
	
	// filtramos y colocamos lo filtrado en un archivo llamado "datosfiltrados.dat"
	filtroOrden2(tiempo, Vx, Vy, elementos);
	
	// termina el programa
	return 0;
}

void filtroOrden2 (double t[],double Vx[],double Vy[], int numelem)
{
	// declaramos las constantes del filtro que vamos a necesitar para filtrar
	double ak[3] = {1.0, -1.98844863,0.9885149};
	double bk[3] = {1.65837562e-05, 3.31675123e-05, 1.65837562e-05};
	
	// declaramos los vectores que vamos a usar para colocar los datos filtrados de Vx y Vy
	// los primeros valores de filtrado puede ser arbitrarios a la hora del filtrar
	// por lo que se eligio el valor cero como dato arbitrario
	double xfiltrado[numelem];
	xfiltrado[0] = 0;
	xfiltrado[1] = 0;
	
	double yfiltrado[numelem];
	yfiltrado[0] = 0;
	yfiltrado[1] = 0;
	
	// aca se filtran las dos señales Vx y Vy en los vectores declarados anteriormente
	int i;
	for (i = 2; i < numelem; i++)
	{
		xfiltrado[i] = -(ak[1]*xfiltrado[i-1] + ak[2]*xfiltrado[i-2]) + bk[0]*Vx[i-0] + bk[1]*Vx[i-1] + bk[2]*Vx[i-2];
		yfiltrado[i] = -(ak[1]*yfiltrado[i-1] + ak[2]*yfiltrado[i-2]) + bk[0]*Vy[i-0] + bk[1]*Vy[i-1] + bk[2]*Vy[i-2];
	}
	
	// se declaran dos vectores los cuales se le pondran el valor de tension y angulo de las señales filtradas
	double V[numelem];
	double angulo[numelem];
	// calcula los valores de la tension y su respectivo angulo en centigrado en vez de radianes
	for (i=0; i < numelem; i++)
	{
		V[i] = 2*sqrt(xfiltrado[i]*xfiltrado[i] + yfiltrado[i]*yfiltrado[i]);
		// para no obtener errores en la division por cero se verifica que el denominador no sea cero
		if(xfiltrado[i] != 0)
			angulo[i] = atan(yfiltrado[i]/xfiltrado[i]);
		else // si el denominador es cero, atan(1/0) es 90º
			angulo[i] = M_PI/2.;
	}
	
	// creamos el archivo para colocar los datos y verificamos que no hay ningun problema
	FILE *f = fopen("datosfiltrados.dat", "w");
	if (f == NULL)
	{
		puts("problem to create the file");
		return;
	}
	// colocamos los datos calculados en el archivo en tres columnas, tiempo, voltaje, y desfase
	for ( i = 0; i < numelem; i++)
		fprintf(f, "%.2lf\t%lf\t%lf\n", t[i], V[i], (180.0/M_PI)*angulo[i]);
	fclose(f);
	// fin de la funcion
	return;
}

