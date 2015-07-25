#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 1024

// Separar: separa datos del formulario

void separar(char *cadena, char *linea, char separador)
{
    int x, y;
    
    x = 0; y = 0;
    
    while ((linea[x]) && (linea[x] != separador))
    {
	cadena[x] = linea[x];
	x = x + 1;
    }
    cadena[x] = '\0';
    if (linea[x]) ++x;
    
    y = 0;
    
    while (linea[y] = linea[x])
    {
	linea[y] = linea[x];
	y++;
	x++;
    }

}

int main(void)
{
    char *lenstr;
    char inputBuffer[MAXLEN];
    int contentLength;
    int i;
    char x;
    char mensaje[80];
    char usuario[80];
    char clave[80];
    char shell[80];

    printf ("Content-type:text/html\n\n");
    printf("<html><TITLE>Response</TITLE>\n");
    printf("<body>\n");
    lenstr = getenv("CONTENT_LENGTH");
    //lenstr = (char *)getenv("CONTENT_LENGTH");
    if (lenstr!= NULL)
    {
	contentLength = atoi(lenstr);   
    }
    else contentLength = 0;

    printf("Content Length: %d", contentLength,"<br>");
    //if (contentLength > sizeof(inputBuffer)-1)
    //	contentLength = sizeof(inputBuffer)-1;

    i = 0;

    while (i < contentLength){

	x = fgetc(stdin);
	if (x==EOF) break;
	inputBuffer[i] = x;
	i++;
    }

    inputBuffer[i] = '\0';
    contentLength = i;

    printf("<br>Datos Formulario: %s\n", inputBuffer);
    printf("<br>Tamanio: %d\n",contentLength);

    separar(mensaje, inputBuffer, '=');
    separar(mensaje, inputBuffer, '&');
    separar(usuario, inputBuffer, '=');
    separar(usuario, inputBuffer, '&');
    separar(clave, inputBuffer, '=');
    separar(clave, inputBuffer, '&');
    separar(shell, inputBuffer, '=');
    separar(shell, inputBuffer, '&');


    printf("\n<p> Mensaje: %s",mensaje);
    printf("\n<p> Usuario: %s",usuario);
    printf("\n<p> Clave: %s",clave);
    printf("\n<p> Shell: %s",shell);
    printf("\n</body></html>");
    return 0;
}

