Las ventajas son que si mando un puntero a una funcion solo se esta pasando 32 o 64 bits que es lo que pesa la direccion. Por lo que luego
esa direccion puede ir a la parte de la memoria Stack y manipularla. 
Si se pasara toda la estructura se estaria haciendo una copia en un frame de la memoria Stack. La cual no solo consume memoria sino tiempo al copiarla. 
