import java.io.*;
import java.net.*;
import java.awt.*;
import javax.swing.*;


 /**
 * The class Server extends J frame
 */ 
public class JavaServer extends JFrame {
    private static final int PORT = 12345;
    private JPanel drawingPanel;


/** 
 *
 * Server
 *
 * @return public
 */
    public JavaServer() { 

        setTitle("Java Drawing Server");
        setSize(800, 600);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        drawingPanel = new JPanel() {
            @Override

/** 
 *
 * Paint component
 *
 * @param g  the g. 
 */
            protected void paintComponent(Graphics g) { 

                super.paintComponent(g);
                // Custom drawing code will go here
            }
        };
        add(drawingPanel);
        setVisible(true);
    }


/** 
 *
 * Main
 *
 * @param args  the args. 
 */
    public static void main(String[] args) { 

        JavaServer server = new JavaServer();
        server.startServer();
    }


/** 
 *
 * Start server
 *
 */
    public void startServer() { 

        try (ServerSocket serverSocket = new ServerSocket(PORT)) {
            System.out.println("Server started on port " + PORT);
            while (true) {
                Socket clientSocket = serverSocket.accept();
                new ClientHandler(clientSocket, drawingPanel).start();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static class ClientHandler extends Thread {
        private Socket clientSocket;
        private JPanel drawingPanel;


/** 
 *
 * Client handler
 *
 * @param socket  the socket. 
 * @param panel  the panel. 
 * @return public
 */
        public ClientHandler(Socket socket, JPanel panel) { 

            this.clientSocket = socket;
            this.drawingPanel = panel;
        }

        @Override

/** 
 *
 * Run
 *
 */
        public void run() { 

            try (BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()))) {
                String command;
                while ((command = in.readLine()) != null) {
                    System.out.println("Received command: " + command);
                    // Process the command and update the drawing panel
                    processCommand(command);
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }


/** 
 *
 * Process command
 *
 * @param command  the command. 
 */
        private void processCommand(String command) { 

            // Example command: "DRAW_RECTANGLE 50 50 100 100"
            String[] parts = command.split(" ");
            String action = parts[0];
            Graphics g = drawingPanel.getGraphics();

            switch (action) {
                case "DRAW_RECTANGLE":
                    int x = Integer.parseInt(parts[1]);
                    int y = Integer.parseInt(parts[2]);
                    int width = Integer.parseInt(parts[3]);
                    int height = Integer.parseInt(parts[4]);
                    g.drawRect(x, y, width, height);
                    break;
                // Add more cases for different shapes
            }
        }
    }
}