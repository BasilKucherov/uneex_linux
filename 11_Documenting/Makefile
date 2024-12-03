GENERATES = build

all: ${GENERATES}

${GENERATES}:
	mkdir -p $@ && \
	cd $@ && \
	cmake -DCMAKE_INSTALL_PREFIX=. .. && \
	make && \
	make doc && \
	make install

clean:
	rm -rf ${GENERATES}
