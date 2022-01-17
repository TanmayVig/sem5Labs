import java.io.*;
import java.net.*;

public class ClientThread extends Thread{
    private Socket socket;
    private BufferedReader br;
    
    public ClientThread(Socket e) throws IOException{
        this.socket = e;
        this.br = new BufferedReader(new InputStreamReader(socket.getInputStream()));
    }

    @Override
    public void run(){
        try{
            while(true){
                String response = br.readLine();
                System.out.println(response);
            }
        } catch(IOException e){
            e.printStackTrace();
        }finally{
            try{
                br.close();
            }catch(Exception e){
                e.printStackTrace();
            }
        }
    }
}
