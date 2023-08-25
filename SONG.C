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
    int choice, n, i;
    char ch[10];
	struct Song *currentSong;
	struct Song *prev;
	struct Song *playlist=createSong("1");
	clrscr();
	printf("Total no. of songs : ");
	scanf("%d",&n);

	currentSong = playlist;
	for(i=1; i<n; i++){
		itoa(i+1,ch,10);
		playlist->next = createSong(ch);
		playlist= playlist->next;
	}
	playlist->next=currentSong;


    do
    {
	printf("Current Song: %s\n\n", currentSong->name);
	printf("Controls : next = 1, prev = 2, , exit = 0 : ");
	scanf(" %d", &choice);
	clrscr();

        switch (choice)
        {
        case 1:
            currentSong = currentSong->next;
	    printf("Now playing: Track %s\n", currentSong->name);
            break;
        case 2:
            prev = currentSong;
            while (prev->next != currentSong)
            {
                prev = prev->next;
            }
            currentSong = prev;
	    printf("Now playing: Track %s\n", currentSong->name);
            break;
	case 0:
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
    } while (choice != 0);

    getch();

    return 0;
}
