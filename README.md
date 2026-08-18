# Fechadura Eletrônica com RFID e ESP32

[![ESP32](https://img.shields.io/badge/ESP32-Microcontroller-E7352C?logo=espressif&logoColor=white)](https://www.espressif.com/en/products/socs/esp32)
[![Arduino](https://img.shields.io/badge/Arduino-IDE-00979D?logo=arduino&logoColor=white)](https://www.arduino.cc/en/software)
[![RFID](https://img.shields.io/badge/RFID-Access%20Control-6C3483)](https://en.wikipedia.org/wiki/Radio-frequency_identification)
[![C++](https://img.shields.io/badge/C%2B%2B-Embedded-00599C?logo=cplusplus&logoColor=white)](https://isocpp.org/)

Projeto de uma fechadura eletrônica com controle de acesso por RFID, desenvolvida com um microcontrolador ESP32.

O sistema lê o identificador de um cartão ou chaveiro RFID, compara o token recebido com os tokens autorizados e aciona o mecanismo de abertura quando o acesso é validado.

> Projeto desenvolvido para fins educacionais, com foco em sistemas embarcados, automação e controle de acesso.

## Sumário

- [Sobre o projeto](#sobre-o-projeto)
- [Problema e solução](#problema-e-solução)
- [Objetivos](#objetivos)
- [Como funciona](#como-funciona)
- [Componentes](#componentes)
- [Tecnologias e bibliotecas](#tecnologias-e-bibliotecas)
- [Circuito e conexões](#circuito-e-conexões)
- [Como executar](#como-executar)
- [Arquivos do projeto](#arquivos-do-projeto)
- [Demonstração](#demonstração)
- [Aprendizados](#aprendizados)
- [Limitações](#limitações)
- [Próximos passos](#próximos-passos)
- [Referências](#referências)
- [Autor](#autor)
- [Licença](#licença)

## Sobre o projeto

O acesso a ambientes restritos frequentemente depende de chaves, senhas ou cartões. Este projeto apresenta uma alternativa baseada em identificação por radiofrequência, utilizando cartões ou tags RFID como credenciais de acesso.

A solução foi construída com um ESP32, um leitor RFID e um mecanismo de acionamento para a fechadura. Quando uma tag é aproximada do leitor, o sistema identifica seu token e verifica se ele está autorizado.

Em caso de autorização, a fechadura é acionada. Caso contrário, o acesso permanece bloqueado.

## Problema e solução

### Problema

Sistemas baseados exclusivamente em chaves podem gerar dificuldades de gerenciamento, como perda, cópia ou necessidade de substituição física das chaves.

### Solução

A proposta é utilizar RFID para identificar usuários autorizados por meio de tokens associados a cartões ou chaveiros.

O sistema permite:

- Ler uma tag RFID.
- Identificar o token recebido.
- Comparar o token com uma lista de acessos autorizados.
- Acionar a fechadura quando o acesso for permitido.
- Bloquear o acesso quando o token não for reconhecido.

## Objetivos

- Desenvolver um protótipo de controle de acesso.
- Aplicar conceitos de sistemas embarcados.
- Integrar um ESP32 a um leitor RFID.
- Implementar validação de tokens.
- Controlar um mecanismo de fechadura eletrônica.
- Praticar programação em C++ para microcontroladores.
- Documentar o desenvolvimento de um projeto de automação.

## Como funciona

O funcionamento do sistema pode ser resumido nas seguintes etapas:

1. O ESP32 inicializa o leitor RFID.
2. O sistema aguarda a aproximação de um cartão ou chaveiro.
3. O leitor captura o identificador da tag.
4. O código compara o identificador com os tokens cadastrados.
5. Se o token for autorizado, o ESP32 aciona a fechadura.
6. Se o token não for autorizado, o acesso é negado.
7. O sistema retorna ao estado de espera para uma nova leitura.

Fluxo simplificado:

```text
Início
  |
Inicialização do ESP32 e leitor RFID
  |
Aguardar tag
  |
Ler token RFID
  |
Token autorizado?
  |              |
 Sim            Não
  |              |
Acionar       Negar acesso
fechadura         |
  |              |
Retornar ao estado de espera
```

## Componentes

A montagem pode utilizar os seguintes componentes:

- ESP32.
- Leitor RFID RC522 ou módulo compatível.
- Cartão ou chaveiro RFID.
- Fechadura elétrica ou solenoide.
- Módulo relé ou circuito de acionamento.
- Fonte de alimentação adequada.
- Protoboard.
- Jumpers.
- LEDs ou buzzer para indicação de status, se utilizados.

> Confira o relatório em PDF e o código-fonte para confirmar a lista exata de componentes e a tensão utilizada na montagem.

## Tecnologias e bibliotecas

- C++ para sistemas embarcados.
- Arduino IDE.
- ESP32.
- Comunicação SPI.
- Tecnologia RFID.
- Biblioteca MFRC522, caso utilizada pelo código.
- Controle digital de entrada e saída.
- Git e GitHub para versionamento.

O módulo MFRC522 é frequentemente utilizado com Arduino e ESP32 para comunicação com leitores RFID por meio da interface SPI [web:258][web:260].

## Circuito e conexões

O leitor RFID normalmente se comunica com o ESP32 por SPI. A ligação exata depende dos pinos definidos no código.

Antes de montar o circuito, confira:

- O modelo da placa ESP32.
- Os pinos SPI utilizados.
- Os pinos `SDA/SS` e `RST` do leitor.
- O pino responsável pelo acionamento da fechadura.
- A tensão de operação do módulo RFID.
- A necessidade de utilizar fonte externa para a fechadura.
- O isolamento elétrico entre o ESP32 e o atuador.

> Adicione nesta seção um diagrama do circuito quando ele estiver disponível.

Exemplo de espaço para o diagrama:

```markdown

```

## Como executar

### Pré-requisitos

- Arduino IDE instalada.
- Placa ESP32 configurada na Arduino IDE.
- Cabo USB para gravação.
- Leitor RFID conectado ao ESP32.
- Biblioteca necessária instalada.
- Circuito montado com alimentação adequada.

### Instalação da placa ESP32

1. Abra a Arduino IDE.
2. Acesse o gerenciador de placas.
3. Pesquise por `ESP32`.
4. Instale o pacote correspondente ao ESP32.
5. Selecione a placa correta no menu de dispositivos.

### Instalação da biblioteca RFID

Se o projeto utilizar a biblioteca MFRC522:

1. Abra a Arduino IDE.
2. Acesse `Sketch`.
3. Selecione `Incluir Biblioteca`.
4. Abra o `Gerenciador de Bibliotecas`.
5. Pesquise por `MFRC522`.
6. Instale a biblioteca compatível.

### Gravação do programa

1. Clone este repositório:

```bash
git clone https://github.com/GabrielCustodio1/Projeto-Fechadura-Eletronica-com-RFID.git
```

2. Abra o arquivo `.ino` correspondente na Arduino IDE.
3. Conecte o ESP32 ao computador.
4. Selecione a porta serial correta.
5. Selecione o modelo da placa.
6. Compile o programa.
7. Faça o upload para o ESP32.
8. Abra o Monitor Serial para acompanhar as leituras.

## Cadastro de tokens

Para autorizar uma tag, identifique o token exibido no Monitor Serial e cadastre-o conforme a estrutura utilizada no código.

Antes de utilizar o sistema, confirme:

- Qual variável armazena os tokens autorizados.
- Qual formato é utilizado para representar o identificador.
- Se o token foi digitado corretamente.
- Se todos os bytes do identificador foram considerados.
- Se a comparação diferencia letras maiúsculas e minúsculas, quando aplicável.

> Não compartilhe tokens reais de um sistema instalado em produção.

## Arquivos do projeto

```text
Projeto-Fechadura-Eletronica-com-RFID/
├── README.md
├── src/
│   └── controle_acesso_rfid.ino
│   └── main.ino
├── docs/
│   └── projeto-fechadura-rfid.pdf
```

### `main.ino`

Arquivo principal do programa ou uma implementação relacionada ao controle da fechadura.

### `controle_acesso_rfid.ino`

Código relacionado à leitura RFID e ao controle de acesso.

### Relatório em PDF

Documento com informações complementares sobre o projeto, desenvolvimento, componentes e funcionamento.

> Caso os dois arquivos `.ino` tenham funções semelhantes, documente no README qual deles deve ser aberto e carregado na placa.

## Demonstração

Adicione imagens ou um vídeo do protótipo funcionando:

```markdown

```

Ou:

```markdown
[Vídeo de demonstração](COLE_AQUI_O_LINK_DO_VIDEO)
```

Uma demonstração ideal deve mostrar:

1. Aproximação de um token autorizado.
2. Abertura da fechadura.
3. Aproximação de um token não autorizado.
4. Negação do acesso.
5. Mensagens exibidas no Monitor Serial.

## Aprendizados

O desenvolvimento deste projeto permitiu praticar:

- Programação para ESP32.
- Integração entre hardware e software.
- Comunicação SPI.
- Leitura de cartões RFID.
- Comparação de identificadores.
- Controle de atuadores.
- Organização de código para sistemas embarcados.
- Uso da Arduino IDE.
- Documentação técnica.
- Versionamento de projetos no GitHub.

## Limitações

Este projeto é um protótipo educacional e não deve ser considerado, sem testes adicionais, um sistema de segurança profissional.

Possíveis limitações:

- Tokens armazenados diretamente no código podem ser copiados.
- O código precisa ser atualizado para cadastrar ou remover acessos.
- A perda de uma tag pode exigir alteração manual da lista autorizada.
- A segurança depende da proteção física do ESP32 e do leitor.
- O acionamento da fechadura exige alimentação adequada.
- O projeto pode não possuir registro de tentativas de acesso.
- O sistema pode não contar com autenticação adicional.

## Próximos passos

- Criar cadastro de usuários sem alterar o firmware.
- Armazenar tokens na memória não volátil.
- Adicionar display para mensagens ao usuário.
- Incluir LEDs e buzzer para indicar o resultado da leitura.
- Registrar data e hora dos acessos.
- Adicionar conexão Wi-Fi.
- Criar uma API para gerenciamento de usuários.
- Integrar o projeto a um banco de dados.
- Implementar abertura remota com autenticação.
- Adicionar botão interno de saída.
- Criar uma caixa ou suporte para proteger os componentes.
- Elaborar um diagrama elétrico completo.
- Adicionar testes automatizados para as regras de autorização.

## Referências

- [Documentação do ESP32](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/)
- [Arduino IDE](https://www.arduino.cc/en/software)
- [Biblioteca MFRC522](https://github.com/miguelbalboa/rfid)
- [Projeto ESP32 com fechadura RFID](https://www.usinainfo.com.br/blog/projeto-esp32-fechadura-eletrica-com-rfid/)
- [Artigo da DIO sobre documentação de projetos no GitHub](https://web.dio.me/articles/seu-github-conta-uma-historia-ou-apenas-armazena-codigos-2e0b660d6e54?back=/home)

## Autor

Desenvolvido por **Gabriel Custódio** e **Matheus Rosa**.

- GitHub: [GabrielCustodio1](https://github.com/GabrielCustodio1)
- Repositório: [Projeto-Fechadura-Eletronica-com-RFID](https://github.com/GabrielCustodio1/Projeto-Fechadura-Eletronica-com-RFID)

## Licença

Este projeto foi desenvolvido para fins educacionais.

Caso o projeto seja distribuído ou utilizado em outro contexto, verifique as licenças das bibliotecas, componentes e materiais de terceiros utilizados.
