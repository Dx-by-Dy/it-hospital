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

    FILE* fl = fopen("C:\\Users\\user\\Desktop\\test.txt", "a+t");

    if (fl == NULL) {
        std::cout << "Ошибка открытия файла";
        exit(1);
    }
    char a;

    while (true) {
        //fflush(fl);
        //fputs("test\n", fl);
        //fflush(fl);

        if (!feof(fl)) {
            /*
            char line[100];
            while (fgets(line, 100, fl)) {
                printf("%s", line);
            }
            */

            char line[100];
            //fscanf(fl, "%s", line);

            
            while (fgets(line, sizeof(line), fl)) {

                cout << line;

                //fseek(fl, 0, SEEK_CUR - 1);
                //fseek(fl, 0, SEEK_CUR + 2);
            }

            fl = fopen("C:\\Users\\user\\Desktop\\test.txt", "w+");
            
            //fseek(fl, 0, SEEK_SET);
            //fgets(line, sizeof(line), fl);
            //cout << line;
            //int d = atoi(line);

            //for (auto chr : line) {
            //    cout << (wchar_t)chr;
            //}

            //fseek(fl, 0, SEEK_SET);
            //fputs("t", fl);

            //std::cout << line << endl;
            //fputs(" ", fl);
        }

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
