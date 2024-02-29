all:
	gcc -g -o out crypto_test.c host_messaging.c -Wall -I/usr/local/include -I. -Os -L/usr/local/lib -lm -lwolfssl -pthread

