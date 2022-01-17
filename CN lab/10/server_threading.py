import socket
from datetime import datetime
import os
import _thread

HOST:str='127.0.0.1'
PORT:int=3000
thread_count:int=0

def threaded_client(connection,add: tuple) -> None :
    while True:
        data = connection.recv(2048)
        if not data or data.decode()=="bye":
            break
        print("{} Client {}: ".format(datetime.now(),str(add[1])) + data.decode())
        connection.sendall(reply:=str.encode(input("{} Server: ".format(datetime.now()))))
        if reply=="bye":
            break
    connection.close()

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST, PORT))
    s.listen()
    while True:
        conn,add =s.accept()
        print("Connected to:" + add[0]+":"+str(add[1])+" at "+str(datetime.now()))
        _thread.start_new_thread(threaded_client,(conn,add))
        thread_count+=1
