	🏍️ Localizador de Motos com IoT
LINK para o video https://youtu.be/2tJ4KAqsfMc.

Este projeto tem como objetivo facilitar a localização de motos no pátio da Motu, utilizando um dispositivo sonoro e visual baseado em ESP32. A proposta foi desenvolvida para a entrega da disciplina de Internet das Coisas (IoT).

📌 Motivação
Em pátios com grande volume de motos, a visualização direta nem sempre é possível, especialmente em horários de pico ou quando há aglomeração de veículos. Pensando nisso, criamos um sistema que auxilia os funcionários na localização rápida e precisa da moto no momento da retirada.

💡 Ideia Central
O sistema consiste em um dispositivo colocado na moto assim que ela chega no pátio, preso de forma simples (como um pano ao redor do guidão), contendo:

Buzzer (apito sonoro)

LEDs para sinalização visual

Conectividade com o sistema via rede local (Wi-Fi)

Quando o funcionário deseja localizar uma moto, ele seleciona o modelo ou IP no sistema web. O sistema então envia um comando para o dispositivo acionar os alertas sonoro e visual, tornando a moto facilmente identificável no pátio.

O som e a luz permanecerão ativos até que o funcionário confirme no sistema que a moto foi encontrada, interrompendo o sinal.

🧠 Funcionamento
A moto recebe o dispositivo assim que chega ao pátio.

O ESP32 se conecta à rede local e aguarda comandos HTTP.

O funcionário, via sistema web, envia um comando ligar.

O ESP32 ativa o buzzer e os LEDs.

Após localizar a moto, o funcionário envia um comando parar (ou usa um botão físico no dispositivo), encerrando o alerta.

🔧 Componentes Utilizados
ESP32

LEDs (1 ou mais)

Buzzer piezoelétrico

Botão (opcional para desligar o alarme manualmente)

Fonte de energia (bateria ou powerbank)

Material de fixação (pano ou suporte para o guidão)

📲 Integração com o Front-End
Interface web onde o funcionário pode:

Selecionar a moto (por modelo ou IP)

Enviar comando para iniciar a localização

Confirmar a localização para parar os alertas

🧪 Testes Realizados
Verificação do acionamento sonoro e visual ao receber o comando

Teste de comunicação via HTTP local com o IP do ESP32

Testes com diferentes distâncias e obstáculos no pátio

📝 Considerações Finais
Este sistema tem o objetivo de otimizar o tempo dos funcionários e reduzir erros na entrega das motos. É um projeto simples, funcional e de baixo custo, com potencial para expansão futura (uso de GPS, conexão com banco de dados, etc.), além de uma integração direta com o código de organização das motos que está sendo desenvolvido para as outras entregas.
