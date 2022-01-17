// BROADCAST CLIENT
import java.net.*;
import java.io.*;

public class Client {
    public static void main(String[] args) throws IOException 
    {
        try
        {
              
            // getting localhost ip
            InetAddress ip = InetAddress.getByName("localhost");
      
            // establish the connection with server port 5056
            Socket s = new Socket(ip, 5056);
      
            // obtaining input and out streams
            DataInputStream dis = new DataInputStream(s.getInputStream());
            DataOutputStream dos = new DataOutputStream(s.getOutputStream());
            BufferedReader buffer = new BufferedReader(new InputStreamReader(System.in));
      
            // the following loop performs the exchange of
            // information between client and client handler
            while (true) 
            {
                String tosend = buffer.readLine();
                dos.writeUTF(tosend);
                dos.flush();
                  
                // If client sends exit,close this connection 
                // and then break from the while loop
                if(tosend.equalsIgnoreCase("Exit"))
                {
                    System.out.println("Closing this connection : " + s);
                    s.close();
                    System.out.println("Connection closed");
                    break;
                }
                  
                // printing date or time as requested by client
                String received = dis.readUTF();
                System.out.println(" ");
                System.out.println("From Server: " + received);
            }
              
            // closing resources
            dis.close();
            dos.close();
        }catch(Exception e){
            e.printStackTrace();
        }
    }
}
