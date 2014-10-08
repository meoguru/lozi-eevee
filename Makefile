all: ./build ./build/out/Default/eevee

./deps/gyp:
	git clone --depth 1 https://chromium.googlesource.com/external/gyp.git ./deps/gyp

./build: ./deps/gyp
	deps/gyp/gyp eevee.gyp --depth . -f make --generator-output ./build

./build/out/Default/eevee: ./build
	make -C ./build

test: ./build/out/Default/eevee
	./build/out/Default/eevee

clean:
	rm -rf ./build
