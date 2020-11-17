using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GuessNum
{
    class guessNum
    {
        public int a;
        public int b;
        public int c;
        public int d;
        public String toString()
        {
            String result = String.Format(a.ToString()+b.ToString()+c.ToString()+d.ToString());
            return result;
        }
    }

}
