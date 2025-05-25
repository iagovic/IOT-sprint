#include <BluetoothSerial.h>
#include "esp_bt_device.h"
#include "esp_gap_bt_api.h"
 
BluetoothSerial SerialBT;
 
const int ledPin = 2;
const int buzzerPin = 4;
 
String areaMaisProxima = "Desconhecida";
int rssiMaisForte = -100;
 
void setup() {
  Serial.begin(115200);
  SerialBT.begin("MotoLocalizadora"); // Visível se quiser emparelhar
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
 
  Serial.println("Iniciando escaneamento...");
  esp_bt_gap_register_callback(btCallback);
  esp_bt_gap_start_discovery(ESP_BT_INQ_MODE_GENERAL_INQUIRY, 10, 0);
}
 
void loop() {
  Serial.println("Área mais próxima: " + areaMaisProxima);
 
  // Aciona LED e buzzer por 3s
  digitalWrite(ledPin, HIGH);
  digitalWrite(buzzerPin, HIGH);
  delay(3000);
  digitalWrite(ledPin, LOW);
  digitalWrite(buzzerPin, LOW);
 
  // Recomeça escaneamento após 10s
  delay(10000);
  rssiMaisForte = -100;
  areaMaisProxima = "Desconhecida";
  esp_bt_gap_start_discovery(ESP_BT_INQ_MODE_GENERAL_INQUIRY, 10, 0);
}
 
// Callback para escaneamento Bluetooth
void btCallback(esp_bt_gap_cb_event_t event, esp_bt_gap_cb_param_t *param) {
  if (event == ESP_BT_GAP_DISC_RES_EVT) {
    for (int i = 0; i < param->disc_res.num_prop; i++) {
      if (param->disc_res.prop[i].type == ESP_BT_GAP_DEV_PROP_RSSI) {
        int rssi = *(int8_t *)param->disc_res.prop[i].val;
 
        for (int j = 0; j < param->disc_res.num_prop; j++) {
          if (param->disc_res.prop[j].type == ESP_BT_GAP_DEV_PROP_EIR) {
            uint8_t *eir = (uint8_t *)param->disc_res.prop[j].val;
            char nome[50];
            if (esp_bt_gap_resolve_eir_data(eir, ESP_BT_EIR_TYPE_CMPL_LOCAL_NAME, (uint8_t *)nome, sizeof(nome))) {
              String nomeStr = String(nome);
              Serial.printf("Dispositivo %s com RSSI: %d\n", nomeStr.c_str(), rssi);
 
              // Se for um nome de área conhecida, considera o mais forte
              if ((nomeStr.startsWith("Area")) && (rssi > rssiMaisForte)) {
                rssiMaisForte = rssi;
                areaMaisProxima = nomeStr;
              }
            }
          }
        }
      }
    }
  }
}