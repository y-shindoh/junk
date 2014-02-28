# -*- coding: utf-8; tab-width: 4 -*-

SOURCE		:= Compare.java
CLASS		:= $(patsubst %.java,%.class,$(SOURCE))

JAVA_OPTION	:= -Dfile.encoding=UTF-8

%.class : %.java
	# $(@F)
	env _JAVA_OPTIONS="$(JAVA_OPTION)" \
	javac $<

all: $(CLASS)

check: $(CLASS)
	env _JAVA_OPTIONS="$(JAVA_OPTION)" \
	java $(basename $<)

clean:
	rm -f $(CLASS)
	find . -name '*~' -print0 | xargs -0 rm -f

.PHONY: all check clean
