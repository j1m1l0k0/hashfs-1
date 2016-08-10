#ifndef	__HASHFS__
#define	__HASHFS__

typedef struct {
} HashFs;

extern void	debug_init(const char * pgm, int level);
extern void	debug(int level, const char *fmt, ...);
extern void	alert(const char *fmt, ...);
extern void	error(const char *fmt, ...);
extern void	fatal(const char *fmt, ...);

#endif
