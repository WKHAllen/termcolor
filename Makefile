CC=gcc

all: test

test: test/test.c src/termcolor.c src/termcolor.h
	$(CC) -o bin/test \
		-std=c99 -pedantic -Wall \
		-Wno-missing-braces -Wextra -Wno-missing-field-initializers -Wformat=2 \
		-Wswitch-default -Wswitch-enum -Wcast-align -Wpointer-arith \
		-Wbad-function-cast -Wstrict-overflow=5 -Wstrict-prototypes -Winline \
		-Wundef -Wnested-externs -Wcast-qual -Wshadow -Wunreachable-code \
		-Wlogical-op -Wfloat-equal -Wstrict-aliasing=2 -Wredundant-decls \
		-Wold-style-definition -Werror \
		-ggdb3 \
		-O0 \
		-fno-omit-frame-pointer -ffloat-store -fno-common -fstrict-aliasing \
		-lm \
		test/test.c src/termcolor.c

run:
	bin/test

clean:
	rm bin/test
