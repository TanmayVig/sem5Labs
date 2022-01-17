import socket
import pickle

HOST : str = '127.0.0.1'
PORT : int = 3300

def generate_key(text: str,key: str) -> str:
    """
    makes length of key and text equal
    """
    return "".join(key for _ in range(int(len(text)/len(key)))) + key[:len(text)%len(key)]

def encrypt(text: str, key : str) -> str:
    """
    Encrypts plain text
    """
    key=generate_key(text,key)
    ec : str=""
    sub : int=ord('a' if text[0].islower() else 'A') # checks if text is all lower or all upper case
    for a,b in zip(text,key):
        ec+=chr((ord(a)+ord(b)-2*sub)%26+sub) # encrypting text
    return ec


with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT)) # establishing connection with server
    text : str = encrypt(msg:=input("Enter the message you want to send... ")
            ,key:=input("Enter the key... ")) # encrypting text input
    print("text input: "+msg)
    print("text sent: "+text)
    s.sendall(pickle.dumps({"text":text,"key":key})) # send message to server
    data = s.recv(1024)
    print("server: "+data.decode())