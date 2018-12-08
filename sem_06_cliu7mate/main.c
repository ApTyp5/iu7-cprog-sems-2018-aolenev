#include <stdio.h>
#include <ncurses.h>

int main(void)
{
    int row, col;

    WINDOW *my_win;

    initscr();
    noecho();
    cbreak();
    refresh();

    my_win = newwin(30, 30, 10, 10);
    MEVENT event;
    mousemask(ALL_MOUSE_EVENTS, NULL);

    box(my_win, 1, 1);
    wrefresh(my_win);

    getmaxyx(my_win, row, col);
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_YELLOW);
    attron(COLOR_PAIR(1));

    printw("Hello, Anton @qwer_ty Olenev\n");
    attroff(COLOR_PAIR(1));
    wrefresh(my_win);

    int c;
    while (1)
    {
        wprintw(my_win, "kek\n");

        c = wgetch(my_win);

        if (c == KEY_MOUSE)
        {
            wprintw(my_win, "Olenev's seminars are good\n");
            if (getmouse(&event) == OK)
            {
                printw("Olenev's seminars are good\n");
            }
        }
    }

/*    raw();

    printw("Hello, ");
    attron(A_BOLD);

    printw("IU%d\n", 7);
    attroff(A_BOLD);

    mvprintw(20, 20, "BMSTU\n");

    getmaxyx(stdscr, row, col);
    mvprintw(row / 2, col / 2 - 6, "Center BMSTU\n");

    char ch;
    while (ch != 'q')
    {
        mvprintw(row - 1, col - 4, "4:20\n");
        ch = getch();
        mvprintw(10, 0, "%c", ch);
        refresh();
    }
*/
    refresh();
    getch();
    endwin();
    return 0;
}
