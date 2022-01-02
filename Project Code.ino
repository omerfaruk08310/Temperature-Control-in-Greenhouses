//LED'lerin bağlı olduğu pinler tanımlandı. 
#define LED1 7
#define LED2 6
#define LED3 5 

long analog;
float heat;
int velocity;
void setup()
{
  pinMode(11,OUTPUT);   // Fan pini çıkış olarak tanımlanır.
  pinMode(7,OUTPUT);  // 7,6 ve 5'de LED'ler bağlıdır. Çıkış olarak tanımlanırlar.
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
}
void loop()
{
  analog=analogRead(0);   // Sıcaklık sensörü okunur.
  heat=analog*0.488;       // Okunan sıcaklık bilgisine göre sıcaklık santigrat cinsinden hesaplanır.
  velocity=analog/4;          // Ortamın sıcaklık değerine göre motorun hızı hesaplanır.
  analogWrite(11,velocity);   // Motor hesaplanan hızda döndürülür. Sıcaklık arttıkça motorun dönüş hızı da artar.

    if(heat>22)    //Isı 22 santigrat dereceyi aşmışsa LED1 ışık verir.
  {
    digitalWrite(LED1,HIGH);
  }
   if(heat>24)     //Isı 24 santigrat dereceyi aşmışsa LED2 ışık verir.
  {
    digitalWrite(LED2,HIGH);
  }
     if(heat>26)   //Isı 26 santigrat dereceyi aşmışsa LED3 ışık verir.
  {
    digitalWrite(LED3,HIGH);
  }
      if(heat<22)    //Isı 22 santigrat derecenin altına düşmüşse LED1 söner.
  {
    digitalWrite(LED1,LOW);
  }
   if(heat<24)     //Isı 24 santigrat derecenin altına düşmüşse LED2 söner.
  {
    digitalWrite(LED2,LOW);
  }
     if(heat<26)   //Isı 26 santigrat derecenin altına düşmüşse LED3 söner.
  {
    digitalWrite(LED3,LOW);
  }
}
