#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <alloca.h>

#include "hashfs.h"

static struct {
  	int		level;
  	const char *	program;
	FILE *		fp;
} DEBUG_MODULE = { 2, "unknown" };

void debug_init(const char *program, int level)
{
	char filename[64];

  	DEBUG_MODULE.level = level;
	DEBUG_MODULE.program = program;

	strcpy(filename, "/tmp/");
	strcat(filename, program);
	strcat(filename, ".log");
	DEBUG_MODULE.fp = fopen(filename, "w");
}

static void debug_log(const char *label, const char *msg)
{
	fprintf(DEBUG_MODULE.fp, "%s %s: %s\n", DEBUG_MODULE.program, label, msg);
	fflush(DEBUG_MODULE.fp);
}


void debug(int level, const char *fmt, ...)
{
	if (DEBUG_MODULE.level > level)
	{
		char * bp = alloca(1024);

		va_list argp;

		va_start(argp, fmt);
		vsprintf(bp, fmt, argp);
		va_end(argp);

		debug_log("debug", bp);
	}
}

void alert(const char *fmt, ...)
{
	char * bp = alloca(1024);

	va_list argp;

	va_start(argp, fmt);
	vsprintf(bp, fmt, argp);
	va_end(argp);

	debug_log("alert", bp);
}

void error(const char *fmt, ...)
{
	char * bp = alloca(1024);

	va_list argp;

	va_start(argp, fmt);
	vsprintf(bp, fmt, argp);
	va_end(argp);

	debug_log("error", bp);
}

void fatal(const char *fmt, ...)
{
	char * bp = alloca(1024);

	va_list argp;

	va_start(argp, fmt);
	vsprintf(bp, fmt, argp);
	va_end(argp);

	debug_log("error", bp);

  	exit(1);
}
