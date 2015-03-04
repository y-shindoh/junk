# -*- coding: utf-8; tab-width: 4 -*-
# Author: Yasutaka SHINDOH

CXX	?= g++
SOURCE	:= $(wildcard ./*.cpp)
EXECUTE	:= $(patsubst %.cpp,%.bin,$(SOURCE))

%.bin : %.cpp
	$(CXX) -O2 -Wall $^ -o $@

all: $(EXECUTE)

check: $(EXECUTE)
	for e in $(EXECUTE); do \
		$$e; \
	done

clean:
	rm -f $(EXECUTE)
	find . -name '*~' -print0 | xargs -0 rm -f
	for d in $(sort $(dir $(EXECUTE))); do \
		if [ -d $$d ]; then rmdir -p $$d 2>/dev/null || : 'ignore errors!'; fi \
	done

.PHONY: check
