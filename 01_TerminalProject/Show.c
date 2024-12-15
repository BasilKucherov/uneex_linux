#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DX 2
#define DY 2
#define MAX_LINE_LENGTH 1024

void print_usage() {
    printf("Usage: show [file]\n");
    exit(1);
}

void display_page(WINDOW *win, FILE *file, const char *filename, long *file_pos) {
    werase(win);
    
    int filename_len = strlen(filename);
    mvprintw(0, (COLS - filename_len) / 2, "%s", filename);
    refresh();

    int win_height = LINES - 2*DY - 2;
    int win_width = COLS - 2*DX - 2;
    char buffer[MAX_LINE_LENGTH];

    fseek(file, *file_pos, SEEK_SET);
    
    if (fgets(buffer, MAX_LINE_LENGTH, file)) {
		*file_pos = ftell(file);
        for (int i = 0; i < win_height - 1; i++) {
            char temp[MAX_LINE_LENGTH];
            if (fgets(temp, MAX_LINE_LENGTH, file)) {
                int len = strlen(temp);
                if (len > 0 && temp[len-1] == '\n')
                    temp[len-1] = '\0';
                mvwprintw(win, i, 0, "%.*s", win_width, temp);
            }
        }
    }
    
    wrefresh(win);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage();
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        exit(1);
    }

    WINDOW *frame, *win;
    int c = 0;
    long file_pos = 0;

    initscr();
    noecho();
    cbreak();
    
    frame = newwin(LINES - 2*DY, COLS - 2*DX, DY, DX);
    box(frame, 0, 0);
    wrefresh(frame);

    win = newwin(LINES - 2*DY - 2, COLS - 2*DX - 2, DY + 1, DX + 1);
    keypad(win, TRUE);
    scrollok(win, TRUE);

    display_page(win, file, argv[1], &file_pos);

    while ((c = wgetch(win)) != 27) {
        if (c == ' ') {
            if (!feof(file)) {
                display_page(win, file, argv[1], &file_pos);
            }
        }
    }

    fclose(file);
    delwin(win);
    delwin(frame);
    endwin();
    return 0;
}