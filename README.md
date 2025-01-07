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

## 🌐 Acessando a Rede do EasyMenu

1. **Ligue o ESP32**  
   Certifique-se de que o dispositivo está devidamente alimentado e funcionando.

2. **Conecte-se à Rede Wi-Fi**  
   O ESP32 cria uma rede Wi-Fi para o projeto.  
   - **Nome da Rede (SSID):** `EasyMenu-Network`  
   - **Senha:** `easymenu123`

3. **Acesse o Painel Web**  
   Após se conectar à rede, abra um navegador e digite o seguinte endereço na barra de URL:  
   [http://192.168.4.1](http://192.168.4.1)  

4. **Navegue pelo Sistema**  
   No painel web, você pode:
   - Fazer pedidos interativos.
   - Gerenciar configurações do sistema (se permitido pelo administrador).

---

### Notas Adicionais:
- Se o ESP32 estiver configurado para se conectar a uma rede Wi-Fi existente, substitua o SSID e a senha pelos valores da sua rede local no código do projeto antes de carregar no dispositivo.
- Certifique-se de que o dispositivo utilizado (como smartphone ou laptop) esteja na mesma rede para acessar o painel.
- Tenha em mente que somente redes 2.4GHz são suportadas
