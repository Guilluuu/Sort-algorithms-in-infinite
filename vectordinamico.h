#ifndef VECTORDINAMICO_H
#define VECTORDINAMICO_H

typedef int TELEMENTO; /*Tipo de datos del vector*/
typedef void * vectorD; /*tipo opaco*/

/*Funciones exportadas*/
/*Función CreaVector: asigna memoria y devuelve la asignación al vector*/
void CreaVector(vectorD *v1,unsigned long int tam1);
/*Función AsignaVector: Llena una posición del vector con un valor*/
void AsignaVector(vectorD *v1,unsigned long int posicion,TELEMENTO valor);
/* Imrpime los elementos del vector que se le pasan*/
#endif /*VECTORDINAMICO_H*/

/*Si el vector "v1" es nulo devuelve true, en otro caso devuelve falso*/
int EsNulo(vectorD v1);
/*Libera los datos del vector, el propio vector y lo inicializa a NULL */
void LiberaVector(vectorD *v1);
/*La función devuelve el elemento del vector "v" que se encuentra en la posición "posición"*/
TELEMENTO recuperar(vectorD v, unsigned long int posicion);
/*Guarda la longitud del vector*/
short longitudvector(vectorD v);
/*Inicializa el vector "v" a NULL*/
void NuevoVector(vectorD* v);

TELEMENTO Componentei(vectorD v1,unsigned long int posicion);