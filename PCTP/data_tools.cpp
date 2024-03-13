#include "data_tools.h"

using namespace std;


void print_all_data(map<string, double>& data) {
    map<string, double> ::iterator it = data.begin();

    cout << "All data value:" << endl;
    for (; it != data.end(); ++it) {
        cout << it->first << " = " << fixed << setprecision(6) << it->second << endl;
    }
}


void print_all_data_in_outfile(FILE* outfile, map<string, double> data) {
    stringstream strs;
    map<string, double> ::iterator it = data.begin();

    for (; it != data.end(); ++it) {
        strs << it->first << "=" << fixed << setprecision(6) << it->second << "\n";
    }

    fputs((char*)strs.str().c_str(), outfile);
    fflush(outfile);
}


void read_data(HANDLE handle, map<string, double>& data) {

	SetFilePointer(handle, 0, 0, FILE_BEGIN);
	int size_of_file = GetFileSize(handle, NULL);
	char* line = new char[size_of_file];

	if (!ReadFile(handle, line, size_of_file, NULL, NULL)) {
		cout << "Read Error!" << endl;
		return;
	}

	string paramName, paramValue;
	bool invalue = false;
	char chr;

	for (int i = 0; i < size_of_file; ++i) {
		chr = line[i];
		if (chr == '\n' || i == size_of_file - 1) {
			data[paramName] = atof((char*)paramValue.c_str());
			paramName = "", paramValue = "";
			invalue = false;
			continue;
		}
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
}
