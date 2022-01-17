import socket


HOST:str='127.0.0.1'
PORT:int=3300

with socket.socket(socket.AF_INET,socket.SOCK_STREAM) as s:
    s.connect((HOST,PORT))
    while True:
        data=s.recv(1024)
        if not data or data.decode()=="bye":
            break
        print("Server: " +data.decode())
