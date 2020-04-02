#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


int isFileExists(const char *path)
{
	printf("THE PATH::::::%s\n", path);
    FILE *filePointer = fopen(path, "r");
    if (filePointer == NULL)
    	printf("peeeeee\n");
        return 0;
    fclose(filePointer);

    return 1;
}

int main()
{
	char filepath[150];
	printf("Enter the file path:");
	fgets(filepath, 150, stdin);
	printf("%s\n", filepath);

	if (isFileExists(filepath))
    {
        printf("FILE EXIST!\n");
    }
    else
    {
        printf("FILE NO EXIST\n");
    }
}

