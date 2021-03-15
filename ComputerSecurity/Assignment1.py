import hashlib
from Crypto.PublicKey import RSA
from Crypto.Cipher import PKCS1_v1_5
from Crypto.Hash import SHA
from Crypto import Random
from Crypto.Cipher import AES
from Crypto.Cipher import DES
from Crypto.Cipher import DES3

def hashFunction(plain) :
    print("\n---------- Hash Function -----------")
    while True : 
        hashtype = input("hash type(SHA1 / SHA256 / SHA384 / SHA512) : ")
        if hashtype == "SHA256" :
            m = hashlib.sha256()
            # use 'encode()' to make plaintext(string) to bytes
            m.update(plain.encode())
            print(m.hexdigest())
            return
        elif hashtype == "SHA384" :
            m = hashlib.sha384()
            m.update(plain.encode())
            print(m.hexdigest())
            return
        elif hashtype == "SHA512" :
            m = hashlib.sha512()
            m.update(plain.encode())
            print(m.hexdigest())
            return
        elif hashtype == "SHA1" :
            m = hashlib.sha1()
            m.update(plain.encode())
            print(m.hexdigest())
            return
        else :
            print("Please enter only one of SHA1, SHA256, SHA384 or SHA512")

            
def RSAFunction(plain):
    print("\n---------- Asymmetric Encryption(RSA) ----------")
    while True : 
        length = input("key length(Choose above 1024) : ")
        if length.isdigit() : 
            if int(length) >= 1024 :
                # variable 'rsakey' is a class RsaKey
                rsakey = RSA.generate(int(length))

                cipher = PKCS1_v1_5.new(rsakey)
                
                if cipher.can_encrypt() : 
                    cipherText = cipher.encrypt(plain.encode())
                    print("encrypted :",cipherText)
                    
                    sentinel = b"DECRYPT ERROR"
                    dePlain = cipher.decrypt(cipherText,sentinel)
                    # use 'decode()' to make bytes to plaintext(string)
                    print("decrypted :",dePlain.decode())

                else :
                    print("This plain text can not encrypt with RSA")
                return
                
            else :
                print("Please enter ar least 1024")
        else :
            print("Plesae enter number")


def Symmetric(plain) :
    print("---------- Symmetric Encryption -----------")
    while True : 
        ciphertype = input("cipher type(DES / DES3 / AES) : ")
        if ciphertype == "DES" :
            DESFunction(plain)
            return
        elif ciphertype == "DES3" :
            DES3Function(plain)
            return
        elif ciphertype == "AES" :
            AESFunction(plain)
            return
        else :
            print("Please enter only one of DES, DES3 or AES")

    
def DESFunction(plain) :
    while True :
        key = input("key(Type 8 but use 7 only) : ")
        if len(key) == 8 :
            DESkey= key.encode()
            cipher = DES.new(DESkey, DES.MODE_ECB)
    
            # make plaintext 8 bytes through padding because DES has a fixed data block size of 8 bytes
            # use underbar for padding char
            # DES.block_size = 8
            plain = plain + ((DES.block_size - (len(plain) % DES.block_size)) * '_')
    
            cipherText = cipher.encrypt(plain.encode())
            print("encrypted: ", cipherText)

            dePlain = cipher.decrypt(cipherText)
            print("decrypted : ", dePlain.decode())
            return
        else :
            print("Please enter a key that is 8 in length")


def DES3Function(plain) :
    while True : 
        key = input("key(16 / 24) : ")
        if (len(key) == 16 and key[:7] != key[8:15]) or (len(key) == 24 and key[:7] != key[8:15] and key[8:15] != key[16:23]) :
            DES3key = DES3.adjust_key_parity(key.encode())
            cipher = DES3.new(DES3key, DES3.MODE_ECB)

            # make plaintext 8 bytes through padding because DES3 has a fixed data block size of 8 bytes
            # use underbar for padding char
            # DES3.block_size = 8
            plain = plain + ((DES3.block_size - (len(plain) % DES3.block_size)) * '_')
    
            cipherText = cipher.encrypt(plain.encode())
            print("encrypted : ", cipherText)

            dePlain = cipher.decrypt(cipherText)
            print("decrypted : ", dePlain.decode())
            return
        else :
            print("Please enter a key that is 16 or 24 in length.")
            print("If you enter a 16-digit key, the first eight parts and the last eight parts must be different. ")
            print("If you enter a 24-digit key, the eight parts in the middle mush be different form the first eight and the last eight")


def AESFunction(plain) :
    while True :
        # AES uses 128/192/256 bits key -> my python bit is 64bits(128/8 = 16)    
        key = input("key(16 / 24 / 32) : ")
        if len(key) == 16 or len(key) == 24 or len(key) == 32 :
            AESkey = key.encode()
            cipher = AES.new(AESkey, AES.MODE_EAX)

            # make plaintext 16 bytes through padding because AES has a fixed data block size of 16  bytes
            # use underbar for padding char
            # cipher.block_size = 16
            plain = plain + ((cipher.block_size - (len(plain) % cipher.block_size)) * '_')
            cipherText = cipher.encrypt(plain.encode())
    
            print("encrypted : ", cipherText)

            de = AES.new(AESkey, AES.MODE_EAX, cipher.nonce)
            dePlain = de.decrypt(cipherText)
            print("decrypted : ", dePlain.decode())
            return 
        else :
            print("Please enter a key that is 16 or 24 or 32 in length")

    
def main() :
    plain = input("Plain text : ")
    print("")
    plain.rstrip("\n")
    Symmetric(plain)
    hashFunction(plain)
    RSAFunction(plain)
    
      
if __name__ == "__main__":
    main()

