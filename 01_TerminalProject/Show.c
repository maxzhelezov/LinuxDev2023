#include <curses.h>

int main(int argc, char* argv[]){
    WINDOW *win;
    int c = 0, maxy, maxx, dx = 3;

    if (argc != 2){
        fprintf(stderr, "Specify file as the second argument\n");
        return 1;
    }

    initscr();
    noecho();
    cbreak();
    printw("File: %s", argv[1]);
    refresh();

    getmaxyx(stdscr, maxy, maxx);
    win = newwin(maxy - 2*dx, maxx-2*dx, dx, dx);
    keypad(stdscr, TRUE);
    scrollok(win, TRUE);

    
    while ((c = getch()) != 27){
        refresh();
    }

    endwin();
}
