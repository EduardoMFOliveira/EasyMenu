# 🌟 EasyMenu 🌟

**Simplificando pedidos com tecnologia IoT**

## 📋 Sumário

- [Sobre o Projeto](#sobre-o-projeto)
- [🛠️ Configuração e Instalação](#️-configuração-e-instalação)
- [🚀 Funcionalidades](#-funcionalidades)
- [📚 Contribuindo](#-contribuindo)
- [📄 Licença](#-licença)

---

## Sobre o Projeto

O **EasyMenu** é um sistema interativo de cardápio baseado em IoT, projetado para facilitar pedidos e otimizar a comunicação entre clientes e preparadores. Ele utiliza o ESP32 como controlador principal, conectado à rede Wi-Fi para comunicação em tempo real.

---

## 🛠️ Configuração e Instalação

1. **Baixe a Arduino IDE**  
   Faça o download da IDE diretamente pelo site oficial:  
   [https://www.arduino.cc/en/software](https://www.arduino.cc/en/software)

2. **Instale as dependências do ESP32**  
   Siga o guia oficial para configurar o ESP32 na Arduino IDE:  
   [https://docs.espressif.com/projects/arduino-esp32/en/latest/installing.html#](https://docs.espressif.com/projects/arduino-esp32/en/latest/installing.html#)

3. **Baixe o arquivo do repositório**  
   Localize o arquivo `EasyMenu.ide` neste repositório e faça o download.

4. **Abra o código na Arduino IDE**  
   Execute o arquivo baixado. Ele será aberto automaticamente na Arduino IDE.

5. **Compile o código para o ESP32**  
   Conecte o ESP32 ao seu computador, selecione a porta correta na IDE e compile o código para carregar o sistema no dispositivo.

---

## 🚀 Funcionalidades

- Sistema interativo de pedidos em tempo real.
- Comunicação via Wi-Fi com o responsável pela preparação dos pedidos.
- Interface fácil de usar para o cliente.
- Suporte para múltiplos dispositivos conectados simultaneamente.

---

---

---

## 🌐 Acessando o Sistema EasyMenu

O sistema EasyMenu possui duas áreas principais: **Área dos Clientes** e **Área do Dono**. Veja abaixo como acessá-las:

---

### 👤 Área dos Clientes

1. **Conecte-se à Rede Wi-Fi Criada pelo ESP32**  
   No dispositivo do cliente (como um smartphone ou tablet), procure a rede criada pelo ESP32:  
   - **Nome da Rede (SSID):** `EasyMenu-Network`  
   - **Senha:** `easymenu123`

2. **Abra o Navegador**  
   Digite o seguinte endereço na barra de URL:  
   [http://192.168.4.1](http://192.168.4.1)

3. **Navegue pelo Cardápio**  
   Use a interface para selecionar itens do cardápio e confirmar o pedido.  
   - O pedido será enviado automaticamente para a **Área do Dono** para preparação.

---

### 🛠️ Área do Dono

1. **Conecte o ESP32 à Rede Wi-Fi Local**  
   Certifique-se de que o ESP32 está configurado para conectar-se à rede local (SSID e senha configurados no código antes de carregar no ESP32).  

2. **Acesse o Painel Administrativo**  
   No dispositivo do dono (como um computador ou smartphone conectado à mesma rede Wi-Fi local), abra um navegador web e digite o endereço IP do ESP32 na rede local.  

   - O IP será exibido no console da Arduino IDE ao carregar o código no ESP32.  Você também pode saber o IP consultando o roteador em que o ESP32 está conectado
     Exemplo: `http://192.168.1.100/admin`

4. **Gerencie o Sistema**  
   Na interface do dono, você pode:
   - Visualizar pedidos recebidos dos clientes.
   - Atualizar o cardápio e preços.
   - Configurar opções do sistema (ex.: alterar senha ou SSID da rede).

---

### 🔑 Notas de Configuração

- **Conexão do ESP32 à Rede Local:**  
  Para configurar o ESP32 com a rede local, atualize o código com o SSID e a senha antes de carregar o programa no dispositivo:  
  ```cpp
  const char* ssid = "SuaRedeWiFi";
  const char* password = "SenhaDaRede";


---

### Observações:
- Certifique-se de que todos os dispositivos usados (clientes e dono) estão conectados à mesma rede criada pelo ESP32 para garantir o funcionamento adequado.
- Caso o ESP32 esteja configurado para usar uma rede local existente, substitua o endereço IP padrão conforme indicado no código do projeto.

---

### Notas Adicionais:
- Se o ESP32 estiver configurado para se conectar a uma rede Wi-Fi existente, substitua o SSID e a senha pelos valores da sua rede local no código do projeto antes de carregar no dispositivo.
- Certifique-se de que o dispositivo utilizado (como smartphone ou laptop) esteja na mesma rede para acessar o painel.
- Tenha em mente que somente redes 2.4GHz são suportadas
