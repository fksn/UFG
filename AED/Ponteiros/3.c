#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    printf("%s de ", argv[1]);
    if (strcmp( argv[2],"01") == 0) printf("janeiro");
    else if (strcmp( argv[2],"02") == 0) printf("fevereiro");
    else if (strcmp( argv[2],"03") == 0) printf("março");
    else if (strcmp( argv[2],"04") == 0) printf("abril");
    else if (strcmp( argv[2],"05") == 0) printf("maio");
    else if (strcmp( argv[2],"06") == 0) printf("junho");
    else if (strcmp( argv[2],"07") == 0) printf("julho");
    else if (strcmp( argv[2],"08") == 0) printf("agosto");
    else if (strcmp( argv[2],"09") == 0) printf("setembro");
    else if (strcmp( argv[2],"10") == 0) printf("outubro");
    else if (strcmp( argv[2],"11") == 0) printf("novembro");
    else if (strcmp( argv[2],"12") == 0) printf("dezembro");
    printf(" de %s\n", argv[3]);
    
}