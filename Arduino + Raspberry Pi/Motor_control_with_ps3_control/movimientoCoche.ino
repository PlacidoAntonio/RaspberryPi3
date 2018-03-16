#include <SoftwareSerial.h>
SoftwareSerial BT(2, 3);

// Motor A
int ENA = 6;
int IN1 = 13;
int IN2 = 12;

// Motor B
int ENB = 5;
int IN3 = 11;
int IN4 = 10;

int vel = 255;

char lectura;
String comando="";

void setup()
{
  Serial.begin(9600) ;
  // Declaramos todos los pines como salidas
  pinMode (ENA, OUTPUT);
  pinMode (ENB, OUTPUT);
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);

  comando.reserve(50);
}

void loop(){
  
  if (Serial.available()){
    lectura = Serial.read();
    
    if (lectura==','){
       if(comando == "Adelante"){
        Adelante();
        comando = "";
       }else if(comando == "Izquierda"){
        Izquierda();
        comando = "";
       }else if(comando == "Derecha"){
        Derecha();
        comando = "";        
       }else if(comando == "Atras"){
        Atras();
        comando = "";        
       }else{
        Parar();
        comando = "";
       }
    }else{
      comando += lectura;
    }
  }

   
}

void Derecha ()
{
  //Direccion motor A
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  analogWrite (ENA, vel); //Velocidad motor A
  //Direccion motor B
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);
  analogWrite (ENB, vel); //Velocidad motor B
}

void Izquierda ()
{
  //Direccion motor A
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);
  analogWrite (ENA, vel);  //Velocidad motor A
  //Direccion motor B
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
  analogWrite (ENB, vel); //Velocidad motor B
}

void Atras ()
{
  //Direccion motor A
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  analogWrite (ENA, vel); //Velocidad motor A
  //Direccion motor B
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
  analogWrite (ENB, vel); //Velocidad motor A
}

void Adelante ()
{
  //Direccion motor A
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);
  analogWrite (ENA, vel); //Velocidad motor A
  //Direccion motor B
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);
  analogWrite (ENB, vel); //Velocidad motor A
}

void Parar ()
{
  //Direccion motor A
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, LOW);
  analogWrite (ENA, 0); //Velocidad motor A
  //Direccion motor B
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, LOW);
  analogWrite (ENB, 0); //Velocidad motor A
}


