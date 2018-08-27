#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void printRecords (int numRecords, char firstName[numRecords][20],char lastName[numRecords][20],int score[numRecords]);
void fNameSearch (int numRecords, char firstName[numRecords][20],char lastName[numRecords][20],int score[numRecords]);
void lNameSearch (int numRecords, char firstName[numRecords][20],char lastName[numRecords][20],int score[numRecords]);
void sortScore (int numRecords, char firstName[numRecords][20],char lastName[numRecords][20],int score[numRecords]);
void sortLName (int numRecords, char firstName[numRecords][20],char lastName[numRecords][20],int score[numRecords]);
void maxScore (int numRecords, char firstName[numRecords][20],char lastName[numRecords][20],int score[numRecords]);
void minScore (int numRecords, char firstName[numRecords][20],char lastName[numRecords][20],int score[numRecords]);
int main()
{
    int numRecords,i,menuInput=1;
    puts("Please indicate number of records you want to enter (min 5, max 15): ");
    scanf("%d",&numRecords);
    char firstName[numRecords][20];
    char lastName [numRecords][20];
    int score [numRecords];

    puts("\nPlease input records of students (enter a new line after each record), with following format:\nfirst name last name score\n");
    for (i=0; i<numRecords; i++)
    {
        scanf("%s%s%d",&firstName[i],&lastName[i],&score[i]);
    }
    for (i=0; i<numRecords; i++)
    {
        firstName[i][0]=toupper(firstName[i][0]);
        lastName[i][0]=toupper(lastName[i][0]);
    }
    while (menuInput!= 0)
    {
        printf("\n");
        puts("Print records (press 1) ");
        puts("Search by first name (press 2) ");
        puts("Search by last name (press 3) ");
        puts("Sort by score (press 4) ");
        puts("Sort by last name (press 5) ");
        puts("Find Max Score (press 6)  ");
        puts("Find Min Score (press 7) ");
        puts("Exit the program (press 0) ");
        printf("\n");
        scanf("%d",&menuInput);

        switch(menuInput)
        {

        case 1:
            printRecords(numRecords, firstName,lastName,score);
            break;

        case 2:
            fNameSearch(numRecords,firstName,lastName,score);
            break;

        case 3:
            lNameSearch(numRecords,firstName,lastName,score);
            break;

        case 4:
            sortScore(numRecords,firstName,lastName,score);
            break;

        case 5:
            sortLName(numRecords,firstName,lastName,score);
            break;

        case 6:
            maxScore(numRecords,firstName,lastName,score);
            break;
        case 7:
            minScore(numRecords,firstName,lastName,score);
            break;

        case 0:
            exit(0);
            break;
        }
    }

}

void printRecords (int numRecords, char firstName[numRecords][20],char lastName[numRecords][20],int score[numRecords])
{

    int i;
    printf("\n");
    for (i=0; i<numRecords; i++)
    {
        printf("First Name: %s, Last Name: %s, Score: %d\n", firstName[i],lastName[i],score[i]);
    }
}

void fNameSearch (int numRecords, char firstName[numRecords][20],char lastName[numRecords][20],int score[numRecords])
{

    int i;
    char test[20];
    printf("\n");
    puts("Please input the First Name of person you want to Search: ");
    scanf("%s",&test);
    test[0]=toupper(test[0]);

    for (i=0; i<numRecords; i++)
    {
        if (strcmp(firstName[i],test)==0)
        {
            printf("\nFirst Name: %s, Last Name: %s, Score: %d", firstName[i],lastName[i],score[i]);
        }


    }
    printf("\n");
}

void lNameSearch (int numRecords, char firstName[numRecords][20],char lastName[numRecords][20],int score[numRecords])
{

    int i;
    char test[20];
    printf("\n");
    puts("Please input the Last Name of person you want to Search: ");
    scanf("%s",&test);
    test[0]=toupper(test[0]);

    for (i=0; i<numRecords; i++)
    {
        if (strcmp(lastName[i],test)==0)
        {
            printf("\nFirst Name: %s, Last Name: %s, Score: %d", firstName[i],lastName[i],score[i]);
        }

    }
    printf("\n");
}

