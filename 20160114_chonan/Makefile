# -*- coding: utf-8; tab-width: 4 -*-
# Author: Yasutaka SHINDOH / 新堂 安孝

SOURCE	:= $(wildcard *.cpp)
EXECUTE	:= sample.exe

CXX			:= clang++
CXXFLAGS	:= -Wall -Weffc++ -O2

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
