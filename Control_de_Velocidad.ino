#define MotorPUL 9
#define ButtonMax 8
#define ButtonMin 7

int MotorPOT=3;
int pot=A0;

int valor;
int PWM;
int val = 0;

void setup() {
  Serial.begin (9600);
  pinMode(MotorPUL,OUTPUT);
  pinMode(MotorPOT,OUTPUT);  
  pinMode(ButtonMax,INPUT);
  pinMode(ButtonMin,INPUT);
}

void loop() {
  
  valor=analogRead(pot);

  if (valor <= 1 && valor >= 0){   
    PWM = (valor, 0, 0, 0, 0);
    analogWrite(MotorPOT,PWM);
    //Serial.println("PWM al 0%");
  }

  if (valor <= 300 && valor >= 2){ 
     
    PWM = (valor, 2, 300, 0, 63);
    analogWrite(MotorPOT,PWM);
    Serial.println("PWM al 25% con potenciometro");
  }

  if (valor <= 700 && valor >= 301){ 
    PWM = (valor, 0, 700, 0, 127);
    analogWrite(MotorPOT,PWM);
    Serial.println("PWM al 50% con potenciometro");
  }
 
  if (valor <= 1023 && valor >= 701){ 
    PWM = (valor, 0, 1023, 0, 190);
    analogWrite(MotorPOT,PWM);
    Serial.println("PWM al 75% con potenciometro");
  }
  
    if(digitalRead(ButtonMax) == HIGH){   
    val = val+64;
    delay(250);
    if (val >192){
      val = 192;

    }
    analogWrite(MotorPUL, val);
    if (val == 64){
      Serial.println("PWM al 25% con pulsador");
      }
    if (val == 128){
      Serial.println("PWM al 50% con pulsador");
      }          
    if (val == 192){
      Serial.println("PWM al 75% con pulsador");
      }
  }
  
  if(digitalRead(ButtonMin) == HIGH){
    val = val-64;
    delay(250);
    if (val <0){
      val = 0; 
    }
    analogWrite(MotorPUL, val);
    if (val == 0){
      Serial.println("PWM al 0% con pulsador");
      }    
    if (val == 64){
      Serial.println("PWM al 25% con pulsador");
      }
    if (val == 128){
      Serial.println("PWM al 50% con pulsador");
      }          
    if (val == 192){
      Serial.println("PWM al 75% con pulsador");
      }    
  }
}
