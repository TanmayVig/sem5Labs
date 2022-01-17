import java.io.*;
import java.net.*;
import java.util.*;
public class main {
    public static void main(String[] args){
        ArrayList<ServerThread> threadList = new ArrayList<ServerThread>();
        try(ServerSocket serverSocket = new ServerSocket(8000)){
            Socket socket = serverSocket.accept();
            ServerThread serverThread = new ServerThread(socket,threadList);
            threadList.add(serverThread);
            serverThread.start();
        }catch(Exception e){ System.out.println("Error occurred in main of server: "+ e.getStackTrace());}
    }
}
