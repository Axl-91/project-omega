.PHONY: configure build run clean

configure:
	cmake -S . -B build

build: configure
	cmake --build build

run: build
	./build/bin/ProjectOmega

clean:
	rm -rf build
