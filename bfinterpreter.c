#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv)
{   
    char region [50000];
    for(int i = 0; i<50000; i++)
    {
        region[i] = 0;
    }
    
    char brazilianFumarole [10000];
	char* filepath = argv[1];
	printf("%s\n", filepath);
    FILE *theFilePointer = fopen(filepath, "r");

	if (theFilePointer == NULL)
    {
        printf("FILE NOT EXIST!!!\n");
        return 0;
    }

    fgets(brazilianFumarole, 10000, theFilePointer);


}

