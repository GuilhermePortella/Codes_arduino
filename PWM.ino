//Exemplo de uso do PWM nos modulos ESP32 - Fade no LED embutido na placa
//RoboCore Tecnologia - Abril/2018

int resolucao = 8; // 8 bits - pode ser alterada de 1 a 16 bits
int maxValorPWM = 255; // para resolucao de 8 bits, maximo valor = 255 (2^8 = 256) - alterar se resolucao for diferente de 8
int frequencia = 5000; // frequencia do PWM em Hz - pode ser alterada dependendo da resolucao
int canalDoPWM = 0; // pode utilizar mais de um canal, para mais de um pino, indo de 0 a 15

void setup() {

  ledcSetup(canalDoPWM, frequencia, resolucao);
  ledcAttachPin(2, canalDoPWM); // LED embutido na placa (pino 2)

}

void loop() {

  for (int i = 0; i <= maxValorPWM; i++) {  
    ledcWrite(canalDoPWM, i);
    delay(10);
  }

  for (int i = maxValorPWM; i >= 0; i--) {
    ledcWrite(canalDoPWM, i);
    delay(10);
  }

}