import java.io.*;
import java.net.*;
public class server{
    public static void main(String[] args){
        try{
            ServerSocket server = new ServerSocket(8080);
            Socket s = server.accept();
            DataInputStream in = new DataInputStream(s.getInputStream());
            DataOutputStream out = new DataOutputStream(s.getOutputStream());
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            String str_recieve="",str_send="";
            while(!str_recieve.equals("stop")){
                str_recieve = in.readUTF();
                if(str_recieve.equals("stop")){
                    break;
                }
                System.out.println("Client: "+ str_recieve);
                str_send = br.readLine();
                out.writeUTF(str_send);
                out.flush();
            }
            System.out.println("Client: "+ str_recieve);
            out.close();
            in.close();
            server.close();
        }catch(Exception e){System.out.println("Connection Ended");}
    }
}