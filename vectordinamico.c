#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



typedef int TELEMENTO;

typedef struct {
    TELEMENTO *datos;
    unsigned long int tam;
} STVECTOR;

typedef STVECTOR *vectorD;

/*Función CreaVector: asigna memoria y devuelve la asignación al vector*/
void CreaVector(vectorD *v1, unsigned long int tam1) {

    LiberaVector(v1);
    if(tam1 <= 0){
        printf("Error al crear vector. [ El tamaño debe ser > 0 ]\n");
    }else {
    *v1 = (vectorD) malloc(sizeof (STVECTOR));
    (*v1)->datos = (TELEMENTO*) malloc(tam1 * sizeof (TELEMENTO));
    (**v1).tam = tam1;
    }
}

/*Función AsignaVector: Llena una posición del vector con un valor*/
void AsignaVector(vectorD *v1, unsigned long int posicion, TELEMENTO valor) {
    if(((*v1)->tam < posicion) || posicion < 0){
        printf("Posición errónea [ La posicion no puede exceder el tamaño del vector creado ni ser menor que 0. ]\n");
    }else{
    *( (*v1) ->datos + posicion) = valor;
    }
}


bool EsNulo(vectorD v1) {
    if (v1 == 0)
        return true;
    return false;
}

void LiberaVector(vectorD *v1) {
    if (!EsNulo(*v1)) {
        /*Primero liberamos el bloque al que apunta datos*/
        free((*v1)->datos);
        /*Y después liberamos la estructura*/
        free(*v1);
        /*Volvemos a inicializar el puntero a 0*/
        *v1=NULL;
    }
}

TELEMENTO Componentei(vectorD v1,unsigned long int posicion){
    if (!EsNulo(v1))
        if (posicion < v1->tam)
            return *(v1->datos+posicion);
}

short tamano(vectorD v1){
    return v1->tam;
}

TELEMENTO recuperar(vectorD v, unsigned long int posicion){

    if(posicion > v->tam){
        printf("La posicion no es valida.\n");
    }else{
    return v->datos[posicion];
    }
}

short longitudvector(vectorD v){

    return v->tam;
}

void NuevoVector(vectorD* v){
    *v = NULL;
}

