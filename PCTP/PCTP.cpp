/*
Parameter change testing program
*/

#include "lib_mac.h"
#include "data_tools.h"
#include "file_tools.h"

using namespace std;


int main(int argc, char* argv[]){

    //написать файл логгов

    string path = get_path_dir(argv[0]);
    char input;
    map <string, double> data;

    HANDLE startfile = open_file(path + "start.txt");
    HANDLE infile = open_file(path + "params_in.txt");
    HANDLE outfile = open_file(path + "params_out.txt");

    clear_file(infile);
    clear_file(outfile);

    if (file_empty(startfile)) {
        _OVERLAPPED overlapped1 = { 0 };
        string line = "SomeParams=0.000000\ntestParams=0.000001";
        data["SomeParams"] = 0.000000;
        data["testParams"] = 0.000001;

        if (!WriteFile(startfile, line.c_str(), line.size(), 0, &overlapped1)) {
            /* create logging */
        }
    }
    else {
        read_data_from_infile(startfile, data);
    }

    while (true) {
        if (file_empty(outfile) && !file_empty(infile) && lock_both_files(infile, outfile)) {

            if (read_data_from_infile(infile, data)) {

                cout << "All data inputs:" << endl;
                print_all_data(data);
                clear_file(infile);

                if (print_data_in_outfile(outfile, data)) {
                    cout << endl << "All data puts:" << endl;
                    print_all_data(data);
                }
            }

            unlock_both_files(infile, outfile);
        }

        sleep(10);

        change_data(data);

        if (LockFile(outfile, 0, 0, MAXDWORD, MAXDWORD)) {
            print_data_in_outfile(outfile, data);
            UnlockFile(outfile, 0, 0, MAXDWORD, MAXDWORD);
        }

        if (_kbhit())
        {
            input = _getch();
            if (input == 'q')
                return 0;
        }
    }

    CloseHandle(infile);
    CloseHandle(outfile);
    CloseHandle(startfile);
    return 0;
}
