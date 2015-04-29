# -*- coding: utf-8; tab-width: 4 -*-

CXX			:= clang++
CXXFLAGS	:= -Wall

SOURCE		:= $(wildcard *.cpp)
EXECUTE		:= sample

check: $(EXECUTE)
	./$(EXECUTE)

$(EXECUTE): $(SOURCE)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(EXECUTE)
	find -name . '*~' -print0 | xargs -0 rm -f
	if [ -d $(dir $(EXECUTE)) ]; then \
		rmdir -p $(dir $(EXECUTE)) 2>/dev/null || : 'ignore errors!'; \
	fi

.PHONY: check clean
