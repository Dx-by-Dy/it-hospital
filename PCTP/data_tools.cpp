#include "data_tools.h"

using namespace std;


void print_all_data(map<string, double> data) {
    map<string, double> ::iterator it = data.begin();

    cout << "All data value:" << endl;
    for (; it != data.end(); ++it) {
        cout << it->first << " = " << it->second << endl;
    }
}


void print_all_data_in_outfile(FILE* outfile, map<string, double> data) {
    stringstream strs;
    map<string, double> ::iterator it = data.begin();

    for (; it != data.end(); ++it) {
        strs << it->first << "=" << fixed << setprecision(6) << it->second + 1 << "\n";
    }

    fputs((char*)strs.str().c_str(), outfile);
    fflush(outfile);
}


bool check_get_data(FILE* infile, FILE* outfile, map<string, double> data, bool with_clear) {
    if (getc(infile) != EOF && getc(outfile) == EOF) {
        fseek(infile, 0, 0);
        fseek(outfile, 0, 0);
        char line[256];

        if (with_clear)
            data.clear();

        while (fgets(line, sizeof(line), infile)) {
            string paramName, paramValue;
            bool invalue = false;
            for (auto chr : line) {
                if (chr == '=') {
                    invalue = true;
                    continue;
                }
                if (chr == ' ')
                    continue;
                if (invalue)
                    paramValue.push_back(chr);
                else
                    paramName.push_back(chr);
            }

            data[paramName] = atof((char*)paramValue.c_str());
        }

        fclose(infile);
        infile = fopen("C:\\Users\\user\\Desktop\\in.txt", "w+");

        return true;
    }

    return false;
}
