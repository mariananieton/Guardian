# Guardian
Bem-vindo ao Guardian, parte integrante da nossa abordagem inovadora para apoiar as mamães durante a gravidez e o cuidado neonatal. Criamos para essa Global Solution o MãeConecta, que é um aplicativo acompanhado por um assistente virtual criado para oferecer
suporte abrangente a mamães durante e depois da gravidez. Ele fornece informações confiáveis, respostas a dúvidas comuns, lembretes importantes e recursos úteis para tornar a jornada da gravidez mais tranquila e informada e, agora, com a introdução do Guardian,
monitorar de forma precisa a temperatura e umidade de bebês nas incubadoras.

----------
### Sobre o Projeto


### Guardian
O Guardian é uma extensão essencial do MãeConecta, desenvolvida para monitorar o ambiente crítico das incubadoras de bebês. Com a utilização de tecnologia avançada, como o ESP32 e o sensor DHT22, o Guardian garante a precisão na medição
da temperatura e umidade, garantindo que os recém-nascidos estejam sempre em condições ideais para o seu desenvolvimento saudável.

- Recursos Principais:
   
  -	Monitoramento em Tempo Real: Através da integração com dispositivos como o ESP32 e o sensor DHT22, o Guardian oferece monitoramento contínuo e em tempo real da temperatura e umidade na incubadora.
  -	Dashboard: Nosso Dashboard oferece uma visão intuitiva e em tempo real das condições de umidade e temperatura nas incubadoras, proporcionando aos pais e profissionais de saúde uma ferramenta poderosa para monitorar e garantir o conforto ideal dos recém-nascidos.
  Com o Node-RED como gateway, cada mudança é capturada e apresentada de forma clara, permitindo uma resposta proativa para assegurar um ambiente seguro e saudável para os nossos pequeninos.

Desfrute do monitoramento contínuo e da tranquilidade de saber que as condições do ambiente da incubadora estão sendo cuidadosamente acompanhadas.

Obrigado por escolher o Guardian para garantir o melhor ambiente possível para os preciosos recém-nascidos nas incubadoras.

Juntos, criamos um ambiente mais seguro e saudável para os nossos pequeninos!

--------------

### Para testar a solução:

1.	Entre no Wokwi por este link para acessar o projeto já criado: [Guardian](https://wokwi.com/projects/382144577711663105)
2.	Caso não consiga acessar, baixe os códigos da pasta wokwi deste repositório, entre no Wokwi e crie um novo projeto com ESP32.
3.	Coloque a ESP32 no board e conecte um sensor DHT22 nela, utilizando a porta 15, o GND e o 5V.
4.	Na aba sketch.ino, coloque o código do arquivo guardian.cpp desse repositório
5.	Na aba diagram.json, coloque o código do arquivo diagram.json desse repositório
6.	Na aba libraries.txt, coloque o código do arquivo libraries.txt desse repositório
7.	Na aba Library Manager, adicione as seguintes bibliotecas: PubSubClient, DHT sensor library, DHT sensor library for ESPx
8.	No Node-RED, importe o arquivo flows.json que está na pasta node-red desse repositório
9.	Abra o dashboard pelo Node-RED para acompanhar as mudanças em tempo real
10.	Volte no Wokwi e clique em "Start the simulation". Pronto! Agora você pode ver o Guardian funcionando em tempo real!
