#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool WaitForEnter()
{
    printf("Press enter to continue: ");
    while(getchar() != '\n');
    getchar();
    return true;
}

void BackToMenu()
{
    system("clear");
    return;
}

char DrawMenu()
{
    char option;

    printf("1. Add note \n");
    printf("2. Show notes \n");
    printf("3. Exit \n");
    scanf(" %c", &option);

    return option;
}

void AddNote()
{
    system("clear");

    char note[256];

    FILE *file = fopen("mynotes.txt", "a");

    if(file == NULL)
    {
       printf("Error, problem with the file"); 
       BackToMenu();
    }
    
    printf("Write your note (max 255 chars): \n");

    getchar();
    fgets(note, sizeof(note), stdin);

    printf("\n");
    fprintf(file, "%s\n", note);
    fprintf(file, "------\n");

    printf("Note has been added\n\n");
    fclose(file);

    if(WaitForEnter())
    {
        BackToMenu();
    }
}

void ShowNotes()
{
    system("clear");

    char note[256];
    FILE *file = fopen("mynotes.txt", "r");

    if(file == NULL)
    {
        printf("Error! No notes found.\n");
        BackToMenu();
        return;
    }

    system("clear");

    printf("--YOUR NOTES--\n");
    printf("\n\n");

    while(fgets(note, sizeof(note), file) != NULL)
    {
        printf("%s", note);
    }

    fclose(file);

    if(WaitForEnter())
    {
        BackToMenu();
    }
    
}

void Exit()
{
    system("clear");
    printf("Bye, bye!\n");
    exit(0);
}

int main()
{

    while(true)
    {
        char option = DrawMenu();

        switch(option)
        {
            case '1':
                AddNote();
                break;

            case '2':
                ShowNotes();
                break;

            case '3':
                Exit();

            default:
                printf("There is no such option like %c. \n", option);

                if(WaitForEnter())
                {
                    BackToMenu();
                }

                break;
        }
    }
    return 0;
}