# -*- coding: utf-8; tab-width: 4 -*-
# Author: Yasutaka SHINDOH / 新堂 安孝

SOURCE	:= $(wildcard *.cpp)
EXECUTE	:= $(patsubst %.cpp,%.exe,$(SOURCE))

CXX			:= clang++
CXXFLAGS	:= -Wall -Weffc++ -O2 -std=c++11

%.exe : %.cpp $(wildcard *.hpp)
	# create: $@
	$(CXX) $(CXXFLAGS) $< -o $@

check: $(EXECUTE)
	@for e in $^ ; do \
		if [ -e $${e} ]; then \
			printf "# execute: $${e}\n"; \
			./$${e}; \
		fi \
	done

all: $(EXECUTE)

clean:
	rm -f $(EXECUTE)
	find . -name '*~' -print0 | xargs -0 rm -f

.PHONY: check all clean
