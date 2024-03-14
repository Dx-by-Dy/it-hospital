#include "data_tools.h"
#include "file_tools.h"

using namespace std;


void print_all_data(map<string, double>& data) {
    map<string, double> ::iterator it = data.begin();

    for (; it != data.end(); ++it) {
        cout << it->first << " = " << fixed << setprecision(6) << it->second << endl;
    }
}

void change_data(map<string, double>& data) {
	if (!data.empty())
		data[data.begin()->first] += 1;
}

char* data_in_chararr(map<string, double>& data) {
	stringstream strs;
	map<string, double> ::iterator it = data.begin();

	for (; it != data.end(); ++it) {
		strs << it->first << "=" << fixed << setprecision(6) << it->second << "\n";
	}

	const int length = strs.str().length();
	char* char_array = new char[length + 1];
	strcpy(char_array, strs.str().c_str());

	return char_array;
}

void chararr_push_in_data(char* line, int size_of_line, map<string, double>& data) {

	string paramName, paramValue;
	bool invalue = false;
	char chr;

	for (int i = 0; i <= size_of_line; ++i) {
		chr = line[i];
		if (chr == '\n' || i == size_of_line) {
			if (paramName != "")
				data[paramName] = (double)atof(paramValue.c_str());
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

bool print_data_in_outfile(HANDLE& outfile, map<string, double>& data) {
	_OVERLAPPED overlapped1 = { 0 };

	char* char_array = data_in_chararr(data);
	clear_file(outfile);

	if (!WriteFile(outfile, char_array, strlen(char_array), 0, &overlapped1)) {
		/*
		create logging
		*/
		cout << "Write Error!" << endl;
		return false;
	}

	return true;
}

bool read_data_from_infile(HANDLE& infile, map<string, double>& data, bool with_clear) {

	SetFilePointer(infile, 0, 0, FILE_BEGIN);
	int size_of_file = GetFileSize(infile, NULL);
	char* line = new char[size_of_file];

	if (!ReadFile(infile, line, size_of_file, NULL, NULL)) {
		/*
		create logging
		*/
		cout << "Read Error!" << endl;
		return false;
	}

	if (with_clear)
		data.clear();

	chararr_push_in_data(line, size_of_file, data);
	return true;
}
