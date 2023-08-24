#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct Song
{
    char name[100];
    struct Song *next;
};

struct Song *createSong(const char *name)
{
    struct Song *song = (struct Song *)malloc(sizeof(struct Song));
    strcpy(song->name, name);
    song->next = NULL;
    return song;
}

void displayPlaylist(struct Song *currentSong)
{
    struct Song *start = currentSong;

    do
    {
        printf("Song: %s\n", currentSong->name);
        currentSong = currentSong->next;
    } while (currentSong != start);
}

int main()
{
    int choice;
    struct Song *currentSong;
    struct Song *prev;
    struct Song *playlist = createSong("Song 1");
    playlist->next = createSong("Song 2");
    playlist->next->next = createSong("Song 3");
    playlist->next->next->next = playlist; // Circular link

    currentSong = playlist;

    clrscr();

    do
    {
        printf("Current Song: %s\n", currentSong->name);
        printf("Options: next = 1, prev = 2, , quit =3: ");
        scanf(" %d", &choice);

        switch (choice)
        {
        case 1:
            currentSong = currentSong->next;
            printf("Now playing: %s\n", currentSong->name);
            break;
        case 2:
            prev = currentSong;
            while (prev->next != currentSong)
            {
                prev = prev->next;
            }
            currentSong = prev;
            printf("Now playing: %s\n", currentSong->name);
            break;
        case 3:
            printf("Exiting music player...\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }

        if (choice != 3)
        {
            printf("\nPlaylist:\n");
            displayPlaylist(currentSong);
            printf("\n");
        }
    } while (choice != 3);

    getch();

    return 0;
}
