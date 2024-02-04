g++ -std=gnu++20 -Wall -Wextra -Wshadow $1.cpp -o $1 -O2 -g
./$1
rm $1

