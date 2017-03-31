import java.net.*;
import java.io.*;
import java.util.*;

public class TestServer
{
   public static void main(String args[])
   {
	
      Socket client = null;
      ServerSocket server= null;
    try
      {
      server = new ServerSocket(4321);
      System.out.println("Server setup and waiting for client connection ...");
      client = server.accept();   
  
      System.out.println("Client connection accepted. Moving to local port ...");
      } 
      catch (Exception e) 
      {
         System.out.println("Error on port: 4321 " + ", " + e);
         System.exit(1);
      }
      
      try
      {
         BufferedReader streamIn = new BufferedReader(new InputStreamReader(client.getInputStream()));
         boolean done = false;
         String line;
         while (!done)
         {
            line = streamIn.readLine();
            if (line.equalsIgnoreCase(".bye"))
               done = true;
            else
               System.out.println("Client says: " + line);
         }

         streamIn.close();
         client.close();
         server.close();
      }
      catch(IOException e)
      { 
      System.out.println("IO Error in streams " + e); 
       }
   }
}