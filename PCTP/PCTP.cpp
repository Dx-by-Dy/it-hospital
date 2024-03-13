/*
Parameter change testing program
*/

#include "lib_mac.h"
#include "data_tools.h"
#include "file_tools.h"

using namespace std;


int main()
{

    //создать функцию открытия файлов по путям и менам
    //создать функцию блокировки файлов

    HANDLE infile = CreateFileA("C:\\Users\\user\\Desktop\\in.txt",
                                GENERIC_READ | GENERIC_WRITE,
                                FILE_SHARE_READ | FILE_SHARE_WRITE,
                                NULL,
                                OPEN_ALWAYS,
                                FILE_ATTRIBUTE_NORMAL,
                                NULL);

    if (infile == INVALID_HANDLE_VALUE) {
        cout << "infile opening error\n";
        exit(1);
    }

    HANDLE outfile = CreateFileA("C:\\Users\\user\\Desktop\\out.txt",
                                GENERIC_READ | GENERIC_WRITE,
                                FILE_SHARE_READ | FILE_SHARE_WRITE,
                                NULL,
                                OPEN_ALWAYS,
                                FILE_ATTRIBUTE_NORMAL,
                                NULL);

    if (infile == INVALID_HANDLE_VALUE) {
        cout << "outfile opening error\n";
        exit(1);
    }

    char input;
    map <string, double> data;

    while (true) {
        if (file_empty(outfile) && !file_empty(infile)) {
            read_data(infile, data);
            print_all_data(data);
            clear_file(infile);
            //print_all_data_in_outfile(outfile, data);
        }

        if (_kbhit())
        {
            input = _getch();
            if (input == 'q')
                return 0;
        }

        sleep(300);
    }

    CloseHandle(infile);
    CloseHandle(outfile);
    return 0;
}
