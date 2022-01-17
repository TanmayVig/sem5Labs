// Java implementation of  Server side
// It contains two classes : Server and ClientHandler

// BROADCAST SERVER
import java.net.*;
import java.io.*;
import java.util.*;

public class Server{

    // All client names
  private static Set<Integer> counter = new HashSet<>();

  // The set of all the print writers for all the clients, used for broadcast.
  private static Set<DataOutputStream> writers = new HashSet<>();

    public static void main(String[] args) throws IOException 
    {
        // server is listening on port 5056
        ServerSocket ss = new ServerSocket(5056);
          
        // running infinite loop for getting
        // client request
        while (true) 
        {
            Socket s = null;
            Integer count = 0;
            try 
            {
                // socket object to receive incoming client requests
                s = ss.accept();
                
                System.out.println(" ");
                System.out.println("A new client is connected : " + s);
                  
                // obtaining input and out streams
                DataInputStream dis = new DataInputStream(s.getInputStream());
                DataOutputStream dos = new DataOutputStream(s.getOutputStream());


                  
                System.out.println("Assigning new thread for this client");

                count ++;
  
                // create a new thread object
                Thread t = new ClientHandler(s, dis, dos, count);
  
                // Invoking the start() method
                t.start();
                  
            }
            catch (Exception e){
                System.out.println(s);
                ss.close();
            }
        }
    }

    // ClientHandler class
    private static class ClientHandler extends Thread 
    {
        private DataInputStream dis;
        private DataOutputStream dos;
        private Socket s;
        private Integer c;
          
      
        // Constructor
        public ClientHandler(Socket socket, DataInputStream in, DataOutputStream out, Integer count) 
        {
            s = socket;
            dis = in;
            dos = out;
            c = count;
            counter.add(count);
            writers.add(dos);
        }
      
        public void run() 
        {
            String received;
            BufferedReader buffer = new BufferedReader(new InputStreamReader(System.in));
            while (true) 
            {
                try {
      
                    // receive the answer from clien
                    received = dis.readUTF();
                    System.out.println(" ");
                      
                    if(received.equalsIgnoreCase("exit"))
                    { 
                        System.out.println("Client " + s + " sends exit...");
                        System.out.println("Closing this connection.");
                        s.close();
                        System.out.println("Connection closed");
                        counter.remove(c);
                        writers.remove(dos);
                        break;
                    }
                    System.out.println("From Client at port " + s.getPort() + ": " + received);
    
                    String tosend = buffer.readLine();
    
                    for(DataOutputStream temp: writers){
                        temp.writeUTF(tosend);
                        temp.flush();
                    }
    
                      
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
              
            try
            {
                // closing resources
                dis.close();
                dos.close();
                  
            }catch(IOException e){
                e.printStackTrace();
            }
        }
    }
}