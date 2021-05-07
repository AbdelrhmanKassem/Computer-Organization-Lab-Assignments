const int ledPin = 13;

String str = "";
char ch;
int timeUnit = 1000;


void dot()
{
  Serial.print(".");
  digitalWrite(ledPin, HIGH);
  delay(timeUnit);
  digitalWrite(ledPin, LOW);
}

void dash()
{
  Serial.print("-");
  digitalWrite(ledPin, HIGH);
  delay(timeUnit * 3);
  digitalWrite(ledPin, LOW);
}

void a()
{
  dot();
  delay(timeUnit);
  dash();
}
void b()
{
  dash();
  delay(timeUnit);
  dot();
  delay(timeUnit);
  dot();
  delay(timeUnit);
  dot();
}
void c()
{
  dash();
  delay(timeUnit);
  dot();
  delay(timeUnit);
  dash();
  delay(timeUnit);
  dot();
}
void d()
{
  dash();
  delay(timeUnit);
  dot();
  delay(timeUnit);
  dot();
}
void e()
{
  dot();
}
void f()
{
  dot();
  delay(timeUnit);
  dot();
  delay(timeUnit);
  dash();
  delay(timeUnit);
  dot();
}
void g()
{
  dash();
  delay(timeUnit);
  dash();
  delay(timeUnit);
  dot();
}
void h()
{
  dot();
  delay(timeUnit);
  dot();
  delay(timeUnit);
  dot();
  delay(timeUnit);
  dot();
}
void i()
{
  dot();
  delay(timeUnit);
  dot();
}
void j()
{
  dot();
  delay(timeUnit);
  dash();
  delay(timeUnit);
  dash();
  delay(timeUnit);
  dash();
}
void k()
{
  dash();
  delay(timeUnit);
  dot();
  delay(timeUnit);
  dash();
}
void l()
{
  dot();
  delay(timeUnit);
  dash();
  delay(timeUnit);
  dot();
  delay(timeUnit);
  dot();
}
void m()
{
  dash();
  delay(timeUnit);
  dash();
}
void n()
{
  dash();
  delay(timeUnit);
  dot();
}
void o()
{
  dash();
  delay(timeUnit);
  dash();
  delay(timeUnit);
  dash();
}
void p()
{
  dot();
  delay(timeUnit);
  dash();
  delay(timeUnit);
  dash();
  delay(timeUnit);
  dot();
}
void q()
{
  dash();
  delay(timeUnit);
  dash();
  delay(timeUnit);
  dot();
  delay(timeUnit);
  dash();
}
void r()
{
  dot();
  delay(timeUnit);
  dash();
  delay(timeUnit);
  dot();
}
void s()
{
  dot();
  delay(timeUnit);
  dot();
  delay(timeUnit);
  dot();
}
void t()
{
  dash();
}
void u()
{
  dot();
  delay(timeUnit);
  dot();
  delay(timeUnit);
  dash();
}
void v()
{
  dot();
  delay(timeUnit);
  dot();
  delay(timeUnit);
  dot();
  delay(timeUnit);
  dash();
}
void w()
{
  dot();
  delay(timeUnit);
  dash();
  delay(timeUnit);
  dash();
}
void x()
{
  dash();
  delay(timeUnit);
  dot();
  delay(timeUnit);
  dot();
  delay(timeUnit);
  dash();
}
void y()
{
  dash();
  delay(timeUnit);
  dot();
  delay(timeUnit);
  dash();
  delay(timeUnit);
  dash();
}
void z()
{
  dash();
  delay(timeUnit);
  dash();
  delay(timeUnit);
  dot();
  delay(timeUnit);
  dot();
}
void one()
{
  dot();
  delay(timeUnit);
  dash();
  delay(timeUnit);
  dash();
  delay(timeUnit);
  dash();
  delay(timeUnit);
  dash();
}
void two()
{
  dot();
  delay(timeUnit);
  dot();
  delay(timeUnit);
  dash();
  delay(timeUnit);
  dash();
  delay(timeUnit);
  dash();
}
void three()
{
  dot();
  delay(timeUnit);
  dot();
  delay(timeUnit);
  dot();
  delay(timeUnit);
  dash();
  delay(timeUnit);
  dash();
}
void four()
{
  dot();
  delay(timeUnit);
  dot();
  delay(timeUnit);
  dot();
  delay(timeUnit);
  dot();
  delay(timeUnit);
  dash();
}
void five()
{
  dot();
  delay(timeUnit);
  dot();
  delay(timeUnit);
  dot();
  delay(timeUnit);
  dot();
  delay(timeUnit);
  dot();
}
void six()
{
  dash();
  delay(timeUnit);
  dot();
  delay(timeUnit);
  dot();
  delay(timeUnit);
  dot();
  delay(timeUnit);
  dot();
}
void seven()
{
  dash();
  delay(timeUnit);
  dash();
  delay(timeUnit);
  dot();
  delay(timeUnit);
  dot();
  delay(timeUnit);
  dot();
}
void eight()
{
  dash();
  delay(timeUnit);
  dash();
  delay(timeUnit);
  dash();
  delay(timeUnit);
  dot();
  delay(timeUnit);
  dot();
}
void nine()
{
  dash();
  delay(timeUnit);
  dash();
  delay(timeUnit);
  dash();
  delay(timeUnit);
  dash();
  delay(timeUnit);
  dot();
}
void zero()
{
  dash();
  delay(timeUnit);
  dash();
  delay(timeUnit);
  dash();
  delay(timeUnit);
  dash();
  delay(timeUnit);
  dash();
}
void morse()
{
  
  switch (ch){
    case 'a':
      a();
      Serial.print(" ");
  	  break;
  	case 'b':
      b();
      Serial.print(" ");
  	  break;
  	case 'c':
      c();
      Serial.print(" ");
  	  break;
  	case 'd':
      d();
      Serial.print(" ");
  	  break;
  	case 'e':
      e();
      Serial.print(" ");
  	  break;
  	case 'f':
      f();
      Serial.print(" ");
  	  break;
  	case 'g':
      g();
      Serial.print(" ");
  	  break;
  	case 'h':
      h();
      Serial.print(" ");
  	  break;
  	case 'i':
      i();
      Serial.print(" ");
  	  break;
  	case 'j':
      j();
      Serial.print(" ");
  	  break;
  	case 'k':
      k();
      Serial.print(" ");
  	  break;
  	case 'l':
      l();
      Serial.print(" ");
  	  break;
   	case 'm':
      m();
      Serial.print(" ");
  	  break;
    case 'n':
      n();
      Serial.print(" ");
  	  break;
  	case 'o':
      o();
      Serial.print(" ");
  	  break;
  	case 'p':
      p();
      Serial.print(" ");
  	  break;
   	case 'q':
      q();
      Serial.print(" ");
  	  break;
    case 'r':
      r();
      Serial.print(" ");
  	  break;
  	case 's':
      s();
      Serial.print(" ");
  	  break;
  	case 't':
      t();
      Serial.print(" ");
  	  break;
   	case 'u':
      u();
      Serial.print(" ");
  	  break;
    case 'v':
      v();
      Serial.print(" ");
  	  break;
    case 'w':
      w();
      Serial.print(" ");
  	  break;
  	case 'x':
      x();
      Serial.print(" ");
  	  break;
  	case 'y':
      y();
      Serial.print(" ");
  	  break;
   	case 'z':
      z();
      Serial.print(" ");
  	  break;
  
    case '0':
      zero();
      Serial.print(" ");
  	  break;
    case '1':
      one();
      Serial.print(" ");
  	  break;
  	case '2':
      two();
      Serial.print(" ");
  	  break;
  	case '3':
      three();
      Serial.print(" ");
  	  break;
   	case '4':
      four();
      Serial.print(" ");
  	  break;
    case '5':
      five();
      Serial.print(" ");
  	  break;
    case '6':
      six();
      Serial.print(" ");
  	  break;
  	case '7':
      seven();
      Serial.print(" ");
  	  break;
  	case '8':
      eight();
      Serial.print(" ");
  	  break;
   	case '9':
      nine();
      Serial.print(" ");
  	  break;
     case ' ':
      delay(timeUnit);
      Serial.print("+ ");
  	  break;
  	 default:
  	  Serial.println("Invalid Character!");
  	  break;
  }
}

void strToMorse()
{
  for (int i = 0; i < str.length(); i++)
  {
    str.toLowerCase();
    ch = str.charAt(i);
    morse();
    delay(timeUnit*3);
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  Serial.println("Enter a string: ");
}

void loop() {
  while (Serial.available())
  {
    str = Serial.readString();
    Serial.print(str + " = ");
    strToMorse();
    Serial.println();
  }
}