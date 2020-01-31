/*
  Para poner un módulo bluetooth HC05 en modo de comandos AT:
  - Si tiene botón: presionar el botón antes de alimentar el Arduino y después
  alimentarlo
  - Si no tiene botón, usar un cable para conectar el pin 8 al pin KEY
  (si el módulo no tiene un pin KEY, conectar el cable directo al 
  pin 34 de la PCB verde del bluetooth
  https://images-na.ssl-images-amazon.com/images/I/51E2toGv%2BLL.jpg )

  En cualquier caso el LED del bluetooth debe empezar a parpadear lentamente.
  
  Comandos AT:
  AT+NAME para solicitar el nombre del bluetooth
  AT+NAME=RobotistasMX para cambiar el nombre del bluetooth a "RobotistasMX"
  AT+PSWD para solicitar la contraseña del bluetooth
  AT+PSWD=3141 para cambiar la contraseña a 3141
  
  By Roy Molina / www.robotistas.mx
*/

#include <SoftwareSerial.h>

SoftwareSerial BT(9, 7); // RX | TX en este caso 9 va con TX del módulo y 7 con RX

void setup()
{ 
  pinMode(8, OUTPUT);
  digitalWrite (8, HIGH);    // Activar el pin KEY del módulo para forzarlo a entrar en modo AT
  Serial.begin(9600);     //Iniciar comunicación computadora-Arduino
  Serial.println("Ingresar comandos AT:");
  BT.begin(38400); //A veces es 38400, a veces 9600 (depende de la configuración que traiga el módulo)
}

void loop()
{
  //Envío de comandos AT
  if (BT.available())         //Lo que recibas desde la computadora
    Serial.write(BT.read());  //Léelo y mándalo al módulo 

  //Recibir la respuesta del Bluetooth
  if (Serial.available())     //Lo que recibas desde el módulo
    BT.write(Serial.read());  //Léelo y mándalo a la computadora
}
