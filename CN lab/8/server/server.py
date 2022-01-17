import socket
import pickle

HOST:str='127.0.0.1'
PORT:int=3000

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST,PORT))
    s.listen()
    conn,add=s.accept()
    with conn:
        while True:
            if ext:=conn.recv(1024):
                ext = ext.decode().split(".")[1]
                with open("recv.{}".format(ext),'wb') as f:
                    
                    while True:
                        data= conn.recv(1024)
                        try:
                            if data.decode():
                                break
                        except UnicodeDecodeError:
                            pass
                        f.write(data)
                    print("New File Recieved")
            else:
                break
            
            choice = int(input("""
            Enter:
                1. to send text file
                2. to send image
                3. to exit
            """))
            if choice == 1:
                choice=3
                path = input("Enter path: ")
                conn.sendall(path.encode())
                with open(path,'rb') as f:
                    line = f.read(1024)
                    while line:
                        conn.sendall(line)
                        print("sending: "+line.decode('utf-8'))
                        line = f.read(1024)
                    conn.sendall(False)
                print("Task completed: File sent to server.")
            elif choice==2:
                choice=3
                path = input("Enter path: ")
                conn.sendall(path.encode())
                with open(path, 'rb') as f:
                    while True:
                        line = f.read(1024)
                        if not line:
                            break
                        conn.sendall(line)
                    conn.sendall(bytes(False))
                print("Task completed: Image sent to server")
            else:
                break