import java.io.*;
import java.net.*;
public class client2 {
    public static void main(String[] args) {
        try{
            Socket s = new Socket("localhost",8080);
            DataOutputStream out = new DataOutputStream(s.getOutputStream());
            DataInputStream in = new DataInputStream(s.getInputStream());
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            String str_send="",str_recieve="";
            while(!str_recieve.equals("stop")){
                str_send = br.readLine();
                out.writeUTF(str_send);
                out.flush();
                str_recieve = in.readUTF();
                System.out.println("Server: "+str_recieve);
            }
            out.close();
            s.close();
        }catch(Exception e){System.out.println("Connection Ended");}   
    }
}
