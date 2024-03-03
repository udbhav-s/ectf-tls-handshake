# Simulated TLS handshake protocol implementation
This is a mutual authentication protocol for eCTF 2024 where an embedded application processor (AP) and a component must verify each other, based on certificates that are generated for both at build-time and signed by a host. 

Both AP and component will use ephemeral Diffie-Hellman for forward secrecy, which involves generating an additional ECC keypair on each side following an exchange of those public keys and combining them to derive a shared secret.   

➡️ Client (AP) sends:  
1) `ap_pubkey`
2) `ap_dh_pubkey` 
3) Signature of (1) and (2) with `ap_pubkey`
4) cert sig: signature of  (`ap_pubkey` + `ap_name`) signed by `host_pubkey`

(3) proves that AP owns the DH key and (4) proves that host certified the AP  

Server (component) receives message. Component validates `ap_pubkey` from certificate and `host_pubkey`, and then verifies signature of entire message with `ap_pubkey`.  

Component generates it's own DH keypair and derives `shared_key` using `ap_dh_pubkey`.  

⬅️ Component sends:  
1) `comp_pubkey`
2) `comp_dh_pubkey`
3) Signature of (1) and (2) with `comp_pubkey`
4) Certificate: signature of (`comp_pubkey` + `comp_id`) by `host_pubkey`

Component also sends (separately due to package size restrictions)
* Signature of `ap_dh_pubkey` using `comp_pubkey` (this additional parameter is the challenge response from component's side)

AP receives message, validates the certificate & message signature, and derives the `shared_key` in a similar fashion.   

AP also verifies the signature of the `ap_dh_public_parameter`, which is enough to conclude if the component is genuine.   

➡️ AP responds with:   
1) Signature of `comp_dh_pubkey` using `ap_pubkey`

(AP can then continue validating other components if proceeding to boot or wait for a response if requesting attestation data. )  

Component validates the signature and concludes that the AP is genuine.  
The handshake is complete.  

# build wolfSSL
```
# go to wolfssl directory (eg. wolfssl-5.6.6)
sudo ./configure --enable-staticmemory --enable-ecc --enable-ecccustcurves=all --enable-fastmath --enable-compkey --enable-ed25519 --disable-harden CFLAGS="-DWOLFSSL_PUBLIC_MP"
sudo make
sudo make install
```

# build and run project
```
make
./out
```
