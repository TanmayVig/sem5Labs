import socket

HOST:str = '127.0.0.1'
PORT:int = 3300

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST,PORT)) # binding socket
    s.listen(); # listning for new connection requests
    conn,addr = s.accept() # accepting connection request from client

    with conn:
        print("connected to: "+str(addr[1]))
        send:str = input("Enter string containing 0s and 1s: ")
        conn.sendall(send.encode())# sending string containing 0s and 1s
        data:bytes = conn.recv(1024) # recieving data from client
        print("Client: \n"+data.decode('utf8'))