RED="\e[31m"
GREEN="\e[32m"
ENDCOLOR="\e[0m"

cmake -B build 
cd build
make

if [ $? -eq 0 ]; then
    echo -e "${GREEN}Build successful${ENDCOLOR}"
else
    echo -e "${RED}Build failed${ENDCOLOR}"
fi