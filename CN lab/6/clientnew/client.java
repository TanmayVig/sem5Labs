import java.net.*;
import java.io.*;
public class client
{
 
    public static void main(String arg[]) throws IOException
    {
 
        InetAddress addr = InetAddress.getByName(null);//because i'm in my pc
        System.out.println("addr = " + addr);
        Socket socket = new Socket(addr, server.port);
 
        String source = "D:/sem-5/CN lab/6/clientnew/t.txt";
        byte[] buf = new byte[10];//1 kilobyte buffer
        int lentgth;
 
 
        InputStream in = new BufferedInputStream(new FileInputStream(source));
        OutputStream out = new BufferedOutputStream(socket.getOutputStream());
 
 
        try
        {
 
 
 
 
            while((lentgth = in.read(buf))>0)
                {
 
                    out.write(buf,0,lentgth);//byte flow sent to the server
                }
 
 
 
 
        }
        finally
        {
            out.flush();
            out.close();
            in.close();
            System.out.println("closing socket...");
            socket.close();
        }
    }
}
 