void sortScore (int numRecords, char firstName[numRecords][20],char lastName[numRecords][20],int score[numRecords])
{
    int i,j, tempScore;
    char tempFName[20], tempLName[20];

    for (i=0; i<numRecords-1; i++)
    {
        for (j=0; j<numRecords-1-i; j++)
        {
            if (score[j]>score[j+1])
            {
                tempScore=score[j];
                score[j]=score[j+1];
                score[j+1]= tempScore;

                strcpy(tempFName,firstName[j]);
                strcpy(firstName[j],firstName[j+1]);
                strcpy(firstName[j+1],tempFName);

                strcpy(tempLName,lastName[j]);
                strcpy(lastName[j],lastName[j+1]);
                strcpy(lastName[j+1],tempLName);
            }
        }
    }
    printf("\nThe records sorted in ascending order by score are:\n");
    printRecords(numRecords,firstName,lastName,score);

}

void sortLName (int numRecords, char firstName[numRecords][20],char lastName[numRecords][20],int score[numRecords])
{
    int i,j,tempScore;
    char tempLName[20], tempFName[20];

    for (i=0; i<numRecords-1; i++)
    {
        for (j=0; j<numRecords-i-1; j++)
        {
            if (strcmp(lastName[j],lastName[j+1])>0)
            {
                strcpy(tempLName,lastName[j]);
                strcpy(lastName[j],lastName[j+1]);
                strcpy(lastName[j+1],tempLName);

                tempScore=score[j];
                score[j]=score[j+1];
                score[j+1]= tempScore;

                strcpy(tempFName,firstName[j]);
                strcpy(firstName[j],firstName[j+1]);
                strcpy(firstName[j+1],tempFName);
            }
        }


    }

    printf("\nThe records sorted in ascending order by their last name are:\n");
    printRecords(numRecords,firstName,lastName,score);




}

void maxScore (int numRecords, char firstName[numRecords][20],char lastName[numRecords][20],int score[numRecords])
{
    int i,j, tempScore;
    char tempFName[20], tempLName[20];

    for (i=0; i<numRecords-1; i++)
    {
        for (j=0; j<numRecords-1-i; j++)
        {
            if (score[j]>score[j+1])
            {
                tempScore=score[j];
                score[j]=score[j+1];
                score[j+1]= tempScore;

                strcpy(tempFName,firstName[j]);
                strcpy(firstName[j],firstName[j+1]);
                strcpy(firstName[j+1],tempFName);

                strcpy(tempLName,lastName[j]);
                strcpy(lastName[j],lastName[j+1]);
                strcpy(lastName[j+1],tempLName);
            }
        }

    }
    printf("\n%s %s scored the maximum of %d\n",firstName[numRecords-1],lastName[numRecords-1],score[numRecords-1]);
}

void minScore (int numRecords, char firstName[numRecords][20],char lastName[numRecords][20],int score[numRecords])
{
    int i,j, tempScore;
    char tempFName[20], tempLName[20];

    for (i=0; i<numRecords-1; i++)
    {
        for (j=0; j<numRecords-1-i; j++)
        {
            if (score[j]>score[j+1])
            {
                tempScore=score[j];
                score[j]=score[j+1];
                score[j+1]= tempScore;

                strcpy(tempFName,firstName[j]);
                strcpy(firstName[j],firstName[j+1]);
                strcpy(firstName[j+1],tempFName);

                strcpy(tempLName,lastName[j]);
                strcpy(lastName[j],lastName[j+1]);
                strcpy(lastName[j+1],tempLName);
            }
        }

    }
    printf("\n%s %s scored the minimum of %d\n",firstName[0],lastName[0],score[0]);
}

