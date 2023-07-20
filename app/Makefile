main: compile 

compile:
	emcc -O3 -s WASM=1 -s EXTRA_EXPORTED_RUNTIME_METHODS='["cwrap"]' -s EXPORTED_FUNCTIONS="['_sayHello']" hello.cpp -o hello.js


