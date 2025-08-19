typedef struct {
    int id;
    char titulo[50];
    char autor[50];
    int anio;
} Libro; // Aca queda definido la estructura para el Libro, con el límite de 50 caracteres para el título y el autor

#include <stdio.h>
#include <string.h> 
// Estas dos son librerías de C para manejar texto y otras funciones

void altaLibro(Libro libros[], int* cantidad);
void bajaLibro(Libro libros[], int* cantidad);
void modificarLibro(Libro libros[], int cantidad);
void buscarLibro(Libro libros[], int cantidad);
void mostrarLibros(Libro libros[], int cantidad);
// Aca se uso el puntero void para poder establecer como bloques de código las acciones de eliminar y agregar libros

int main() {
    Libro libros[100];
    int cantidad = 0;
    int opcion;
    // Aca ya empieza el programa y se le establece un limite de 100 libros, empieza con el libro 0 y se pone como entero la opción que el usuario tipeo

    do {
        printf("\n--- Catalogo de Libros ---\n");
        printf("1. Agregar libro\n");
        printf("2. Eliminar libro\n");
        printf("3. Modificar libro\n");
        printf("4. Buscar libro\n");
        printf("5. Mostrar todos los libros\n");
        printf("0. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        // Aca se muestran los mensajes que hay en el catalogo de libros y se guarda la opcion que el usuario escriba

        switch(opcion) {
            case 1: altaLibro(libros, &cantidad); break;
            case 2: bajaLibro(libros, &cantidad); break;
            case 3: modificarLibro(libros, cantidad); break;
            case 4: buscarLibro(libros, cantidad); break;
            case 5: mostrarLibros(libros, cantidad); break;
        } // Aca se inicia el bloque del codigo acorde a la opción elegida: 1, 2, 3, 4 o 5
    } while(opcion != 0);
    // Esto pasa mientras el usuario no eligio la opción 0 porque sino eso quiere decir que el usuario salio y termina la ejecución

    return 0;
}
void altaLibro(Libro libros[], int* cantidad) {
    printf("Ingrese ID: ");
    scanf("%d", &libros[*cantidad].id);
    getchar(); // limpiar buffer
    printf("Ingrese titulo: ");
    fgets(libros[*cantidad].titulo, 50, stdin);
    libros[*cantidad].titulo[strcspn(libros[*cantidad].titulo, "\n")] = '\0';
    printf("Ingrese autor: ");
    fgets(libros[*cantidad].autor, 50, stdin);
    libros[*cantidad].autor[strcspn(libros[*cantidad].autor, "\n")] = '\0';
    printf("Ingrese año: ");
    scanf("%d", &libros[*cantidad].anio);
    (*cantidad)++;
    // Despues de pedir la ID, título, autor y año del libro se crea uno y se lo agrega a la variable de "cantidad"

}
void bajaLibro(Libro libros[], int* cantidad) {
    int id, i, encontrado = 0;
    printf("Ingrese ID a eliminar: ");
    scanf("%d", &id);
    for(i = 0; i < *cantidad; i++) {
        if(libros[i].id == id) {
            for(int j = i; j < *cantidad - 1; j++)
                libros[j] = libros[j+1];
            (*cantidad)--;
            encontrado = 1;
            break;
        } //Pide el ID del libro a eliminar y si coinciden se lo borra y se remueve de "cantidad"
    }
    if(!encontrado) {
        printf("Libro no encontrado.\n");
        // Si no coincide el ID o el libro con una ID no existe, le pone este mensaje

    }
}
void modificarLibro(Libro libros[], int cantidad) {
    int id, i;
    printf("Ingrese ID del libro a modificar: ");
    scanf("%d", &id);
    for(i = 0; i < cantidad; i++) {
        if(libros[i].id == id) {
            getchar();
            printf("Nuevo titulo: ");
            fgets(libros[i].titulo, 50, stdin);
            libros[i].titulo[strcspn(libros[i].titulo, "\n")] = '\0';
            printf("Nuevo autor: ");
            fgets(libros[i].autor, 50, stdin);
            libros[i].autor[strcspn(libros[i].autor, "\n")] = '\0';
            printf("Nuevo año: ");
            scanf("%d", &libros[i].anio);
            return;
        } // Aca pide el ID del libro para cambiar y aparecen 3 mensajes para modificar el título, autor y año

    }
    printf("Libro no encontrado.\n");
    // Si no coincide el ID o el libro con tal ID no existe, aparece este mensaje

}
void buscarLibro(Libro libros[], int cantidad) {
    char titulo[50];
    getchar();
    printf("Ingrese titulo a buscar: ");
    fgets(titulo, 50, stdin);
    titulo[strcspn(titulo, "\n")] = '\0';
    for(int i = 0; i < cantidad; i++) {
        if(strcmp(libros[i].titulo, titulo) == 0) {
            printf("ID: %d\nTitulo: %s\nAutor: %s\nAño: %d\n",
                   libros[i].id, libros[i].titulo, libros[i].autor, libros[i].anio);
            return;
        } // Aca se pide el título del libro para buscar y si coincide se lo muestra 

    }
    printf("Libro no encontrado.\n");
    // Si no coincide el título o un libro con ese título no existe, aparece este mensaje

}
void mostrarLibros(Libro libros[], int cantidad) {
    if(cantidad == 0) {
        printf("No hay libros cargados.\n");
        return;
    } // Aca aparece el mensaje de "No hay libros cargados" si es que cantidad es igual a cero

    for(int i = 0; i < cantidad; i++) {
        printf("%d\nID: %d\nTitulo: %s\nAutor: %s\nAño: %d\n",
               libros[i].id, libros[i].titulo, libros[i].autor, libros[i].anio);
    } // Aca se muestran todos los libros registrados eSn "cantidad"
}