all: clean test

./deps/gyp:
	git clone --depth 1 https://chromium.googlesource.com/external/gyp.git ./deps/gyp

./deps/json11/json11.cpp:
	git submodule update --init

./build: ./deps/gyp ./deps/json11/json11.cpp
	deps/gyp/gyp eevee.gyp --depth . -f make --generator-output ./build

./build/out/Default/eevee: ./build
	make -C ./build

test: ./build/out/Default/eevee
	./build/out/Default/eevee

clean:
	rm -rf ./build
