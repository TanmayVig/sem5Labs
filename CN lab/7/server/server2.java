import java.net.*;
import java.io.*;

public class server2 {
public static void main (String []args) {
               try { 
                      ServerSocket ss = new ServerSocket(1999); 
                      Socket s = ss.accept(); 
                      DataInputStream dis = new DataInputStream(s.getInputStream()); 
                      String k = dis.readUTF(); 
                      System.out.println("File Transferred"); 
                      FileOutputStream fos = new FileOutputStream("D:\\sem-5\\CN lab\\7\\server\\test.txt"); 
                      byte[] b = k.getBytes(); 
                      fos.write(b);
                    // fos.writeChars(k); 
                     } catch (IOException ie) { 
                       ie.printStackTrace(); 
                     }
          }
}