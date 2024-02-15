#include <stdio.h>
#include <stdlib.h>
#include "libFile.h"

int main() {
    // allocation automatique
    // initialisation
    File fileClients = {0, NULL, NULL};
    Client * temp = NULL;

    addClient(&fileClients, "Anna", 123);
    addClient(&fileClients, "Teo", 1231);
    addClient(&fileClients, "Tony", 122);

    printClients(&fileClients);
    printf("Nombre de clients = %d\n", fileClients.n);

    // on piioche un client
    temp = pickClient(&fileClients);

    printClients(&fileClients);
    printf("Nombre de clients = %d\n", fileClients.n);

    freeFileV2(&fileClients);
    free(temp);

    printClients(&fileClients);

    return 0;
}
