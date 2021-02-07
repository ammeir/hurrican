
#ifndef DEBUG_H
#define DEBUG_H

//#include <cstdio>

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>     /* va_list, va_start, va_arg, va_end */


#ifdef PSV_DEBUG_CODE
static void PSV_DEBUG(const char* str, ...) {
	va_list list;
	char buf[512];

	va_start(list, str);
	vsprintf(buf, str, list);
	va_end(list);

	FILE *fp = fopen("ux0:data/trace1.log", "a+"); // Linux
	
	if (fp != NULL){
		fprintf(fp, buf);
		fprintf(fp, "\x0D\x0A"); // new line
		fclose(fp);
	}
}
#else
static void PSV_DEBUG(const char* str, ...) {}
#endif



#endif