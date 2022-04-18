/*
Module: fileStruct.c
Function:
        To create and manage a Bank Account.
Copyright notice:
        This file copyright (C) 2022 by
        MCCI Corporation
        3520 Krums Corners Road
        Ithaca, NY 14850
        An unpublished work. All rights reserved.
        This file is proprietary information, and may not be disclosed or
        copied without the prior permission of MCCI Corporation.
Author:
        Pranau R, MCCI Corporation   April 2022
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

struct info
    {
    char name[20];
    char profession[20];
    };

/****************************************************************************\
|
|   Main Function.
|
\****************************************************************************/

/*
Name: main()
Function:
        To write and read structure to a file.
Definition:
        int main (void);
Returns:
        Functions returning type int: return an integer.
*/

int main()
    {
    int ch;
    FILE *fp;
    struct info person;

    printf("\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("This is fileStruct.exe v1.0.0\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("\n");
    printf("It can able store a data from file to structure and from structure to file\n\n");

    printf("1. Write a File: \n");
    printf("2. Read a file: \n");
    printf("3. Exit \n");

    printf("\nEnter the Choice: \n");
    scanf("%d", &ch);

    switch (ch)
        {
        case 1:
            {
            fp = fopen ("information.txt", "wb");

            if (fp == NULL)
                {
                printf("The cannot be open\n\n");
                }

                printf("Enter Name: \n");
                scanf("%s", person.name);

                printf("Enter Profession: \n");
                scanf("%s", person.profession);

                fwrite (&person, sizeof(struct info), 1, fp);

            if (fwrite != 0)
                {
                printf("File written successfully!\n\n");
                }
            else
                {
                printf("Error!!\n");
                }

            fclose (fp);

            printf("\n\nPress any key to close the program...\n\n");
            getch();
            }
        case 2:
            {
            fp = fopen ("information.txt", "rb");

            if (fp == NULL)
                {
                printf("Error opening the file!\n\n");
                }
        
            while(fread(&person, sizeof(struct info), 1, fp))
                {
                printf ("Name = %s\n", person.name);
                printf ("Profession = %s\n", person.profession);
                }

            fclose (fp);

            printf("\n\nPress any key to close the program...\n\n");
            getch();
            }
        case 3:
            {
            return 0;
            }
        default:
            {
            printf("Invalid Entry!!\n");
            }
        }
    return 0;
    }