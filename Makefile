amazing: amazingReturn0.cpp,
	 amazingMaxMin.cpp

	# THIS COMPILES WITH ALL EXTRA PEDANTIC
	# JUST HOW
	g++-10 $^ -o $@ -Wall -Wextra -pedantic -O3 -std=c++20

sort: sort.cpp
	g++-10 $^ -o $@ -Wall -Wextra -pedantic -O3 -std=c++20
