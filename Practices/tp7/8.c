#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int z, i=0;
	float t, matriz[200];
	FILE* file = fopen("mapa.dat", "r");
	if (file == NULL)
	{
		printf("problem!\n");
		return 1;
	}
	fscanf(file, "%d %d", &z, &z);
	while(!feof(file))
	{
		fscanf(file, "%d %f %f %f %f %f %f %f %f",&z, &matriz[i], &matriz[i+1], &t, &t, &t, &t, &t, &t);
		i = i + 2;
	}
	fclose(file);
	for (int j=0; j<200; j=j+2)
		printf("%.0f\t%.1f\n", matriz[j], matriz[j+1]);
	return 0;
}
