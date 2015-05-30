# -*- tab-width: 4 -*-

SOURCE	:= $(sort $(wildcard *.c) $(wildcard *.cpp))
EXECUTE	:= sample_dp.exe sample_nodp.exe

CXX			:= clang++
CXXFLAGS	:= -Wall -std=c++98 -O2

LENGTH	:= 40
STEP	:= 3

%_dp.exe : $(SOURCE)
	# create: $@
	$(CXX) $(CXXFLAGS) -D'LENGTH=$(LENGTH)' -D'STEP=$(STEP)' $< -o $@

%_nodp.exe : $(SOURCE)
	# create: $@
	$(CXX) $(CXXFLAGS) -D'LENGTH=$(LENGTH)' -D'STEP=$(STEP)' -DNOT_USE_DP $< -o $@

check: $(EXECUTE)
	@for e in $^ ; do \
		if [ -e $${e} ]; then \
			printf "# execute: $${e}\n"; \
			time ./$${e}; \
		fi \
	done

clean:
	rm -f $(EXECUTE)
	find . -name '*~' -print0 | xargs -0 rm -f

.PHONY: check clean
