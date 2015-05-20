# -*- coding: utf-8; tab-width: 4 -*-

SOURCE	:= $(wildcard *.c)
EXECUTE	:= sample

CC		:= clang
CFLAGS	:= -Wall -std=c99

check: $(EXECUTE)
	# check
	./$(EXECUTE)

$(EXECUTE): $(SOURCE)
	# create: $(@F)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	# clean
	rm -f $(EXECUTE)
	find . -name '*~' -print0 | xargs -0 rm -f

.PHONY: check clean
