# build wolfSSL
```
# go to wolfssl directory (eg. wolfssl-5.6.6)
sudo ./configure --enable-staticmemory --enable-ecc --enable-ecccustcurves=all --enable-compkey --enable-fastmath --enable-compkey CFLAGS="-DWOLFSSL_PUBLIC_MP"
sudo make
sudo make install
```

# build and run project
```
make
./out
```