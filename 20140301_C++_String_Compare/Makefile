# -*- coding: utf-8; tab-width: 4 -*-

SOURCE		:= $(wildcard *.cpp)
EXECUTE		:= sample

CXX			?= clang++
CXXFLAGS	?= -O2 -Wall

all: $(EXECUTE)

$(EXECUTE): $(SOURCE)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $^ -o $@

check: $(EXECUTE)
	./$<

clean:
	rm -f $(EXECUTE)
	find . -name '*~' -print0 | xargs -0 rm -f

.PHONY: all check clean
