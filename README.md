Infiltration of data whether it be code, commands, or a binary file to drop to disk and execute could be much easier, especially using the DNS type of TXT (as opposed to host record type A). TXT types were designed to provide descriptive text, such as service details, contact names, phone numbers, etc in response to TXT DNS queries for domain names.
Guess what looks likes text? Base64-encoded non-text data!below shows the identical query being sent to the malicious site, however, the type is now TXT on both the request and response, and the response data contains the first 300 or so characters of an encoded binary executable file that could be executed by the client malware. Again, using the logs, the adversary would be able to know which client asked for the payload, and that the payload was sent (who knows if it actually arrived…).

## tldr
we store payload in TXT DNS records.
We query the DNS and get our payload on remote system.

## 2 pocs

### 1. python 
This is a python executable that uses default libraries in python and linux bash to retrieve our payload and then b_64 decode it.
```
python3 filename.py
```
will work here, you can import this code in any of your exploits

### 2. C plus plus or binary file 
I have included 2 codes here - long and short with their executables
long has alll descriptive comments and steps
short has been stripped of them, to reduce side

minimum size recieved without any ofuscation yet- 64288 bytes or 64 kb
We can easily get this under around 50 kb by removing some spaces and few more refrences.
