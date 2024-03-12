#pragma once
#include "lib_mac.h"

void print_all_data(std::map<std::string, double> data);

void print_all_data_in_outfile(FILE* outfile, std::map<std::string, double> data);

bool check_get_data(FILE* infile, FILE* outfile, std::map<std::string, double> data, bool with_clear);