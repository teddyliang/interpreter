#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char** argv)
{
    char brazilianFumarole [10000];
	char* filepath = argv[1];
	//printf("Enter the file path:");
	//fgets(filepath, 200, stdin);
	printf("%s\n", filepath);
    FILE *theFilePointer = fopen(filepath, "r");

	if (theFilePointer == NULL)
    {
        printf("FILE NOT EXIST!!!\n");
        return 0;
    }

    fgets(brazilianFumarole, 10000, theFilePointer);


}

