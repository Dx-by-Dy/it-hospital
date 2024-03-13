#include "file_tools.h"

bool file_empty(HANDLE handle) {
	return !GetFileSize(handle, NULL);
}

void clear_file(HANDLE& handle) {
	SetFilePointer(handle, 0, 0, FILE_BEGIN);
	SetEndOfFile(handle);
} 