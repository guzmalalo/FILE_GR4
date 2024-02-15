
#ifndef FILE_GR4_LIBFILE_H
#define FILE_GR4_LIBFILE_H

typedef struct client{
    // data
    char name[20];
    int numCard;

    // links
    struct client * next;
} Client;

struct l{
    int n; // nombre de clients

    struct client* first;
    struct client* last;
};

typedef struct l File;

// client initialisation
Client * initClient(char * name, int numCard);

// Ajouter client
void addClient(File * fileClients, char * name, int numCard);

// print clients
void printClients(File * fileClients);

//  pick HEAD
Client* pickClient(File* fileClients);

// free file
void freeFile(File * fileClients);

// using peakClient
void freeFileV2(File * fileClients);


#endif
