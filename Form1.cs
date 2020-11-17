using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace GuessNum
{

    public partial class Form1 : Form
    {
        private List<guessNum> data;
        private List<guessNum> guessProcess;

        public Form1()
        {
            InitializeComponent();
            this.label1.Text = @"1、请从0~9中，选择不同的四个数，写在纸上（不要欺骗计算机哦~）！" + "\n" +
                @"2、计算机每次猜完之后，请点击判定按钮。A表示相同数的个数，B表示该位置数字正确的个数。以目标数1234和猜测数5624为例，判定2A1B。";
            this.label1.Visible = true;
            this.label2.Visible = false;
            this.button1.Visible = true;
            this.button2.Visible = false;
            this.button3.Visible = false;
            this.button4.Visible = false;
            this.button5.Visible = false;
            this.button6.Visible = false;
            this.button7.Visible = false;
            this.button8.Visible = false;
            this.button9.Visible = false;
            this.button10.Visible = false;
            this.button11.Visible = false;
            this.button12.Visible = false;
            this.button13.Visible = false;
            this.button14.Visible = false;
            this.button15.Visible = false;
            this.button16.Visible = false;
        }
        private void init() 
        {
            this.label1.Text = @"1、请从0~9中，选择不同的四个数，写在纸上（不要欺骗计算机哦~）！" + "\n" +
                @"2、计算机每次猜完之后，请点击判定按钮。A表示相同数的个数，B表示该位置数字正确的个数。以目标数1234和猜测数5624为例，判定2A1B。";
            this.label1.Visible = true;
            this.label2.Visible = false;
            this.button1.Visible = true;
            this.button2.Visible = false;
            this.button3.Visible = false;
            this.button4.Visible = false;
            this.button5.Visible = false;
            this.button6.Visible = false;
            this.button7.Visible = false;
            this.button8.Visible = false;
            this.button9.Visible = false;
            this.button10.Visible = false;
            this.button11.Visible = false;
            this.button12.Visible = false;
            this.button13.Visible = false;
            this.button14.Visible = false;
            this.button15.Visible = false;
            this.button16.Visible = false;
        }
        private void button1_Click(object sender, EventArgs e)
        {

            this.data = new List<guessNum>();
            this.guessProcess = new List<guessNum>();
            initData();
            this.label1.Visible = false;
            this.label2.Visible = true;
            guessNum item = data[0];
            guessProcess.Add(item);
            this.label2.Text = item.toString();
            this.button1.Visible = false;
            this.button2.Visible = true;
            this.button3.Visible = true;
            this.button4.Visible = true;
            this.button5.Visible = true;
            this.button6.Visible = true;
            this.button7.Visible = true;
            this.button8.Visible = true;
            this.button9.Visible = true;
            this.button10.Visible = true;
            this.button11.Visible = true;
            this.button12.Visible = true;
            this.button13.Visible = true;
            this.button14.Visible = true;
            this.button15.Visible = true;
            this.button16.Visible = true;
        }
        private void initData()
        {
            for (var i = 0; i < 10; i++)
            {
                for (var j = 0; j < 10; j++)
                {
                    if (j == i) continue;
                    for (var k = 0; k < 10; k++)
                    {
                        if (k == j || k == i) continue;
                        for (var l = 0; l < 10; l++)
                        {
                            if (l == k || l == j || l == i)
                                continue;
                            guessNum item = new guessNum();
                            item.a = i;
                            item.b = j;
                            item.c = k;
                            item.d = l;
                            this.data.Add(item);

                        }
                    }
                }
            }
        }
        private void cutData(int q, int p)
        {
            guessNum standand = data[0];
            for (int i = 0; i < data.Count; i++)
            {
                int numA = 0;
                int numB = 0;
                guessNum item = data[i];
                if (standand.a == item.a)
                    numB++;
                if (standand.b == item.b)
                    numB++;
                if (standand.c == item.c)
                    numB++;
                if (standand.d == item.d)
                    numB++;
                if (standand.a == item.a || standand.a == item.b || standand.a == item.c || standand.a == item.d)
                    numA++;
                if (standand.b == item.a || standand.b == item.b || standand.b == item.c || standand.b == item.d)
                    numA++;
                if (standand.c == item.a || standand.c == item.b || standand.c == item.c || standand.c == item.d)
                    numA++;
                if (standand.d == item.a || standand.d == item.b || standand.d == item.c || standand.d == item.d)
                    numA++;
                if (numA != q || numB != p)
                {
                    data.RemoveAt(i);
                    i--;
                }

            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.cutData(0,0);
            if (data.Count() == 0)
            {
                MessageBox.Show("您的判定有错误哦，我们需要重新开始！");
                init();
                return;
            }
            guessNum item = data[0];
            guessProcess.Add(item);
            this.label2.Text = item.toString();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            this.cutData(1, 0);
            if (data.Count() == 0)
            {
                MessageBox.Show("您的判定有错误哦，我们需要重新开始！");
                init();
                return;
            }
            guessNum item = data[0];
            guessProcess.Add(item);
            this.label2.Text = item.toString();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            this.cutData(1, 1);
            if (data.Count() == 0)
            {
                MessageBox.Show("您的判定有错误哦，我们需要重新开始！");
                init();
                return;
            }
            guessNum item = data[0];
            guessProcess.Add(item);
            this.label2.Text = item.toString();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            this.cutData(2, 0);
            if (data.Count() == 0)
            {
                MessageBox.Show("您的判定有错误哦，我们需要重新开始！");
                init();
                return;
            }
            guessNum item = data[0];
            guessProcess.Add(item);
            this.label2.Text = item.toString();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            this.cutData(2, 1);
            if (data.Count() == 0)
            {
                MessageBox.Show("您的判定有错误哦，我们需要重新开始！");
                init();
                return;
            }
            guessNum item = data[0];
            guessProcess.Add(item);
            this.label2.Text = item.toString();
        }

        private void button7_Click(object sender, EventArgs e)
        {
            this.cutData(2, 2);
            if (data.Count() == 0)
            {
                MessageBox.Show("您的判定有错误哦，我们需要重新开始！");
                init();
                return;
            }
            guessNum item = data[0];
            guessProcess.Add(item);
            this.label2.Text = item.toString();
        }

        private void button8_Click(object sender, EventArgs e)
        {
            this.cutData(3, 0);
            if (data.Count() == 0)
            {
                MessageBox.Show("您的判定有错误哦，我们需要重新开始！");
                init();
                return;
            }
            guessNum item = data[0];
            guessProcess.Add(item);
            this.label2.Text = item.toString();
        }

        private void button9_Click(object sender, EventArgs e)
        {
            this.cutData(3, 1);
            if (data.Count() == 0)
            {
                MessageBox.Show("您的判定有错误哦，我们需要重新开始！");
                init();
                return;
            }
            guessNum item = data[0];
            guessProcess.Add(item);
            this.label2.Text = item.toString();
        }

        private void button10_Click(object sender, EventArgs e)
        {
            this.cutData(3, 2);
            if (data.Count() == 0)
            {
                MessageBox.Show("您的判定有错误哦，我们需要重新开始！");
                init();
                return;
            }
            guessNum item = data[0];
            guessProcess.Add(item);
            this.label2.Text = item.toString();
        }

        private void button11_Click(object sender, EventArgs e)
        {
            this.cutData(3, 3);
            if (data.Count() == 0)
            {
                MessageBox.Show("您的判定有错误哦，我们需要重新开始！");
                init();
                return;
            }
            guessNum item = data[0];
            guessProcess.Add(item);
            this.label2.Text = item.toString();
        }

        private void button12_Click(object sender, EventArgs e)
        {
            this.cutData(4, 0);
            if (data.Count() == 0)
            {
                MessageBox.Show("您的判定有错误哦，我们需要重新开始！");
                init();
                return;
            }
            guessNum item = data[0];
            guessProcess.Add(item);
            this.label2.Text = item.toString();
        }

        private void button13_Click(object sender, EventArgs e)
        {
            this.cutData(4, 1);
            if (data.Count() == 0)
            {
                MessageBox.Show("您的判定有错误哦，我们需要重新开始！");
                init();
                return;
            }
            guessNum item = data[0];
            guessProcess.Add(item);
            this.label2.Text = item.toString();
        }

        private void button14_Click(object sender, EventArgs e)
        {
            this.cutData(4, 2);
            if (data.Count() == 0)
            {
                MessageBox.Show("您的判定有错误哦，我们需要重新开始！");
                init();
                return;
            }
            guessNum item = data[0];
            guessProcess.Add(item);
            this.label2.Text = item.toString();
        }

        private void button15_Click(object sender, EventArgs e)
        {
            this.cutData(4, 3);
            if (data.Count() == 0)
            {
                MessageBox.Show("您的判定有错误哦，我们需要重新开始！");
                init();
                return;
            }
            guessNum item = data[0];
            guessProcess.Add(item);
            this.label2.Text = item.toString();
        }

        private void button16_Click(object sender, EventArgs e)
        {
            guessNum item = data[0];
            guessProcess.Add(item);
            this.saveProcess();
            this.label1.Visible = true;
            this.label2.Visible = false;
            this.button1.Visible = true;
            this.button2.Visible = false;
            this.button3.Visible = false;
            this.button4.Visible = false;
            this.button5.Visible = false;
            this.button6.Visible = false;
            this.button7.Visible = false;
            this.button8.Visible = false;
            this.button9.Visible = false;
            this.button10.Visible = false;
            this.button11.Visible = false;
            this.button12.Visible = false;
            this.button13.Visible = false;
            this.button14.Visible = false;
            this.button15.Visible = false;
            this.button16.Visible = false;
        }

        private void saveProcess()
        {
            String fileName = @"result.txt";
            StreamWriter result = new StreamWriter(fileName, true, System.Text.Encoding.Default);
            String process="";
            for (int i = 0; i < guessProcess.Count; i++)
            {
                guessNum item = guessProcess[i];
                process += (item.toString() + "\t");
            }
           
            result.WriteLine(process);
            result.Close();
        }
    }
   
}

   