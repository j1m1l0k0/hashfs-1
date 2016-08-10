#/usr/bin/make -f
#
#
OBJECT-DIR	= Gen

SRCS		= $(shell find *.c)
OBJS		= $(SRCS:%.c=$(OBJECT-DIR)/%.o)

CDEFINE-FLAGS	= _FILE_OFFSET_BITS=64
CDEBUG-FLAGS	= -g
CFLAGS		= $(CDEBUG-FLAGS) $(CDEFINE-FLAGS:%=-D%)
LDFLAGS		=
LIBS		= -lfuse

PROGRAM		= hashfs

$(OBJECT-DIR)/$(PROGRAM): $(OBJS)
	@mkdir -p $(@D)
	$(CC) -o $@ $(LDFLAGS) $(OBJS) $(LIBS)


$(OBJECT-DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) -c -o $@ $(CFLAGS) $< 

clean::
	@if [ -d $(OBJECT-DIR) ] ; then  set -x ; rm -rf "$(OBJECT-DIR)" ; fi;
	@find * \( -name *\# -o -name *\\~ \) | xargs -i sh -cx "rm -f {}"
