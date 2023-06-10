using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace protocolGUI
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            serialPort11.Open();
        }
      
        private void button1_Click(object sender, EventArgs e)
        {
            SendCommand("F", textBox1.Text);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            SendCommand("B", textBox1.Text);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            SendCommand("R", textBox1.Text);
        }

        private void button4_Click(object sender, EventArgs e)
        {
            SendCommand("L", textBox1.Text);
        }

        private void SendCommand(string command, string duration)
        {
            string commandString = command + duration;
            serialPort11.WriteLine(commandString);
        }
        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }
        private void MainForm_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (serialPort11.IsOpen)
                serialPort11.Close();
        }
    }
}
