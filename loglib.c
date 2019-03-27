#define _CRT_SECURE_NO_WARNINGS
#include "loglib.h"
#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

FILE *filePointer;

int SESSION_TRACKER; // Keeps track of session

static char* getCurrentTime()
{
	char *buf = NULL;
	int size = 0;

	time_t currentTime = time(NULL); /* get current calendar time */

	char *timestr = asctime(localtime(&currentTime));
	timestr[strlen(timestr) - 1] = 0;  //Getting rid of \n

	size = strlen(timestr) + 1 + 2; //Additional +2 for square braces
	buf = (char*)malloc(size);

	memset(buf, 0x0, size);
	snprintf(buf, size, "%s", timestr);

	return buf;
}

int flog(const char * const filename, const unsigned int line, const char *const format, ...)
{

	if (SESSION_TRACKER > 0) {

		filePointer = fopen("log.txt", "a+");
		if (filePointer == NULL) {

			return 0;
		}
	}
	else {

		filePointer = fopen("log.txt", "w");
		if (filePointer == NULL) {

			return 0;
		}
	}

	fprintf(filePointer, "[%s] ", getCurrentTime());
	fprintf(filePointer, "[%s][line: %d] ", filename, line);

	va_list argptr;
	va_start(argptr, format);

	int done = vfprintf(filePointer, format, argptr);

	va_end(argptr);

	SESSION_TRACKER++;

	fclose(filePointer);

	return done;
}
