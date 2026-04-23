#include <Arduino.h>
// #include <string.h> // strlen, strcpy, strcat, strcmp, strchr
//

/*Autor: Davi Nogueira
Programa: Textos em C
Descrição: Principios sobre Strings
Data: 22/04/2026
Versão:1.0
*/

//\0 é um terminador
// String em estilo C
char primeiroNomeExplicito[10] = {'O', 'L', 'A', ' ', 'M', 'U', 'N', 'D', 'O', '\0'};
char primeiroNomeImplicito[10] = {'O', 'L', 'A', ' ', 'M', 'U', 'N', 'D', 'O'};

// O terminador \0 esta implicito na String
String nomeCompleto = "Davi";

void setup()
{
  Serial.begin(9600);
  Serial.println(); // quebra do ruido

  // quando é uma concatenacao (nome tecnico para adicionar duas string)ira funcionar no setup, loop ou outras funcoes
  nomeCompleto = nomeCompleto + "Nogueira";

  // Serial.println(primeiroNomeExplicito);
  // Serial.println(primeiroNomeImplicito);
  // Serial.println(nomeCompleto);

  // A partir de uma string acesso um dos seus metodos para mostrar o comprimento da mesma
  int tamanhoDaPalavra = nomeCompleto.length(); // Sizeof retornaria o tamanho de memoria ocupada
  // Serial.println(tamanhoDaPalavra);

  // charAt retorna o valor da posicao requerida
  char primeiraLetra = nomeCompleto.charAt(0);
  // Serial.println(primeiraLetra);

  // acessa atraves do colchetes a respectiva posicao da minha string
  // Serial.println(nomeCompleto[0]);

  String nomeCurso = "Desenvolvimento de Sistemas";

  // Serial.println(nomeCurso.indexOf("Sistemas"));
  //  nomeCurso.replace("Sistemas", "Games");
  //  Serial.println(nomeCurso);

  // transforma o texto em maiusculo
  // nomeCurso.toUpperCase();
  // Serial.println(nomeCurso);

  // Transforma o texto em minusculo
  //  nomeCurso.toLowerCase();
  //  Serial.println(nomeCurso);

  // String numeroEmString = "2026";
  // int numeroConvertido = numeroEmString.toInt(); //Converte String em int
  // Serial.println(numeroConvertido);

  String textoDigitado = "";

  //  if (textoDigitado.length() == 0)
  // {
  //   Serial.println("Texto Vazio");
  // }
  // else
  // {
  //   Serial.println("Ha texto");
  // }

  // "*" -> indica ponteiro, ou seja, guarda o endereco de memoria de um valor fixo ou de uma variavel
  const char *conversaoStringEmC = nomeCompleto.c_str();
  // Serial.println(conversaoStringEmC);

  const char *cidade = "Sao Paulo";
  // Serial.println(cidade);

  // Retorna o tamanho da string em estilo C(QUANTAS LETRAS TEM)
  int tamanhoCidade = strlen(cidade);
  Serial.println(tamanhoCidade);

  //* PROFESSOR THIAGO
  // A funcao strcpy copia byte a byte a palavra, ou seja, nesse caso ficara "SENAI" com 10 de espaco e nao "OLA MUNDO" com 10 de espaco
  strcpy(primeiroNomeExplicito, "SENAI");

  Serial.println(primeiroNomeExplicito);

  // A funcao strcmp analiza a ordem lexica das palavras
  if (strcmp(primeiroNomeExplicito, "SENAI") == 0)
  {
    Serial.println("Sao iguais");
  }

  else if (strcmp(primeiroNomeExplicito, "SENAI") > 0)
  {
    Serial.println("A segunda palavra vem antes da primeira palavra em ordem lexica");
  }

  else // < 0
  {
    Serial.println("A primeira palavra vem antes da segunda palavra em ordem lexica");
  }

  if (strncmp(primeiroNomeImplicito, "OLA", 3) == 0)
  {
    Serial.println("As primeiras letras da palavra sao iguais");
  }

  if (strstr(primeiroNomeImplicito, "MUNDO")) // procurar string dentro da string
  {
    Serial.println("Palavra MUNDO detectada");
  }

  strchr(primeiroNomeImplicito, 'M');                 // retorna a posicao que se encontra a primeira ocorrencia do caracter
  Serial.println(strchr(primeiroNomeImplicito, 'M')); // MUNDO\0

  strcpy(primeiroNomeExplicito, "45");
  // palavra[0] - 48 * 10 + primeiroNomeExplicito[1] - 48
  int numeroRecebido = atoi(primeiroNomeExplicito); // ATOI = ASCII to INT
  Serial.println(numeroRecebido * 2);               // 90

  char fraseComposta[30];
  strcpy(fraseComposta, primeiroNomeImplicito);
  strcat(fraseComposta, primeiroNomeExplicito);
  Serial.println(fraseComposta); // OLA MUNDO 45

  //! ----------- STRING -----------------

  String palavra3 = "HOJE EH QUINTA"; // PALAVRA3 é um objeto, nao uma variavel
  Serial.println(palavra3.length());  // tamanho
  Serial.println(palavra3.charAt(8)); //"HOJE EH (Q)UINTA"

  Serial.println(palavra3.indexOf('Q'));     // 8 - primeira ocorrencia
  Serial.println(palavra3.substring(8, 14)); // QUINTA

  Serial.println(palavra3.indexOf('E'));     // 3
  Serial.println(palavra3.lastIndexOf('E')); // 5 - ultima ocorrencia

  if (palavra3.equals("HOJE EH SEXTA"))
  {
    Serial.println("Hoje é sexta!!!");
  }

  else
  {
    Serial.println("Errouuuuuuu, hj n é sexta");
  }

  if (palavra3.equalsIgnoreCase("Hoje eh quinta!"))
  {
    Serial.println("Sim, hoje eh quinta feira!");
  }

  if (palavra3.startsWith("HOJE")) // COMECA COM
  {
    Serial.println("A string comeca com HOJE");
  }

  if (palavra3.endsWith("INTA")) // TERMINA COM
  {
    Serial.println("A palavra termina com INTA");
  }

  String valor = "123kg";

  int valorNumerico = valor.toInt();
  Serial.println(valorNumerico * 10);

  palavra3.toLowerCase(); // tudo minusculo
  Serial.println(palavra3);

  palavra3.toUpperCase(); // TUDO MAIUSCULO
  Serial.println(palavra3);

  String textoLed = "Led = ON";
  textoLed.replace("ON", "OFF"); // mudando a palavra
  Serial.println(textoLed);

  String novaFrase = "texto    ";
  Serial.println(novaFrase);

  if (novaFrase.equals("texto"))
  {
    Serial.println("Sao iguais");
  }

  else
  {
    Serial.println("Nao sao iguais");
  }

  novaFrase.trim(); // Remove espacs e \n \r \t do fim do texto
  if (novaFrase.equals("texto"))
  {
    Serial.println("Sao iguais");
  }

  else
  {
    Serial.println("Nao sao iguais");
  }

  novaFrase.concat(" final");
  Serial.println(novaFrase);

  const char* vetorCaracteres = novaFrase.c_str();
  Serial.println("Oi");
}

void loop()
{
}