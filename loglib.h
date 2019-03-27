#ifndef _LOGLIB_H
#define _LOGLIB_H

#include <stdio.h>


static char* getCurrentTime();

/*
*
* @param filename - Name of the file you work with
* @param line - line of the code
* @param fmt - string
* @return - return how many characters printed
*
*/
int flog(const char * const filename, const unsigned int line, const char *fmt, ...);
#endif // !_LOGLIB_H

