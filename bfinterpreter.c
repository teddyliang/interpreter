#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define regionLength 50000
#define codeLength 10000
#define ascii 176

struct tuple
{
    int index;
    int letter;
};

void left(struct tuple *tuplePointer)
{  
    //printf("In left\n");
    if(tuplePointer->index!=0)
    {
        tuplePointer->index = tuplePointer->index-1;
    }
    //say the error
    else
    {
        printf("Tried to go left when at the first index\n");
        exit(0);
    }
}

void right(struct tuple *tuplePointer)
{
    //printf("In right\n");
    if(tuplePointer->index<regionLength)
    {
        tuplePointer->index = tuplePointer->index+1;
    }

    //say the error
    else
    {
        printf("Tried to go right when at the end of the region\n");
        exit(0);
    }

   
}

void plus(struct tuple *tuplePointer, int region[])
{
    if(region[tuplePointer->index] < 256)
    {
        region[tuplePointer->index] += 1;
    }
    else
    {
        region[tuplePointer->index] = 0;
    }
}

void minus(struct tuple *tuplePointer, int region[])
{

    if(region[tuplePointer->index] > 0)
    {
        region[tuplePointer->index] -= 1;
    }
    else
    {
        region[tuplePointer->index] = 255;
    }
}

void star(struct tuple *tuplePointer, int region[])
{
    printf("In star\n");
    printf("%c", (char)(region[tuplePointer->index]));
}
void executeCommand(struct tuple *tuplePointer, int region[], char brazilianFumarole[]);


void open(struct tuple *tuplePointer, int region[], char brazilianFumarole[])
{
    printf("In open\n");
    const int letterStart = tuplePointer->letter;
    while(region[tuplePointer->index] != 0)
    {
        tuplePointer->letter++;
        char command [2];
        command[0] = brazilianFumarole[tuplePointer->letter];
        command[1] = '\0';
        while(strcmp(command, ")") != 0)
        {
            printf("Command:%c, thingy: %d\n", command[0], strcmp(command, ")"));
            executeCommand(tuplePointer, region, brazilianFumarole);
            tuplePointer->letter++;
            command[0] = (char) brazilianFumarole[tuplePointer->letter];
        }
        tuplePointer->letter = letterStart;
    }
    char command [2];
    command[0] = brazilianFumarole[tuplePointer->letter];
    command[1] = '\0';
    while(strcmp(command, ")") != 0)
    {
        tuplePointer->letter++;
        command[0] = (char) brazilianFumarole[tuplePointer->letter];
    }
}

void executeCommand(struct tuple *tuplePointer, int region[], char brazilianFumarole[])
{
    //printf("region index:%d,  region value:%d, code letter: %d\n", tuplePointer->index, region[tuplePointer->index], tuplePointer->letter);
    char command = (char) brazilianFumarole[tuplePointer->letter];
    //printf("executeCommand %c\n", command);
    if(strcmp(&command, "<") == ascii)
    {
        left(tuplePointer);
    }
    else if(strcmp(&command, ">") == ascii)
    {
        right(tuplePointer);
    }
    else if(strcmp(&command, "+") == ascii)
    {
        plus(tuplePointer, region);
    }
    else if(strcmp(&command, "-") == ascii)
    {
        minus(tuplePointer, region);
    }
    else if(strcmp(&command, "*") == ascii)
    {
        star(tuplePointer, region);
    }
    else if(strcmp(&command, "(") == ascii)
    {
        open(tuplePointer, region, brazilianFumarole);
    }
    else if (strcmp(&command, ")") == ascii)
    {
        printf("uneven/mismatched parentheses\n");
        exit(0);
    }
    // else if(tuplePointer->letter == 10)
    // {
    //     exit(0);
    // }
}

int main(int argc, char** argv)
{  
    int region [regionLength];
    for(int i = 0; i<regionLength; i++)
    {
        region[i] = 0;
    }

    char brazilianFumarole [codeLength];
    char* filepath = argv[1];
    //printf("%s\n", filepath);
    FILE *theFilePointer = fopen(filepath, "r");

    if (theFilePointer == NULL)
    {
        printf("FILE NOT EXIST!!!\n");
        return 0;
    }

    fgets(brazilianFumarole, codeLength, theFilePointer);
    for(int i=0; i<codeLength; i++)
    {
        printf("%c", brazilianFumarole[i]);
    }
    int index = 0;
    int letter = 0;

    struct tuple myTuple;
    myTuple.index = index;
    myTuple.letter = letter;

    struct tuple *tuplePointer = &myTuple;

    while(myTuple.letter < codeLength)
    {
        executeCommand(tuplePointer, region, brazilianFumarole);
        //printf("%d\n", letter);
        myTuple.letter++;
    }

}