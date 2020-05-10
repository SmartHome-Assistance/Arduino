String data="I am ready!";
bool led_3 = false;
bool led_4 = false;
bool led_5 = false;
int n = 0; 
String s = "";
String tmp = "";


void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  digitalWrite(3, HIGH);
  delay(200);
  digitalWrite(3, LOW);
  
  pinMode(4, OUTPUT);
  digitalWrite(4, HIGH);
  delay(200);
  digitalWrite(4, LOW);
  
  pinMode(5, OUTPUT);
  digitalWrite(5, HIGH);
  delay(200);
  digitalWrite(5, LOW);
  
  delay(200);

  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  delay(200);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
        
}

void led(String sl){
  if (sl == "3"){
      if (led_3 == false){
        digitalWrite(3, HIGH);
        led_3 = true;
        Serial.println("I'm turn ON 3 led");
      } else {
        digitalWrite(3, LOW);
        led_3 = false;
        Serial.println("I'm turn OFF 3 led");
      };
    };
    if (sl == "4"){
      if (led_4 == false){
        digitalWrite(4, HIGH);
        led_4 = true;
        Serial.println("I'm turn ON 4 led");
      } else {
        digitalWrite(4, LOW);
        led_4 = false;
        Serial.println("I'm turn OFF 4 led");
      };
    };
    if (sl == "5"){
      if (led_5 == false){
        digitalWrite(5, HIGH);
        led_5 = true;
        Serial.println("I'm turn ON 5 led");
      } else {
        digitalWrite(5, LOW);
        led_5 = false;
        Serial.println("I'm turn OFF 5 led");
      };
    };
    if (sl == "0"){
      if ((led_3 == true)|| (led_4 == true) || (led_5 == true)){
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
        led_3 = false;
        led_4 = false;
        led_5 = false;
        Serial.println("I'm turn OFF ALL led");
      } else {
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(5, HIGH);
        led_3 = true;
        led_4 = true;
        led_5 = true;
        Serial.println("I'm turn ON ALL led");
      };
    };
 }

void loop() {
  if (Serial.available() > 0) {
    s = Serial.read() - '0';
    data = "OK";
    //Serial.print(s + " " + data);
    led(s);
  };
  s = ""; 
  delay(200);
}
