import java.io.*;
import java.net.*;

class TestClient 
{
   public static void main(String[] args)
   {
	String host="localhost";
      try 
      {
         Socket  client    = new Socket("localhost", 4321);
         DataOutputStream socketOut = new DataOutputStream(client.getOutputStream());
         DataInputStream  socketIn  = new DataInputStream(client.getInputStream());
         BufferedReader  console   = new BufferedReader(new InputStreamReader(System.in));
         System.out.println("Connected to " + host + ". Enter text:");

         boolean done = false;
         String line;
        while (!done) 
         {
             line = console.readLine();
            if (line.equalsIgnoreCase(".bye"))
               done = true;
            socketOut.writeBytes(line + '\n');
         }

         socketOut.close(); socketIn.close(); client.close();
      } 
      catch (UnknownHostException e) 
      { System.err.println(host + ": unknown host."); } 
      catch (IOException e) 
      { System.err.println("I/O error with " + host); }
	
   }
}