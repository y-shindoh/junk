# -*- tab-width: 4 -*-

SOURCE	:= $(sort $(wildcard *.cpp))
EXECUTE	:= sample

CXX			:= clang++
CXXFLAGS	:= -Wall -std=c++98 -O2

check: $(EXECUTE)
	# execute: $(notdir $<)
	./$<

$(EXECUTE) : $(SOURCE)
	# create: $@
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(EXECUTE)
	find . -name '*~' -print0 | xargs -0 rm -f

.PHONY: check clean
