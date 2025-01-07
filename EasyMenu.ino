#include <WiFi.h>
#include <WebServer.h>

// Configuração do Wi-Fi do ponto de acesso para clientes
const char* apSSID = "CafeCardapio";
const char* apPassword = "12345678";

// Configuração do Wi-Fi local para o dono
const char* ssid = "NOME_DA_REDE";
const char* password = "SENHA_DA_REDE";

// Servidor Web
WebServer server(80);

// Variáveis globais
String orders = "";  // Lista de pedidos
int orderCounter = 1;  // Contador de pedidos

// Função para servir a página do cliente
void handleClientPage() {
  String html = R"rawliteral(
    <html>
    <head>
      <meta charset="UTF-8">
      <title>Cardápio</title>
      <style>
        body { font-family: Arial, sans-serif; text-align: center; margin: 20px; }
        h1 { color: #5a5a5a; }
        .menu-item { display: inline-block; margin: 15px; text-align: center; }
        img { width: 150px; height: auto; border-radius: 10px; }
        button { margin-top: 10px; padding: 10px 20px; font-size: 16px; border: none; background-color: #007BFF; color: white; border-radius: 5px; }
        button:hover { background-color: #0056b3; }
      </style>
    </head>
    <body>
      <h1>Bem-vindo ao Cardápio</h1>
      <form action="/submitOrder" method="GET">
        <div class="menu-item">
          <img src="https://via.placeholder.com/150?text=Cappuccino" alt="Cappuccino">
          <p>Cappuccino - R$8.00</p>
          <button name="item" value="Cappuccino">Pedir</button>
        </div>
        <div class="menu-item">
          <img src="https://via.placeholder.com/150?text=Expresso" alt="Expresso">
          <p>Expresso - R$6.00</p>
          <button name="item" value="Expresso">Pedir</button>
        </div>
        <div class="menu-item">
          <img src="https://via.placeholder.com/150?text=Hamburger+Simples" alt="Hambúrguer Simples">
          <p>Hambúrguer Simples - R$12.00</p>
          <button name="item" value="Hambúrguer Simples">Pedir</button>
        </div>
        <div class="menu-item">
          <img src="https://via.placeholder.com/150?text=Hamburger+Duplo" alt="Hambúrguer Duplo">
          <p>Hambúrguer Duplo - R$15.00</p>
          <button name="item" value="Hambúrguer Duplo">Pedir</button>
        </div>
        <div class="menu-item">
          <img src="https://via.placeholder.com/150?text=Coca-Cola" alt="Refrigerante Coca-Cola">
          <p>Refrigerante Coca-Cola - R$5.00</p>
          <button name="item" value="Refrigerante Coca-Cola">Pedir</button>
        </div>
        <div class="menu-item">
          <img src="https://via.placeholder.com/150?text=Guarana" alt="Refrigerante Guaraná">
          <p>Refrigerante Guaraná - R$5.00</p>
          <button name="item" value="Refrigerante Guaraná">Pedir</button>
        </div>
      </form>
    </body>
    </html>
  )rawliteral";

  server.send(200, "text/html", html);
}

// Função para processar pedidos enviados pelo cliente
void handleOrderSubmission() {
  String item = server.arg("item");
  orders += String(orderCounter++) + ". " + item + 
            " <button onclick=\"location.href='/removeOrder?id=" + String(orderCounter - 1) + "'\">Atendido</button><br>";
  server.send(200, "text/html", "<h1>Pedido Enviado!</h1><p>Obrigado pelo seu pedido.</p>");
}

// Função para servir a página do dono
void handleOwnerPage() {
  String html = R"rawliteral(
    <html>
    <head>
      <meta charset="UTF-8">
      <title>Pedidos Recebidos</title>
      <style>
        body { font-family: Arial, sans-serif; margin: 20px; }
        h1 { color: #5a5a5a; }
        .order { margin: 10px 0; }
        button { padding: 5px 10px; background-color: #007BFF; color: white; border: none; border-radius: 5px; }
        button:hover { background-color: #0056b3; }
      </style>
      <script>
        setInterval(() => { location.reload(); }, 5000);
      </script>
    </head>
    <body>
      <h1>Pedidos Recebidos</h1>
  )rawliteral";

  html += orders.isEmpty() ? "<p>Sem pedidos no momento.</p>" : orders;
  html += "</body></html>";

  server.send(200, "text/html", html);
}

// Função para remover pedidos individuais
void handleRemoveOrder() {
  int id = server.arg("id").toInt();
  String orderId = String(id) + ".";
  int pos = orders.indexOf(orderId);
  if (pos >= 0) {
    int endPos = orders.indexOf("<br>", pos) + 4;
    orders.remove(pos, endPos - pos);
  }
  server.send(200, "text/html", "<h1>Pedido atendido!</h1><a href='/owner'>Voltar</a>");
}

void setup() {
  Serial.begin(115200);

  // Configuração do ponto de acesso
  WiFi.softAP(apSSID, apPassword);
  Serial.println("Ponto de acesso iniciado!");
  Serial.print("IP do cliente: ");
  Serial.println(WiFi.softAPIP());

  // Configuração do Wi-Fi local
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConectado ao Wi-Fi local!");
  Serial.print("IP do dono: ");
  Serial.println(WiFi.localIP());

  // Rotas do cliente
  server.on("/", handleClientPage);
  server.on("/submitOrder", handleOrderSubmission);

  // Rotas do dono
  server.on("/owner", handleOwnerPage);
  server.on("/removeOrder", handleRemoveOrder);

  // Inicializa o servidor
  server.begin();
  Serial.println("Servidor Web iniciado!");
}

void loop() {
  server.handleClient();
}