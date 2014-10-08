all: clean test

clean:
	rm -rf ./build

./deps/gyp:
	git clone --depth 1 https://chromium.googlesource.com/external/gyp.git ./deps/gyp

./deps/json11/json11.cpp:
	git submodule update --init

./build/test: ./deps/gyp ./deps/json11/json11.cpp
	deps/gyp/gyp eevee.gyp --depth . -f make --root-target test -Icommon.gypi --generator-output ./build/test

test: ./build/test
	rm -f build/test/out/Debug/test
	BUILDTYPE=Debug make -C ./build/test
	./build/test/out/Debug/test

.PHONY: test
