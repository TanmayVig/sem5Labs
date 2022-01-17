import java.net.*;
import java.io.*;
public class server
{
    public static final int port = 8080;
    public static void main(String arg[]) throws IOException
    {
 
        ServerSocket s = new ServerSocket(port);
        System.out.println("Started:  " + s);
        byte[] buffer = new byte[10];
 
        try
        {
            Socket socket = s.accept();
            System.out.println("Connection accepted: "+ socket);
            //copy file  code here
 
 
 
                try
                {
                InputStream in = new BufferedInputStream(socket.getInputStream());
 
 
                while(true)// loop to copy the file
                {
 
 
                }
 
                }
                finally
                {
                    socket.close();    
                    System.out.println("closing socket...");
                }    
        }
        finally
        {
            s.close();
            System.out.println("closing Server socket...");
        }
    }
}

