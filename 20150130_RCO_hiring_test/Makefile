# -*- coding: utf-8; tab-width: 4 -*-

INPUT	:= $(wildcard input_*.txt)
OUTPUT	:= $(patsubst input_%.txt,output_%.txt,$(INPUT))

output_%.txt : input_%.txt
	# input: $<
	@cat $<
	# output: $@
	@ruby -Ku translator.rb < $< | tee $@

all: $(OUTPUT)

clean:
	rm -f $(OUTPUT)
	find . -name '*~' -print0 | xargs -0 rm -f
	for d in $(sort $(dir $(OUTPUT))); do \
		if [ -d $$d ]; then rmdir -p $$d 2>/dev/null || : 'ignore errors!'; fi \
	done
