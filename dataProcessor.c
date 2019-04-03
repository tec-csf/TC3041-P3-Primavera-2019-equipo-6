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

///// MAIN FUNCTION
int main(int argc, char * argv[])
{
    readData(argv[1]);
}

void readData(char *filename)
{
    FILE *fp;
    char str[BUFFER_SIZE];

    FILE * file_ptrOut = NULL;
    char buffer[BUFFER_SIZE];

    long long int nodeA, nodeB;

    char * filename2 = "out.csv";
    file_ptrOut = fopen(filename2, "w");
 
    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Could not open file %s",filename);
        return;
    }

    fprintf(file_ptrOut, "FromNodeId,ToNodeId\n");
    while (fgets(str, BUFFER_SIZE, fp) != NULL)
    {
        sscanf(buffer, "%lld %lld\n", &nodeA, &nodeB); 
        fprintf(file_ptrOut, "%lld,%lld\n", nodeA, nodeB); 
    }
    
    fclose(fp);
    fclose(file_ptrOut);
}