#pragma once
#include "lib_mac.h"

void print_all_data(std::map<std::string, double>& data);

void chararr_push_in_data(char* line, int size_of_line, std::map<std::string, double>& data);

void change_data(std::map<std::string, double>& data);

bool read_data_from_infile(HANDLE& infile, std::map<std::string, double>& data, bool with_clear = true);

bool print_data_in_outfile(HANDLE& outfile, std::map<std::string, double>& data);

char* data_in_chararr(std::map<std::string, double>& data);