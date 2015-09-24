# -*- coding: utf-8; tab-width: 4 -*-
# Author: Yasutaka SHINDOH / 新堂 安孝

SOURCE	:= $(wildcard *.cpp)
HEADER	:= $(wildcard *.hpp)
EXECUTE	:= sample.exe

CXX			:= clang++
CXXFLAGS	:= -Wall -Weffc++ -std=c++11 -DNDEBUG -O2

check: $(EXECUTE)
	# check
	@for i in `seq 1 8`; do \
		printf "<<%d>>\n" $$i; \
		./$(EXECUTE); \
	done

$(EXECUTE): $(SOURCE) $(HEADER)
	# create: $(@F)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(SOURCE) -o $@

clean:
	# clean
	rm -f $(EXECUTE)
	find . -name '*~' -print0 | xargs -0 rm -f

.PHONY: check clean
