/*
Parameter change testing program
*/

#include <iostream>
#include <stdio.h>
#include <thread>
#include <chrono>
#include <conio.h>

#define sleep(x) std::this_thread::sleep_for(std::chrono::milliseconds(x))

using namespace std;

int main()
{

    FILE* fl = fopen("C:\\Users\\user\\Desktop\\test.txt", "r+");

    if (fl == NULL) {
        std::cout << "Ошибка открытия файла";
        exit(1);
    }
    char a;

    while (true) {
        fseek(fl, 0, 0);
        fputs("testing\n", fl);
        fflush(fl);

        sleep(300);

        if (_kbhit())
        {
            char a = _getch();
            if (a == 'q')
                return 0;
            std::cout << a + 1 << std::endl;
        }

    }

    fclose(fl);
}
