int number = 0;
int number2 = 0;
int res=0;

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(4);
}

void loop() {

}

void serialEvent(){
  if(number ==0){
  	number = Serial.parseInt();
    Serial.println(number);
  }
  else{
      number2 = Serial.parseInt();
      Serial.println(number2);
  	  res = number + number2;
      Serial.println(res);
      number = 0;
  }
}