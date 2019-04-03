#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
// Signals library
#include <errno.h>
#include <signal.h>
// Sockets libraries
#include <netdb.h>
#include <sys/poll.h>
// Posix threads library
#include <pthread.h>

#define MAX_ACCOUNTS 5
#define BUFFER_SIZE 4096
#define MAX_QUEUE 5

///// FUNCTION DECLARATIONS
void readData();
void instructions(char * program);

///// MAIN FUNCTION
int main(int argc, char * argv[]){
    if(argv[1]==NULL){
        instructions(argv[0]);
    }
    readData(argv[1]);
    return 0;
}

void readData(char *filename){
    FILE *fp;
    char str[BUFFER_SIZE];
    FILE * file_ptrOut = NULL;

    long long int nodeA, nodeB;

    char * filename2 = "out.csv";
    file_ptrOut = fopen(filename2, "w");
 
    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Could not open file\n");
        return;
    }

    fgets(str, BUFFER_SIZE, fp);
    fprintf(file_ptrOut, "FromNodeId,ToNodeId\n");
    while (fgets(str, BUFFER_SIZE, fp) != NULL){
        sscanf(str, "%lld %lld\n", &nodeA, &nodeB); 
        fprintf(file_ptrOut, "%lld,%lld\n", nodeA, nodeB); 
    }
    
    fclose(fp);
    fclose(file_ptrOut);
}

void instructions(char * program){
    printf("Usage:\n");
    printf("\t%s {filename}\n", program);
    exit(EXIT_FAILURE);
}