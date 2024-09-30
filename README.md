# 🌡️ Sistema de Monitoramento de Temperatura e Umidade IoT

Este projeto monitora níveis de temperatura e umidade utilizando um Arduino Uno e um sensor DHT22. O sistema aciona alertas visuais por meio de LEDs e envia avisos críticos via mensagens de WhatsApp. Os dados também são visualizados em tempo real usando o Node-RED.

## 🛠️ Visão Geral do Projeto

Este sistema captura dados ambientais utilizando um sensor DHT22 e exibe as informações através de LEDs. Dependendo das leituras, o sistema indica o status como "OK", "Perigo" ou "Crítico". Os dados do sensor são enviados para um dashboard no Node-RED, onde atualizações em tempo real são exibidas em gráficos. Além disso, se limites críticos forem atingidos, uma mensagem é enviada via WhatsApp.

### Componentes Utilizados:
- **Arduino Uno**
- **Sensor de Temperatura e Umidade DHT22**
- **LEDs (Vermelho, Amarelo, Verde)**
- **Resistor de 10kΩ**
- **Dashboard Node-RED**
- **Integração com WhatsApp para alertas**

## 🏗️ Arquitetura do Projeto

### 1. Dispositivos IoT (Borda)
- **Arduino Uno**: Controlador principal, responsável por ler a temperatura e umidade do sensor DHT22 e enviar os dados através da conexão serial.
- **Sensor DHT22**: Mede tanto a temperatura quanto a umidade.
- **Indicadores de LED**:
  - Verde: Operação normal
  - Amarelo: Estado de alerta (alta/baixa umidade ou temperatura)
  - Vermelho: Estado crítico (temperatura e umidade fora dos limites seguros)

### 2. Back-end (Processamento de Dados e Comunicação)
- **Node-RED**: Gerencia o fluxo de dados, processa as informações e fornece uma interface para visualização. Também integra-se com a API do WhatsApp para enviar alertas quando uma condição crítica é detectada. A comunicação entre o Arduino e o Node-RED é feita através da porta serial, utilizando o nó `node-red-node-serialport`.

### 3. Front-end (Interface de Usuário)
- **Dashboard Node-RED**: Um painel visual exibe as leituras de temperatura e umidade em tempo real, além de disparar mensagens via WhatsApp.

## 📦 Instruções de Configuração

### 1. Configuração de Hardware:
- Conecte o sensor DHT22 ao pino 4 do Arduino.
- Conecte os LEDs aos pinos 11 (Vermelho), 12 (Amarelo) e 13 (Verde) com resistores adequados.
- Conecte o resistor de 10kΩ ao DHT22 como um pull-up.

### 2. Configuração de Software:

```bash
# Clone o repositório
git clone https://github.com/seu-usuario/seu-repositorio.git

# Abra o projeto no Arduino IDE e carregue o código

# Instalar dependências para o Node-RED
npm install node-red-dashboard
npm install node-red-node-serialport
npm install node-red-contrib-whatsapp-cmb
```

### 4. Integração com WhatsApp:
Para enviar alertas via WhatsApp, configure uma API apropriada (como Twilio) e integre as credenciais no Node-RED usando o nó `node-red-contrib-whatsapp-cmb`.

## ⚙️ Como Funciona

1. **Monitoramento de Temperatura e Umidade**:
   - O sensor DHT22 lê a temperatura e a umidade a cada 3 segundos.
   - O sistema indica o status com LEDs e exibe os dados no dashboard Node-RED.

2. **Alertas Visuais**:
   - LED Verde: Operação normal.
   - LED Amarelo: Alerta de perigo (temperatura/umidade fora dos limites).
   - LED Vermelho: Estado crítico (valores extremos de temperatura/umidade).

3. **Dashboard Node-RED**:
   - Exibe as leituras em gráficos.
   - Mostra o status atual do sistema ("OK", "Perigo", "Crítico").

4. **Alertas via WhatsApp**:
   - Quando o status é "Crítico", uma mensagem é enviada automaticamente para o número de WhatsApp configurado.

## 📋 Requisitos

### Hardware:
- Arduino Uno
- Sensor de Temperatura e Umidade DHT22
- 3 LEDs (Vermelho, Amarelo, Verde)
- Resistor de 10kΩ
- Breadboard e fios de conexão

### Software:
- Arduino IDE
- Node-RED com as dependências:
  - `node-red-dashboard`
  - `node-red-node-serialport`
  - `node-red-contrib-whatsapp-cmb`

## 🔧 Exemplo de Saída

```json
{
  "Temperatura": 32.5,
  "Umidade": 45.0,
  "Status": "OK"
}
```

## 📄 Licença

Este projeto é licenciado sob a [MIT License](LICENSE).

---

🎁 Sinta-se à vontade para contribuir com melhorias e novas funcionalidades! Se você encontrar algum problema ou tiver sugestões, fique à vontade para melhorar o projeto!

---

## ✒️ Autores

* **Luiz Felipe Coelho Ramos** - *RM:555074* - [Luiz0770](https://github.com/Luiz0770)
* **Fernando Gonzales Alexandre** - *RM:555045* - [Fernando1403](https://github.com/Fernando1403)
* **Lucas Catroppa Piratininga** - *RM:555450* - [Fernando1403](https://github.com/lucasdias0812)
* **Caio Bucciarelli** - *RM:554899* - [CaioBucciarelli](https://github.com/CaioBucciarelli)
* **Vitor Musolino Teixeira** - *RM:555012* - [Vitormusolino](https://github.com/vitormusolino)
