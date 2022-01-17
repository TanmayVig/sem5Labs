import socket
from datetime import datetime
import os

HOST:str='127.0.0.1'
PORT:int=3000
thread_count:int=0
conn_list:list=[]

def chat(connection,add) -> None :
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
        choice= int(input("Enter:\n 1. to  add new client\n 2. to chat with client\n 0 to exit\n"))
        if(choice==1):
            conn,add =s.accept()
            print("Connected to:" + add[0]+":"+str(add[1])+" at "+str(datetime.now()))
            conn_list.append((conn,add))
            thread_count+=1
        elif(choice==2):
            if(len(conn_list)<1):
                print("no connections yet!")
                continue
            chat(conn_list[0][0],conn_list[0][1])
            conn_list.pop(0)
        else:
            break
