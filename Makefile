CC = cc
CFLAGS = -W -Wall -Wextra -Werror -O

.PHONY: go test clean

all: rev revbig go

*.c:
	${CC} ${CFLAGS} -o $@ $<

go:
	@for file in *.go; do \
	    _out=`echo $$file | sed 's/\.go$$//'`; \
	    echo "go build -o go-$$_out $$file"; \
	    go build -o go-$$_out $$file; \
	done

test:

clean:
	rm -f rev revbig go-*
