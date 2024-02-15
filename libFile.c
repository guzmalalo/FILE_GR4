#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libFile.h"

// Init client
Client * initClient(char * name, int numCard){
    // Dynamic allocation
    Client * newClient = (Client *) malloc(sizeof(Client));

    // Initialisation data
    newClient->numCard = numCard;
    strcpy(newClient->name,name);

    // Initialisation
    newClient->next= NULL;

    return newClient;
}

// Add client
void addClient(File * fileClients, char * name, int numCard){

    Client * newClient = initClient(name, numCard);

    if (fileClients->first ==NULL || fileClients->last==NULL){
        // if we have no clients yet
        fileClients->first = newClient;
        fileClients->last = newClient;
    }else{
        // if we have at least one client
        fileClients->last->next = newClient;
        fileClients->last = newClient;
    }

    fileClients->n++;

}

void printClients(File * fileClients){

    if (fileClients->first==NULL){
        printf("List is Empty\n");
        return;
    }

    Client * current = fileClients->first;

    printf("First\n");
    while (current!=NULL){
        printf("Client : %s , n : %d\n", current->name, current->numCard);
        current = current->next;
    }
    printf("Last\n");

}


void freeFile(File * fileClients){
    Client * toDelete = NULL;
    if(fileClients->first==NULL){
        // if we have no clients
        return;
    }

    while (fileClients->first!=NULL){
        toDelete = fileClients->first;
        fileClients->first = fileClients->first->next;
        free(toDelete);
    }

    fileClients->first =NULL;
    fileClients->last= NULL;

}

Client* pickClient(File* fileClients){
    if(fileClients->first==NULL){
        return NULL;
    }

    Client * temp = fileClients->first;
    fileClients->first = temp->next;
    temp->next = NULL;

    if(fileClients->first==NULL){
        // list is empty
        fileClients->last= NULL;
    }

    fileClients->n--;

    return temp;

}


void freeFileV2(File * fileClients){
    while(fileClients->first!=NULL){
        free(pickClient(fileClients));
    }
}

