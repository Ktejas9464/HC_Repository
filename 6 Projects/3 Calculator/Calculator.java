/*
Calculator application using java programming language
*/

import java.lang.*;
import java.util.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class Maths
{
	int no1 = 0;
	int no2 = 0;
	public Maths(int num1, int num2)
	{
		no1 = num1;
		no2 = num2;
	}
	public int Add()
	{
		return no1+no2;
	}
	public int Sub()
	{
		return no1-no2;
	}
	public int Multiply()
	{
		return no1*no2;
	}
	public int Divide()
	{
		return no1/no2;
	}	
}

class GUI
{
	public GUI()
	{
		JFrame frame = new JFrame("Calculator");
		frame.setSize(500,500);
		
		JLabel l1 = new JLabel("First Number: ");
		l1.setBounds(20,10,100,50);
		
		JLabel l2 = new JLabel("Second Number: ");
		l2.setBounds(20,60,100,50);
		
		JTextField t1 = new JTextField();
		t1.setBounds(200,30,150,35);
		
		JTextField t2 = new JTextField();
		t2.setBounds(200,70,150,35);
		
		JLabel l3 = new JLabel("Choose the operation");
		l3.setBounds(20,150,200,50);
		
		JButton b1 = new JButton("Add");
		b1.setBounds(50,200,120,50);
		
		JButton b2 = new JButton("Sub");
		b2.setBounds(250,200,120,50);
		
		JButton b3 = new JButton("Multiply");
		b3.setBounds(50,270,120,50);
		
		JButton b4 = new JButton("Divide");
		b4.setBounds(250,270,120,50);
		
		JLabel l4 = new JLabel("Result:");
		l4.setBounds(20,350,100,50);
		
		JTextField t3 = new JTextField();
		t3.setBounds(150,350,200,50);
		
		frame.add(l1);
		frame.add(l2);
		frame.add(t1);
		frame.add(t2);
		frame.add(l3);
		frame.add(b1);
		frame.add(b2);
		frame.add(b3);
		frame.add(b4);
		frame.add(l4);
		frame.add(t3);
		
		frame.setLayout(null);
		frame.setVisible(true);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		//Action for Add button
		b1.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent eobj)
			{
				Maths mobj = new Maths(Integer.parseInt(t1.getText()),Integer.parseInt(t2.getText()));
				t3.setText(Integer.toString(mobj.Add()));
			}			
		});
		
		//Action for Sub button
		b2.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent eobj)
			{
				Maths mobj = new Maths(Integer.parseInt(t1.getText()),Integer.parseInt(t2.getText()));
				t3.setText(Integer.toString(mobj.Sub()));
			}			
		});
		
		//Action for Multiply button
		b3.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent eobj)
			{
				Maths mobj = new Maths(Integer.parseInt(t1.getText()),Integer.parseInt(t2.getText()));
				t3.setText(Integer.toString(mobj.Multiply()));
			}			
		});
		
		//Action for Divide button
		b4.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent eobj)
			{
				Maths mobj = new Maths(Integer.parseInt(t1.getText()),Integer.parseInt(t2.getText()));
				t3.setText(Integer.toString(mobj.Divide()));
			}			
		});
	}
}

class Calculator
{
	public static void main(String args[])
	{
		GUI gobj = new GUI();		
	}	
}