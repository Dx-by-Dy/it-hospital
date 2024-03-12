/*
Parameter change testing program
*/

#include "lib_mac.h"
#include "data_tools.h"

using namespace std;


int main()
{
    FILE* infile = fopen("C:\\Users\\user\\Desktop\\in.txt", "r+");
    FILE* outfile = fopen("C:\\Users\\user\\Desktop\\out.txt", "w+");

    char input;
    map <string, double> data;


    if (infile == NULL || outfile == NULL) {
        cout << endl <<"Files opening error!" << endl;
        exit(1);
    }

    while (true) {
        if (check_get_data(infile, outfile, data, false)) {
            print_all_data(data);
            print_all_data_in_outfile(outfile, data);
        }

        if (_kbhit())
        {
            input = _getch();
            if (input == 'q')
                return 0;
            //std::cout << input + 1 << std::endl;
        }

        sleep(10);

    }

    fclose(infile);
    fclose(outfile);
    return 0;
}
