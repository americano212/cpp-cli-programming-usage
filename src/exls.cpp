#include <ncurses.h>
#include <sys/types.h>
#include <dirent.h>
#include <string>
#include <vector>

int main() {
    initscr();      // Initialize ncurses
    noecho();       // Don't echo user input
    cbreak();       // Disable line buffering (receive keys immediately)
    keypad(stdscr, TRUE); // Enable special keys like arrow keys

    clear();

    printw("Press 'q' to quit");

    // Get current directory contents
    DIR *dir;
    struct dirent *entry;

    dir = opendir(".");
    if (dir == NULL) {
        printw("Error opening directory.");
        getch();
        endwin();
        return 1;
    }

    std::vector<std::string> files;

    while ((entry = readdir(dir)) != NULL) {
        files.push_back(entry->d_name);
    }

    closedir(dir);

    // Display files and directories
    int y = 3;

    for (const std::string &file : files) {
        mvprintw(y, 1, file.c_str());
        y++;
    }

    // Main loop
    while (true) {
        int ch = getch();

        if (ch == 'q') {
            break;
        }
    }

    endwin(); // End ncurses

    return 0;
}
