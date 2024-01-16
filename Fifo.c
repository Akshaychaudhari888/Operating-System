//Fifo page replacement
#include<stdio.h>
int main() {
    int no_of_frames, no_of_pages, frames[10], pages[30], front = 0, rear = 0, faults = 0;
    printf("Enter number of frames: ");
    scanf("%d", &no_of_frames);

    printf("Enter total number of pages: ");
    scanf("%d", &no_of_pages);

    printf("Enter page reference string: ");
    for (int i = 0; i < no_of_pages; ++i) {
        scanf("%d", &pages[i]);
    }

    for (int i = 0; i < no_of_frames; ++i) {
        frames[i] = -1;
    }

    for (int i = 0; i < no_of_pages; ++i) {
        int page = pages[i];
        int pageFound = 0;

        // Check if page is already in frame
        for (int j = 0; j < no_of_frames; ++j) {
            if (frames[j] == page) {
                pageFound = 1;
                break;
            }
        }

        // If page is not in frame, perform FIFO replacement
        if (pageFound == 0) {
            if (rear < no_of_frames) {
                frames[rear++] = page;
            } else {
                frames[front++] = page;
                front %= no_of_frames;
            }
            faults++;
        }

        // Display the current state of frames
        printf("\n");
        for (int j = 0; j < no_of_frames; ++j) {
            printf("%d\t", frames[j]);
        }
    }

    printf("\n\nTotal Page Faults = %d", faults);
    return 0;
}
