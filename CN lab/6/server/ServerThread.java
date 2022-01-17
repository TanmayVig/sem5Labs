import java.io.*;
import java.net.*;
import java.util.*;
public class ServerThread extends Thread {
    private Socket socket;
    private ArrayList<ServerThread> threadlist;
    private PrintWriter output;
    public ServerThread(Socket socket, ArrayList<ServerThread> threadlist){
        this.socket = socket;
        this.threadlist = threadlist;
    }

    @Override
    public void run(){
        try{
            BufferedReader input = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            output = new PrintWriter(socket.getOutputStream(),true);
            while(true){
                String outputString = input.readLine();
                if(outputString.equals("bye")){
                    break;
                }
                printToAllClients(outputString);
                System.out.println("Server Recieved: "+ outputString);
            }
        }catch(Exception e){
            System.out.println("Error occured in main of Server:" + e.getStackTrace());
        }
    }
    private void printToAllClients(String outputString){
        for(ServerThread i : threadlist){
            i.output.println(outputString);
        }
    }
}
