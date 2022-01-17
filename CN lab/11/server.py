import socket

HOST = '127.0.0.1'
PORT = 3300

conn_list = list()

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST,PORT))
    s.listen()
    while True:
        choice = int(input("Enter\n 1. to add network\n 2. to send message to all connections\n 4. to end\n"))
        if(choice==1):
            conn,add = s.accept()
            conn_list.append((conn,add))
            conn.sendall(b'connected to Server')
            print("Connected to:" + add[0]+":"+str(add[1]))
        elif(choice==2):
            msg:str = input("Enter message to send: ")
            for c,a in conn_list:
                c.sendall(msg.encode())
        else:
            break