import java.io.*;
import java.util.*;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileInputStream;
import java.lang.*;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

class Front
{
	public static void main(String arg[])
	{
		Window obj = new Window();
	}
	
}

class Window //implements ActionListener
{
	public Window()
	{
		JFrame f = new JFrame("File Packer");
		
		//---------------------------------------
		JLabel lobj1 = new JLabel("Enter Folder name: ");
		lobj1.setBounds(10,10,120,100);
		
		JTextField tf1 = new JTextField();
		tf1.setBounds(140,50,130,30);
		//---------------------------------------
		JLabel lobj2 = new JLabel("Enter File name: ");
		lobj2.setBounds(10,60,120,100);
		
		JTextField tf2 = new JTextField();
		tf2.setBounds(140,100,130,30);
		//----------------------------------------
		JButton bobj = new JButton("Submit");
		//(x-cordinate, y-cordinate, width, height)
		bobj.setBounds(70,180,130,30);
		
		f.add(lobj1);
		f.add(tf1);
		f.add(lobj2);
		f.add(tf2);
		f.add(bobj);
		
		f.setSize(300,300);
		f.setLayout(null);
		f.setVisible(true);
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		bobj.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent eobj)
			{
				//System.out.println("Folder name: "+tf1.getText());
				//System.out.println("File name: "+tf2.getText());
				Packer pobj = new Packer(tf1.getText(),tf2.getText());
				f.setVisible(false);
				NewWindow nobj = new NewWindow();
			}
		});	
	}
}

class NewWindow
{
	public NewWindow()
	{
		JFrame fobj = new JFrame("File Unpacker");
		
		JLabel lobj = new JLabel("Enter File to unpack: ");
		lobj.setBounds(10,20,120,100);
		
		JTextField tf = new JTextField();
		tf.setBounds(140,60,130,30);
		
		JButton bobj = new JButton("Submit");
		bobj.setBounds(70,150,130,30);
		
		fobj.add(lobj);
		fobj.add(tf);
		fobj.add(bobj);
		
		fobj.setSize(300,300);
		fobj.setLayout(null);
		fobj.setVisible(true);
		fobj.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		bobj.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent eobj)
			{
				Unpacker pobj = new Unpacker(tf.getText());
				fobj.setVisible(false);
			}
		});
	}
	
}

class Packer
{
	//reference to write in output stream - characteristic
	public FileOutputStream outstream = null;
	//parameterised constructor - create file inside constructor
	public Packer(String FolderName, String FileName)
	{
		try
		{
			//System.out.println("Inside packer constructor");
			//creates new file for packing
			File outfile = new File(FileName);
			outstream = new FileOutputStream(FileName);
			
			//Set the current working directory for folder traversal
			System.setProperty("user.dir",FolderName);
			
			TravelDirectory(FolderName);
		}
		catch(Exception obj)
		{
			System.out.println(obj);
		}
	}
	
	public void TravelDirectory(String path)
	{
		File directoryPath = new File(path);
		int counter = 0;
		
		//get all file names from directory
		File arr[] = directoryPath.listFiles();
		
		for(File filename : arr)
		{
			//System.out.println(filename.getName());
			//System.out.println(filename.getAbsolutePath());
			if(filename.getName().endsWith(".txt"))
			{
				PackFile(filename.getAbsolutePath());
				counter++;
			}
		}
		System.out.println("Successfully packed files: "+counter);
	}
	
	public void PackFile(String FilePath)
	{
		//packing logic
		//System.out.println("FileName received: "+FilePath);
		byte Header[] = new byte[100];
		byte Buffer[] = new byte[1024];
		int length = 0;
		
		FileInputStream istream = null;
		
		File fobj = null;
		fobj = new File(FilePath);
		
		String temp = FilePath+" "+fobj.length();
		
		//System.out.println("Header: "+temp.length());
		
		//create header of 100 bytes
		for(int i=temp.length();i<100;i++)
		{
			temp = temp + " ";
		}
		//System.out.println("Header: "+temp.length());
		//convert string (array of characters) to bytes
		Header = temp.getBytes();
		
		try
		{
			//open file for reading
			istream = new FileInputStream(FilePath);
			
			outstream.write(Header,0,Header.length);
			while((length = istream.read(Buffer)) > 0)
			{
				outstream.write(Buffer,0,length);
			}
			
			istream.close();
		}
		catch(Exception obj)
		{}
		
		//System.out.println("Header: "+temp.length());
		
	}
}

//class
class Unpacker
{
	//object to write
	public FileOutputStream outstream = null;
	//constructor
	public Unpacker(String src)
	{
		//System.out.println("Inside unpacker");
		unpackFile(src);
	}
	
	public void unpackFile(String FilePath)
	{
		try
		{
			//file open
			FileInputStream instream = new FileInputStream(FilePath);
			//local variables
			byte Header[] = new byte[100];
			int length = 0;
			int counter = 0;
		
			while((length = instream.read(Header,0,100)) > 0)
			{
				//convert byte to string
				String str = new String(Header);
				//System.out.println(str);
				//extract last extension
				String ext = str.substring(str.lastIndexOf("\\"));
				//get file name - remove first letter
				ext = ext.substring(1);
				
				//word[0] - filename, word[1] - file length
				//handle space
				String words[] = ext.split("\\s");
				String name = words[0];
				//convert file length to int
				int size = Integer.parseInt(words[1]);
				
				//create array of bytes of size = file size
				byte arr[] = new byte[size];
				instream.read(arr,0,size);
				
				//new file gets created
				FileOutputStream fout = new FileOutputStream(name);
				//write data into newly created file
				fout.write(arr,0,size);
				counter++;
			}
			
			System.out.println("Successfully unpacked files: "+counter);
			//instream.read(Header,0,100);
			//System.out.println(Header.toString());
		}
		catch(Exception obj)
		{}
	}
}
