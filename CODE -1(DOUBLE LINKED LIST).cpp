#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Song {
    char name[50];
    struct Song *prev, *next;
};

struct Song* head = NULL;

void addSong(char *songName) {
    struct Song *newSong = (struct Song*)malloc(sizeof(struct Song));
    strcpy(newSong->name, songName);
    newSong->prev = newSong->next = NULL;

    if (head == NULL) {
        head = newSong;
    } else {
        struct Song *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newSong;
        newSong->prev = temp;
    }

    printf("Added: %s\n", songName);
}

void playForward() {
    struct Song *temp = head;
    printf("\nPlaying songs in forward direction:\n");
    while (temp != NULL) {
        printf("%s -> ", temp->name);
        temp = temp->next;
    }
    printf("END\n");
}

void playBackward() {
    struct Song *temp = head;
    if (temp == NULL) return;

    while (temp->next != NULL)
        temp = temp->next;

    printf("\nPlaying songs in backward direction:\n");
    while (temp != NULL) {
        printf("%s -> ", temp->name);
        temp = temp->prev;
    }
    printf("START\n");
}

int main() {
    addSong("Song A");
    addSong("Song B");
    addSong("Song C");

    playForward();
    playBackward();

    return 0;
}

