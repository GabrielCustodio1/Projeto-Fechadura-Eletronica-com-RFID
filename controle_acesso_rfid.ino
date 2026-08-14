#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <MFRC522.h>
#define SCREEN_WIDTH 128 // Largura do display OLED em pixels
#define SCREEN_HEIGHT 64 // Altura do display OLED em pixels
#define OLED_RESET 4 // Pino de reset do OLED
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire,
OLED_RESET);
#define RST_PIN 25 // Pino de reset do RFID
#define SS_PIN 26 // Pino SS do RFID
int LED_VERDE = 14;
int LED_VERMELHO = 13;
MFRC522 rfid(SS_PIN, RST_PIN); // Instância do objeto RFID
// UID autorizado (substitua pelos bytes do UID desejado)
byte UID_AUTORIZADO[] = {0xB1, 0xC9, 0x03, 0x1D};
void setup() {
pinMode(LED_VERDE, OUTPUT);
pinMode(LED_VERMELHO, OUTPUT);
Serial.begin(115200);
display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
display.display();
delay(2000);
SPI.begin(); // Inicializa o barramento SPI
rfid.PCD_Init(); // Inicializa o RFID
6
}
void loop() {
display.clearDisplay();
display.setTextSize(1);
display.setTextColor(SSD1306_WHITE);
display.setCursor(10, 20);
// Verifica se um cartão RFID está presente
if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
Serial.print("UID do Cartao: ");
bool acessoAutorizado = true;
for (byte i = 0; i < rfid.uid.size; i++) {
Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
Serial.print(rfid.uid.uidByte[i], HEX);
display.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
display.print(rfid.uid.uidByte[i], HEX);
// Compara o UID do cartão com o UID autorizado
if (rfid.uid.uidByte[i] != UID_AUTORIZADO[i]) {
acessoAutorizado = false;
}
}
Serial.println();
rfid.PICC_HaltA();
// Verifica se o acesso está autorizado
if (acessoAutorizado) {
display.clearDisplay();
display.setTextSize(1);
display.setTextColor(SSD1306_WHITE);
display.setCursor(10, 20);
display.print("Acesso Liberado, Bem Vindo SR.CARLOS");
digitalWrite(LED_VERDE, HIGH);
delay(1000);
digitalWrite(LED_VERDE, LOW);
} else {
display.clearDisplay();
display.setTextSize(1);
display.setTextColor(SSD1306_WHITE);
display.setCursor(10, 20);
display.print("Acesso Negado");
digitalWrite(LED_VERMELHO, HIGH);
delay(1000);
digitalWrite(LED_VERMELHO, LOW);
}
7
} else {
display.print("Aproxime o cartao");
}
display.display();
delay(2000);
}