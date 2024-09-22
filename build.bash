# Create a build directory and compile the project
mkdir -p build

# Compile the project
gcc -Wall src/*.c src/*.h -o build/strlib