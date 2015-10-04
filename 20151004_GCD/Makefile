# -*- coding: utf-8; tab-width: 4 -*-
# Author: Yasutaka SHINDOH / 新堂 安孝

SOURCE	:= $(wildcard *.cpp)
EXECUTE	:= sample.exe

NUMBER	:= 20000000

CXX			:= clang++
CXXFLAGS	:= -Wall -Weffc++ -O2 -D"N=(size_t)$(NUMBER)"

check: $(EXECUTE)
	# check
	./$(EXECUTE)

$(EXECUTE): $(SOURCE)
	# create: $(@F)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(SOURCE) -o $@

clean:
	# clean
	rm -f $(EXECUTE)
	find . -name '*~' -print0 | xargs -0 rm -f

.PHONY: check clean
