#include <Arduino.h>
//#include <string.h> // strlen, strcpy, strcat, strcmp, strchr
//

/*Autor: Davi Nogueira
Programa: Textos em C
Descrição: Principios sobre Strings
Data: 22/04/2026
Versão:1.0
*/

//\0 é um terminador
//String em estilo C
char primeiroNomeExplicito[5] = {'D','a','v','i','\0'};
char primeiroNomeImplicito[5] = {'D','a','v','i'};

//O terminador \0 esta implicito na String
String nomeCompleto = "Davi";

void setup() 
{
  Serial.begin(9600);
  Serial.println();//quebra do ruido

  //quando é uma concatenacao (nome tecnico para adicionar duas string)ira funcionar no setup, loop ou outras funcoes
  nomeCompleto = nomeCompleto + "Nogueira";

  // Serial.println(primeiroNomeExplicito);
  // Serial.println(primeiroNomeImplicito);
  // Serial.println(nomeCompleto);

  //A partir de uma string acesso um dos seus metodos para mostrar o comprimento da mesma
  int tamanhoDaPalavra = nomeCompleto.length();//Sizeof retornaria o tamanho de memoria ocupada
  //Serial.println(tamanhoDaPalavra);

  //charAt retorna o valor da posicao requerida
  char primeiraLetra = nomeCompleto.charAt(0);
  //Serial.println(primeiraLetra);

  //acessa atraves do colchetes a respectiva posicao da minha string
  //Serial.println(nomeCompleto[0]);

  String nomeCurso = "Desenvolvimento de Sistemas";

  //Serial.println(nomeCurso.indexOf("Sistemas"));
  // nomeCurso.replace("Sistemas", "Games");
  // Serial.println(nomeCurso);

  // transforma o texto em maiusculo
  //nomeCurso.toUpperCase();
  //Serial.println(nomeCurso);

  //Transforma o texto em minusculo
  // nomeCurso.toLowerCase();
  // Serial.println(nomeCurso);

  // String numeroEmString = "2026";
  // int numeroConvertido = numeroEmString.toInt(); //Converte String em int
  // Serial.println(numeroConvertido);

  String textoDigitado = "";

  // if (textoDigitado.length() == 0)
  // {
  //   Serial.println("Texto Vazio");
  // }
  // else
  // {
  //   Serial.println("Ha texto");
  // }

  //* -> indica ponteiro, ou seja, guarda o endereco de memoria de um valor fixo ou de uma variavel
  const char *conversaoStringEmC = nomeCompleto.c_str() ;
  //Serial.println(conversaoStringEmC);

  const char *cidade = "Sao Paulo";
  //Serial.println(cidade);

  //Retorna o tamanho da string em estilo C
  int tamanhoCidade = strlen(cidade);
  Serial.println(tamanhoCidade);
  
}

void loop() 
{


}