import java.io.*;
import java.net.*;
import java.util.Scanner;
public class main {
    
    public static void main(String[] args){
        try(Socket socket = new Socket("localhost",8000)){
            BufferedReader br = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            PrintWriter output = new PrintWriter(socket.getOutputStream(),true);
            Scanner scanner = new Scanner(System.in);
            String userInput,response,ClientName = "";
            ClientThread clientThread = new ClientThread(socket);
            clientThread.start();
            do{
                if(ClientName.equals("")){
                    System.out.println("Enter your Name");
                    userInput = scanner.nextLine();
                    ClientName = userInput;
                    if(userInput.equals("bye")) break;
                }
                else{
                    String message = ("("+ClientName+")" + "message: ");
                    System.out.println(message);
                    userInput = scanner.nextLine();
                    output.println(message+" "+ userInput);
                    if(userInput.equals("bye")) break;
                }
            }while(!userInput.equals("bye"));
        }catch(Exception e){ System.out.println("Exception in client Main: "+e.getStackTrace()); }
     }
}
