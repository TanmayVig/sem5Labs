import socket
import pickle

HOST : str = '127.0.0.1'
PORT : int = 3300

def generate_key(text: str,key: str) -> str: 
    """
    makes length of key and text equal
    """
    return "".join(key for _ in range(int(len(text)/len(key)))) + key[:len(text)%len(key)]

def decrypt(data: dict) -> str:
    """
    Decrypts to plain text
    """
    text=data.get('text')
    key = data.get('key')
    key=generate_key(text,key)
    dc : str=""
    sub : int=ord('a' if text[0].islower() else 'A') # checks if text is all lower or all upper case
    for a,b in zip(text,key):
        dc+=chr((ord(a)-ord(b)+26)%26+sub) # decrypting text
    return dc

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST, PORT)) # binding socket 
    s.listen() 
    conn,addr = s.accept() # accepting connection and returning connection and address info
    with conn:
        print("connected to ",addr)
        data = conn.recv(1024) # recieving data from client
        print("client: "+decrypt(pickle.loads(data))) # printing decrypted message
        conn.sendall(b'recieved')